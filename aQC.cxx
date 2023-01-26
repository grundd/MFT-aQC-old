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

vector<int>* ReadInput(string sIn, string &period, string &pass1, string &pass2, string &type)
{
    std::vector<int>* runList = new std::vector<int>;
    ifstream ifs;
    ifs.open(sIn);
    int nRuns;
    ifs >> period
        >> pass1
        >> pass2
        >> type
        >> nRuns;
    for(int i = 0; i < nRuns; i++) {
        int run;
        ifs >> run;
        runList->push_back(run);
    }
    cout << "Input:\n"
         << "period: " << period << "\n"
         << "pass1:  " << pass1 << "\n"
         << "pass2:  " << pass2 << "\n"
         << "run list (" << nRuns << " runs):\n";
    for(int i = 0; i < nRuns; i++) cout << Form("%03i -> ",i+1) << runList->at(i) << "\n";
    return runList;
}

template <typename TH>
TH* LoadHisto(string path, string histName, int runNo, string pass)
{
    o2::ccdb::CcdbApi api;
    if(pass == "passMC") api.init("ccdb-test.cern.ch:8080");
    else                 api.init("ali-qcdb-gpn.cern.ch:8083");
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
    char slash = '/';
    size_t index = newName.find_last_of(slash);
    if (index < string::npos) {
        // erase everything up to 'index'
        newName.erase(0,index+1);
    }
    return newName;
}

void SaveHistos(string period, int runNo, string pass, bool isMC)
{
    gSystem->Exec(Form("mkdir -p Results/%s/runsRootFiles/",period.data()));
    // check if the file already exists
    string sFile = Form("Results/%s/runsRootFiles/%i_%s.root",period.data(),runNo,pass.data());
    bool fileExists = !gSystem->AccessPathName(sFile.data());
    if(fileExists && !rewriteAll) {
        cout << sFile << " already exists and won't be recreacted. Skipping...\n";
    } else {
        cout << sFile << " doesn't exist or will be recreated. Histograms will be loaded now:\n";
        TFile* f = new TFile(sFile.data(),"recreate");
        string sPath = "";
        if(isMC) sPath += "qc_mc/";
        else     sPath += "qc_async/";
        sPath += "MFT/MO/";
        std::vector<string> sNamesTH2 = {
            // track position
            "Tracks/tracks/mMFTTrackEtaPhi_5_MinClusters",
            "Tracks/tracks/mMFTTrackXY_5_MinClusters",
            "Tracks/tracks/mMFTTrackEtaPhi_7_MinClusters",
            "Tracks/tracks/mMFTTrackXY_7_MinClusters",
            "Tracks/tracks/mMFTTrackEtaPhi_8_MinClusters",
            "Tracks/tracks/mMFTTrackXY_8_MinClusters"
        };
        if(isMC) {
            sNamesTH2.push_back("Digits/mDigitOccupancySummary");
            sNamesTH2.push_back("Clusters/mClusterOccupancySummary");
        }
        std::vector<string> sNamesTH1 = {
            // tracks
            "Tracks/tracks/mMFTTrackEta",
            "Tracks/tracks/mMFTTrackNumberOfClusters",
            "Tracks/tracks/mMFTTrackPhi",
            "Tracks/tracks/mMFTTrackTanl",
            "Tracks/tracks/mNOfTracksTime",
            "Tracks/tracks/mMFTTrackInvQPt",
            "Tracks/tracks/CA/mMFTCATrackPt",
            "Tracks/tracks/LTF/mMFTLTFTrackPt",
            "Tracks/tracks/CA/mMFTCATrackEta",
            "Tracks/tracks/LTF/mMFTLTFTrackEta",
            "Tracks/tracks/mMFTTracksBC",
            // clusters
            "Tracks/clusters/mMFTClusterPatternIndex",
            "Tracks/clusters/mMFTClusterSensorIndex",
            "Tracks/clusters/mMFTClustersROFSize",
            "Tracks/clusters/mNOfClustersTime"
        };
        if(isMC) {
            sNamesTH1.push_back("Digits/mDigitChipOccupancy");
            sNamesTH1.push_back("Digits/mDigitsBC");
            sNamesTH1.push_back("Clusters/mClusterOccupancy");
            sNamesTH1.push_back("Clusters/mClusterSizeSummary");
            sNamesTH1.push_back("Clusters/mClusterZ");
            sNamesTH1.push_back("Clusters/mGroupedClusterSizeSummary");
        }
        for(int i = 0; i < sNamesTH2.size(); i++) {
            TH2F* h = LoadHisto<TH2F>(sPath,sNamesTH2[i],runNo,pass);
            if(h) {
                cout << "run " << runNo << ", " << pass << ": " << h->GetName() << " loaded\n";
                f->cd();
                h->Write(RenameHisto(h->GetName()).data());
            }
        }
        for(int i = 0; i < sNamesTH1.size(); i++) {
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
    string pass1;
    string pass2;
    string type;
    std::vector<int>* runList = ReadInput(sIn,period,pass1,pass2,type);
    bool isMC;
    if(type == "data") isMC = false;
    else if(type == "MC") isMC = true;
    int nRuns = runList->size();
    for(int i = 0; i < nRuns; i++) SaveHistos(period.data(),runList->at(i),pass1,isMC);
    if(pass2 != "none") 
        for(int i = 0; i < nRuns; i++) SaveHistos(period.data(),runList->at(i),pass2,isMC);
    return;
}