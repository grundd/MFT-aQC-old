// aQC.cxx
// David Grund, Jan 18, 2023
// MFT asynchronous Quality Control

// cpp
#include <vector>
#include <fstream>
// root
#include "TSystem.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"

bool rewriteAll = true;

vector<int>* ReadInput(string sIn, string &period, string &pass)
{
    std::vector<int>* runList = new std::vector<int>;
    ifstream ifs;
    ifs.open(sIn);
    ifs >> period;
    ifs >> pass;
    int nRuns;
    ifs >> nRuns;
    for(int i = 0; i < nRuns; i++) {
        int run;
        ifs >> run;
        runList->push_back(run);
    }
    cout << "Input:\n"
         << "period: " << period << "\n"
         << "pass:   " << pass << "\n"
         << "run list (" << nRuns << " runs):\n";
    for(int i = 0; i < nRuns; i++) cout << Form("%03i -> ",i+1) << runList->at(i) << "\n";
    return runList;
}

template <typename TH>
TH* LoadHisto(string path, string histName, int runNo, string pass)
{
    o2::ccdb::CcdbApi api;
    api.init("ali-qcdb-gpn.cern.ch:8083");
    map<string, string> metadata;
    metadata["RunNumber"] = std::to_string(runNo);
    metadata["PassName"] = pass;
    TH* h = api.retrieveFromTFileAny<TH>(path+histName,metadata,-1);
    if(h) return h;
    else  return NULL;
}

string RenameHisto(string oldName)
{
    string newName = oldName;
    std::replace(newName.begin(),newName.end(),'/','_'); // replace all 'x' to 'y'
    return newName;
}

void SaveHistos(string period, int runNo, string pass)
{
    gSystem->Exec(Form("mkdir -p Results/runsRootFiles/%s/",period.data()));
    // check if the file already exists
    string sFile = Form("Results/runsRootFiles/%s/%i_%s.root",period.data(),runNo,pass.data());
    bool fileExists = !gSystem->AccessPathName(sFile.data());
    if(fileExists && !rewriteAll) {
        cout << sFile << " already exists and won't be recreacted. Skipping...\n";
    } else {
        cout << sFile << " doesn't exist or will be recreated. Histograms will be loaded now:\n";
        TFile* f = new TFile(sFile.data(),"recreate");
        string sPath = "/qc_async/MFT/MO/Tracks/";
        string sNamesTH2[] = {
            // track position
            "tracks/mMFTTrackEtaPhi_5_MinClusters",
            "tracks/mMFTTrackXY_5_MinClusters",
            "tracks/mMFTTrackEtaPhi_7_MinClusters",
            "tracks/mMFTTrackXY_7_MinClusters",
            "tracks/mMFTTrackEtaPhi_8_MinClusters",
            "tracks/mMFTTrackXY_8_MinClusters"
        };
        string sNamesTH1[] = {
            // tracks
            "tracks/mMFTTrackEta",
            "tracks/mMFTTrackNumberOfClusters",
            "tracks/mMFTTrackPhi",
            "tracks/mMFTTrackTanl",
            "tracks/mNOfTracksTime",
            "tracks/mMFTTrackInvQPt",
            "tracks/CA/mMFTCATrackPt",
            "tracks/LTF/mMFTLTFTrackPt",
            "tracks/CA/mMFTCATrackEta",
            "tracks/LTF/mMFTLTFTrackEta",
            "tracks/mMFTTracksBC",
            // clusters
            "clusters/mMFTClusterPatternIndex",
            "clusters/mMFTClusterSensorIndex",
            "clusters/mMFTClustersROFSize",
            "clusters/mNOfClustersTime"
        };
        for(int i = 0; i < sizeof(sNamesTH2) / sizeof(sNamesTH2[0]); i++) {
            TH2F* h = LoadHisto<TH2F>(sPath,sNamesTH2[i],runNo,pass);
            if(h) {
                cout << "run " << runNo << ", " << pass << ": " << h->GetName() << " loaded\n";
                f->cd();
                h->Write(RenameHisto(h->GetName()).data());
            }
        }
        for(int i = 0; i < sizeof(sNamesTH1) / sizeof(sNamesTH1[0]); i++) {
            TH1F* h = LoadHisto<TH1F>(sPath,sNamesTH1[i],runNo,pass);
            if(h) {
                cout << "run " << runNo << ", " << pass << ": " << h->GetName() << " loaded\n";
                f->cd();
                h->Write(RenameHisto(h->GetName()).data());
            }
        }
        f->Write("",TObject::kWriteDelete);
        f->Close();
    }
    return;
}

void aQC(string sIn)
{
    string period;
    string pass;
    std::vector<int>* runList = ReadInput(sIn,period,pass);
    int nRuns = runList->size();
    for(int i = 0; i < nRuns; i++) SaveHistos(period.data(),runList->at(i),"apass1");
    for(int i = 0; i < nRuns; i++) SaveHistos(period.data(),runList->at(i),"apass2");
    return;
}