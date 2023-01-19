// aQC.cxx
// David Grund, Jan 18, 2023
// MFT asynchronous Quality Control

// cpp
#include <vector>
#include <fstream>
// root
#include "TSystem.h"
#include "TH1.h"
#include "TH2.h"

vector<int>* InputRuns(string sIn)
{
    std::vector<int>* runList = new std::vector<int>;
    ifstream ifs;
    ifs.open(sIn);
    int nRuns;
    ifs >> nRuns;
    for(int i = 0; i < nRuns; i++) {
        int run;
        ifs >> run;
        runList->push_back(run);
    }
    cout << "Input run list (" << nRuns << " runs):\n";
    for(int i = 0; i < nRuns; i++) cout << Form("%03i -> ",i+1) << runList->at(i) << "\n";
    return runList;
}

template <typename TH>
void LoadHisto(string path, string histName, int runNo, string pass)
{
    o2::ccdb::CcdbApi api;
    api.init("ali-qcdb-gpn.cern.ch:8083");
    map<string, string> metadata;
    metadata["RunNumber"] = std::to_string(runNo);
    metadata["PassName"] = pass;
    TH* loadedHisto = api.retrieveFromTFileAny<TH>(path+histName,metadata,-1);
    if(loadedHisto) loadedHisto->Draw();
    return;
}

void LoadHistos(int runNo)
{
    LoadHisto<TH1F>("/qc_async/MFT/MO/Tracks/tracks/","mMFTTrackEta",runNo,"apass1");
    
    return;
}

void aQC(string sIn)
{
    gSystem->Exec("mkdir -p Results/runsRootFiles/");
    std::vector<int>* runList = InputRuns(sIn);
    int nRuns = runList->size();
    for(int i = 0; i < nRuns; i++) LoadHistos(runList->at(i));
    
    return;
}