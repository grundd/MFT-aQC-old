//
// download file containing several output histograms
//


// -----------------------------------------------------------------
// all headers are defined here

// c++ headers
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// root headers
#include "TH1F.h"
#include "TFile.h"
#include "TLegend.h"
#include "TString.h"
#include <time.h>

void getTracksHistoRuns(string histName, vector<string> passlist, int runNumber1, int runNumber2);
void getClustersHistoRuns(string histName, vector<string> passlist, int runNumber1, int runNumber2);
void getTracksHistoTime(string histName, vector<string> passlist, time_t ts_start, time_t ts_end);
void getClustersHistoTime(string histName, vector<string> passlist, time_t ts_start, time_t ts_end);
void downloadTime(int option);
void downloadRuns(int option, int runNumber1, int runNumber2);
void getTracksHistoRunList(string histName, vector<string> passlist, vector<int> runNumbers);
void getClustersHistoRunList(string histName, vector<string> passlist, vector<int> runNumbers);
void downloadRunList(int option);
//
//------------------------------------------------------------------
//main program
void download(int choice, int option, int runNumber1, int runNumber2){
    if(choice==1){
        downloadRuns(option, runNumber1, runNumber2);
    }
    if(choice==2){
        downloadTime(option);
    }
    if(choice==3){
        downloadRunList(option);
    }
    return;
}

//
//------------------------------------------------------------------
//download list of runs (possible to do only 1 run)

void downloadRunList(int option){
    //create directories for different runs
    TFile *outputfileRuns = new TFile("DownloadRunList.root","RECREATE");
       outputfileRuns->cd();
       outputfileRuns->mkdir("mMFTClusterPatternIndex");
       outputfileRuns->mkdir("mMFTTrackTanl");
       outputfileRuns->mkdir("mMFTTrackROFSize");
       outputfileRuns->mkdir("mMFTTrackNumberOfClusters");
       outputfileRuns->mkdir("mMFTTrackPhi");
       outputfileRuns->mkdir("mMFTTrackEta");
       outputfileRuns->mkdir("mMFTClustersROFSize");
       outputfileRuns->mkdir("mMFTClusterSensorIndex");
       outputfileRuns->Close();
    
    TFile *outputfileRunsPass = new TFile("DownloadRunListPass.root","RECREATE");
       outputfileRunsPass->cd();
       outputfileRunsPass->mkdir("mMFTClusterPatternIndex");
       outputfileRunsPass->mkdir("mMFTTrackTanl");
       outputfileRunsPass->mkdir("mMFTTrackROFSize");
       outputfileRunsPass->mkdir("mMFTTrackNumberOfClusters");
       outputfileRunsPass->mkdir("mMFTTrackPhi");
       outputfileRunsPass->mkdir("mMFTTrackEta");
       outputfileRunsPass->mkdir("mMFTClustersROFSize");
       outputfileRunsPass->mkdir("mMFTClusterSensorIndex");
       outputfileRunsPass->Close();
    
    const int cinTerminator = 0;
    vector <int> runNumbers;
    int runNumber;
    cout << "Enter run numbers (0 is the last number ending the line):" << endl;
    while ((cin >> runNumber) && runNumber != cinTerminator) {
            runNumbers.push_back(runNumber);
        }
    
    int passchoice;
    cout << endl;
    cout << "Download according to pass?" << endl;
    cout << "1. Yes." << endl;
    cout << "2. No." << endl;
    cout << "Enter option number:";
    cin >> passchoice;
    
    string pass, S;
    vector<string> passlist;
    if(passchoice==1){
    cout << "Enter passes, each pass separated by space:" << endl;
    cin.ignore();
    getline(cin,S);
    stringstream X(S);
    while(getline(X, pass, ' ')){
        passlist.push_back(pass);}
        
    }

    if(option==1){
            getTracksHistoRunList("mMFTTrackTanl", passlist, runNumbers);
        }
    if(option==2){
            getTracksHistoRunList("mMFTTrackROFSize", passlist, runNumbers);
        }
    if(option==3){
            getTracksHistoRunList("mMFTTrackNumberOfClusters", passlist, runNumbers);
        }
    if(option==4){
            getTracksHistoRunList("mMFTTrackPhi", passlist, runNumbers);
        }
    if(option==5){
            getTracksHistoRunList("mMFTTrackEta", passlist, runNumbers);
        }
    if(option==6){
        getClustersHistoRunList("mMFTClusterPatternIndex", passlist, runNumbers);
    }
    if(option==7){
        getClustersHistoRunList("mMFTClustersROFSize", passlist, runNumbers);
    }
    if(option==8){
        getClustersHistoRunList("mMFTClusterSensorIndex", passlist, runNumbers);
        }
    if(option==9){
        getTracksHistoRunList("mMFTTrackTanl", passlist, runNumbers);
        getTracksHistoRunList("mMFTTrackROFSize", passlist, runNumbers);
        getTracksHistoRunList("mMFTTrackNumberOfClusters", passlist, runNumbers);
        getTracksHistoRunList("mMFTTrackPhi", passlist, runNumbers);
        getTracksHistoRunList("mMFTTrackEta", passlist, runNumbers);
        getClustersHistoRunList("mMFTClusterPatternIndex", passlist, runNumbers);
        getClustersHistoRunList("mMFTClustersROFSize", passlist, runNumbers);
        getClustersHistoRunList("mMFTClusterSensorIndex", passlist, runNumbers);
    }
    
}
//
//------------------------------------------------------------------
//download time interval

void downloadTime(int option)
{
        //cretae output files
        TFile *outputfile = new TFile("DownloadTime.root","RECREATE");
        outputfile->cd();
        outputfile->mkdir("mMFTClusterPatternIndex");
        outputfile->mkdir("mMFTTrackTanl");
        outputfile->mkdir("mMFTTrackROFSize");
        outputfile->mkdir("mMFTTrackNumberOfClusters");
        outputfile->mkdir("mMFTTrackPhi");
        outputfile->mkdir("mMFTTrackEta");
        outputfile->mkdir("mMFTClustersROFSize");
        outputfile->mkdir("mMFTClusterSensorIndex");
        outputfile->Close();
    
    TFile *outputfilePass = new TFile("DownloadTimePass.root","RECREATE");
    outputfilePass->cd();
    outputfilePass->mkdir("mMFTClusterPatternIndex");
    outputfilePass->mkdir("mMFTTrackTanl");
    outputfilePass->mkdir("mMFTTrackROFSize");
    outputfilePass->mkdir("mMFTTrackNumberOfClusters");
    outputfilePass->mkdir("mMFTTrackPhi");
    outputfilePass->mkdir("mMFTTrackEta");
    outputfilePass->mkdir("mMFTClustersROFSize");
    outputfilePass->mkdir("mMFTClusterSensorIndex");
    outputfilePass->Close();
    
    time_t ts_start=0, ts_end=0;
    vector<string> nums;
    struct tm datetime_start;
    struct tm datetime_end;
    string day, month, hour, min, sec;
    int year;
    cout<<"\n"<<"Time period [format (hour 24H): DD MM YYYY HH MM SS]"<<endl;
    cout<<"Enter start date and time: ";
    cin>> day >> month >> year >> hour >> min >> sec;
    string datetime1 = Form("%d%s%s_%s%s%s",year,month.c_str(),day.c_str(),hour.c_str(),min.c_str(),sec.c_str());
    datetime_start.tm_mday = stoi(day);
    datetime_start.tm_mon = stoi(month)-1;//-1 because january = 0;
    datetime_start.tm_year = year-1900;
    datetime_start.tm_hour = stoi(hour);
    datetime_start.tm_min = stoi(min);
    datetime_start.tm_sec = stoi(sec);
    datetime_start.tm_isdst = -1; //-1 means DST unknown
    ts_start = mktime(&datetime_start);//get timestamp start
    ts_start*=1000; //convert in milliseconds

    cout<<"Enter end date and time  : ";
    cin>> day >> month >> year >> hour >> min >> sec;
    string datetime2 = Form("%d%s%s_%s%s%s",year,month.c_str(),day.c_str(),hour.c_str(),min.c_str(),sec.c_str());
    datetime_end.tm_mday = stoi(day);
    datetime_end.tm_mon = stoi(month)-1;//-1 because january = 0;
    datetime_end.tm_year = year-1900;
    datetime_end.tm_hour = stoi(hour);
    datetime_end.tm_min = stoi(min);
    datetime_end.tm_sec = stoi(sec);
    datetime_end.tm_isdst = -1; //-1 means DST unknown
    ts_end = mktime(&datetime_end);//get timestamp start
    ts_end*=1000; //convert in milliseconds
    printf("Timestamp start (ms): %ld\n", (long) ts_start);
    printf("Timestamp end   (ms): %ld\n", (long) ts_end);
    nums.push_back(datetime1);
    nums.push_back(datetime2);
    
    int passchoice;
    cout << endl;
    cout << "Download according to pass?" << endl;
    cout << "1. Yes." << endl;
    cout << "2. No." << endl;
    cout << "Enter option number:";
    cin >> passchoice;
    
    string pass, S;
    vector<string> passlist;
    if(passchoice==1){
    cout << "Enter passes, each pass separated by space:" << endl;
    cin.ignore();
    getline(cin,S);
    stringstream X(S);
    while(getline(X, pass, ' ')){
        passlist.push_back(pass);}
        
    }
    
        if(option==1){
                getTracksHistoTime("mMFTTrackTanl", passlist, ts_start, ts_end);
            }
        if(option==2){
                getTracksHistoTime("mMFTTrackROFSize", passlist, ts_start, ts_end);
            }
        if(option==3){
                getTracksHistoTime("mMFTTrackNumberOfClusters", passlist, ts_start, ts_end);
            }
        if(option==4){
                getTracksHistoTime("mMFTTrackPhi", passlist, ts_start, ts_end);
            }
        if(option==5){
                getTracksHistoTime("mMFTTrackEta", passlist, ts_start, ts_end);
            }
        if(option==6){
            getClustersHistoTime("mMFTClusterPatternIndex", passlist, ts_start, ts_end);
        }
        if(option==7){
            getClustersHistoTime("mMFTClustersROFSize", passlist, ts_start, ts_end);
        }
        if(option==8){
            getClustersHistoTime("mMFTClusterSensorIndex", passlist, ts_start, ts_end);
        }
        if(option==9){
            getTracksHistoTime("mMFTTrackTanl", passlist, ts_start, ts_end);
            getTracksHistoTime("mMFTTrackROFSize", passlist, ts_start, ts_end);
            getTracksHistoTime("mMFTTrackNumberOfClusters", passlist, ts_start, ts_end);
            getTracksHistoTime("mMFTTrackPhi", passlist, ts_start, ts_end);
            getTracksHistoTime("mMFTTrackEta", passlist, ts_start, ts_end);
            getClustersHistoTime("mMFTClusterPatternIndex", passlist, ts_start, ts_end);
            getClustersHistoTime("mMFTClustersROFSize", passlist, ts_start, ts_end);
            getClustersHistoTime("mMFTClusterSensorIndex", passlist, ts_start, ts_end);
        }
}

//
//------------------------------------------------------------------
//download Run interval
void downloadRuns(int option, int runNumber1, int runNumber2)
{
        //create directories for different runs
        TFile *outputfileRuns = new TFile("DownloadRuns.root","RECREATE");
           outputfileRuns->cd();
           outputfileRuns->mkdir("mMFTClusterPatternIndex");
           outputfileRuns->mkdir("mMFTTrackTanl");
           outputfileRuns->mkdir("mMFTTrackROFSize");
           outputfileRuns->mkdir("mMFTTrackNumberOfClusters");
           outputfileRuns->mkdir("mMFTTrackPhi");
           outputfileRuns->mkdir("mMFTTrackEta");
           outputfileRuns->mkdir("mMFTClustersROFSize");
           outputfileRuns->mkdir("mMFTClusterSensorIndex");
           outputfileRuns->Close();
    
    TFile *outputfileRunsPass = new TFile("DownloadRunsPass.root","RECREATE");
       outputfileRunsPass->cd();
       outputfileRunsPass->mkdir("mMFTClusterPatternIndex");
       outputfileRunsPass->mkdir("mMFTTrackTanl");
       outputfileRunsPass->mkdir("mMFTTrackROFSize");
       outputfileRunsPass->mkdir("mMFTTrackNumberOfClusters");
       outputfileRunsPass->mkdir("mMFTTrackPhi");
       outputfileRunsPass->mkdir("mMFTTrackEta");
       outputfileRunsPass->mkdir("mMFTClustersROFSize");
       outputfileRunsPass->mkdir("mMFTClusterSensorIndex");
       outputfileRunsPass->Close();
    
    int passchoice;
    cout << endl;
    cout << "Download according to pass?" << endl;
    cout << "1. Yes." << endl;
    cout << "2. No." << endl;
    cout << "Enter option number:";
    cin >> passchoice;
    
    string pass, S;
    vector<string> passlist;
    if(passchoice==1){
    cout << "Enter passes, each pass separated by space:" << endl;
    cin.ignore();
    getline(cin,S);
    stringstream X(S);
    while(getline(X, pass, ' ')){
        passlist.push_back(pass);}
        
    }
        if(option==1){
                getTracksHistoRuns("mMFTTrackTanl", passlist, runNumber1, runNumber2);
            }
        if(option==2){
                getTracksHistoRuns("mMFTTrackROFSize", passlist, runNumber1, runNumber2);
            }
        if(option==3){
                getTracksHistoRuns("mMFTTrackNumberOfClusters", passlist, runNumber1, runNumber2);
            }
        if(option==4){
                getTracksHistoRuns("mMFTTrackPhi", passlist, runNumber1, runNumber2);
            }
        if(option==5){
                getTracksHistoRuns("mMFTTrackEta", passlist, runNumber1, runNumber2);
            }
        if(option==6){
            getClustersHistoRuns("mMFTClusterPatternIndex", passlist, runNumber1, runNumber2);
        }
        if(option==7){
            getClustersHistoRuns("mMFTClustersROFSize", passlist, runNumber1, runNumber2);
        }
        if(option==8){
            getClustersHistoRuns("mMFTClusterSensorIndex", passlist, runNumber1, runNumber2);
            }
        if(option==9){
            getTracksHistoRuns("mMFTTrackTanl", passlist, runNumber1, runNumber2);
            getTracksHistoRuns("mMFTTrackROFSize", passlist, runNumber1, runNumber2);
            getTracksHistoRuns("mMFTTrackNumberOfClusters", passlist, runNumber1, runNumber2);
            getTracksHistoRuns("mMFTTrackPhi", passlist, runNumber1, runNumber2);
            getTracksHistoRuns("mMFTTrackEta", passlist, runNumber1, runNumber2);
            getClustersHistoRuns("mMFTClusterPatternIndex", passlist, runNumber1, runNumber2);
            getClustersHistoRuns("mMFTClustersROFSize", passlist, runNumber1, runNumber2);
            getClustersHistoRuns("mMFTClusterSensorIndex", passlist, runNumber1, runNumber2);
        }
    
}


// -----------------------------------------------------------------
//get histograms for multiple runs

void getTracksHistoRuns(string histName, vector<string> passlist, int runNumber1, int runNumber2){

//get run list between run1 and run2
  long timestamp = -1;
  o2::ccdb::CcdbApi api;
  api.init("ali-qcdb-gpn.cern.ch:8083");
    
  map<string, string> metadata;
  vector<string>runlist;
    for (int i = runNumber1; i < (runNumber2 + 1); i++){
        runlist.push_back(to_string(i));
        
    }

    //string histName = "mMFTTrackTanl";
    string fixedPathPart = "/qc_async/MFT/MO/Tracks/tracks/";
    stringstream ss;
    ss << fixedPathPart << histName;
    string specificPath = ss.str();

    if(!passlist.empty()){
        for(int i = 0; i<runlist.size();i++){
            metadata["RunNumber"] = runlist[i];
            for(int j = 0; j<passlist.size();j++){
                metadata["PassName"] = passlist[j];
            TH1F* loadedHisto = api.retrieveFromTFileAny<TH1F>(specificPath.c_str(), metadata, timestamp);
            if(!loadedHisto)
            {
                cout << "Given Run Pass combination does not exist" << endl;
                continue;
            }
            
                TFile *outputfileRuns = new TFile("DownloadRunsPass.root","UPDATE");
                TH1F* h1 = dynamic_cast<TH1F*>(loadedHisto->Clone(Form("%s_%s",runlist[i].c_str(),passlist[j].c_str())));
                //h1->GetXaxis()->SetTitle(Form("Run %s",runlist[i].c_str()));
                outputfileRuns->cd();
                outputfileRuns->cd(histName.c_str());
                h1->Write();
                outputfileRuns->Close();
                
            }
        }
    }
    
    else{
    TFile *outputfileRuns = new TFile("DownloadRuns.root","UPDATE");
    
    for(int i = 0; i<runlist.size();i++){
        metadata["RunNumber"] = runlist[i];
        TH1F* loadedHisto = api.retrieveFromTFileAny<TH1F>(specificPath.c_str(), metadata, timestamp);
        if(!loadedHisto)
        {
            cout << "Given Run does not exist" << endl;
            continue;
            
        }
        else{
            TH1F* h1 = dynamic_cast<TH1F*>(loadedHisto->Clone(Form("%s",runlist[i].c_str())));
            //h1->GetXaxis()->SetTitle(Form("Run %s",runlist[i].c_str()));
            outputfileRuns->cd();
            outputfileRuns->cd(histName.c_str());
            h1->Write();
            }
        }
    outputfileRuns->Close();
    }
}

void getClustersHistoRuns(string histName, vector<string> passlist, int runNumber1, int runNumber2){
    //get run list between run1 and run2
      long timestamp = -1;
      o2::ccdb::CcdbApi api;
      api.init("ali-qcdb-gpn.cern.ch:8083");
        
      map<string, string> metadata;
      vector<string>runlist;
        for (int i = runNumber1; i < (runNumber2 + 1); i++){
            runlist.push_back(to_string(i));
            
        }

        //string histName = "mMFTTrackTanl";
        string fixedPathPart = "/qc_async/MFT/MO/Clusters/clusters/";
        stringstream ss;
        ss << fixedPathPart << histName;
        string specificPath = ss.str();
        
    if(!passlist.empty()){
            for(int i = 0; i<runlist.size();i++){
                metadata["RunNumber"] = runlist[i];
                for(int j = 0; j<passlist.size();j++){
                    metadata["PassName"] = passlist[j];
                TH1F* loadedHisto = api.retrieveFromTFileAny<TH1F>(specificPath.c_str(), metadata, timestamp);
                    if(!loadedHisto)
                    {
                        cout << "Given Run Pass combination does not exist" << endl;
                        continue;
                    }
                    TFile *outputfileRuns = new TFile("DownloadRunsPass.root","UPDATE");
                    TH1F* h1 = dynamic_cast<TH1F*>(loadedHisto->Clone(Form("%s_%s",runlist[i].c_str(),passlist[j].c_str())));
                    //h1->GetXaxis()->SetTitle(Form("Run %s",runlist[i].c_str()));
                    outputfileRuns->cd();
                    outputfileRuns->cd(histName.c_str());
                    h1->Write();
                    outputfileRuns->Close();
                
            }
            
            }
        }
        
        else{
        TFile *outputfileRuns = new TFile("DownloadRuns.root","UPDATE");
        
        for(int i = 0; i<runlist.size();i++){
            metadata["RunNumber"] = runlist[i];
            TH1F* loadedHisto = api.retrieveFromTFileAny<TH1F>(specificPath.c_str(), metadata, timestamp);
            if(loadedHisto)
            {
                TH1F* h1 = dynamic_cast<TH1F*>(loadedHisto->Clone(Form("%s",runlist[i].c_str())));
                //h1->GetXaxis()->SetTitle(Form("Run %s",runlist[i].c_str()));
                outputfileRuns->cd();
                outputfileRuns->cd(histName.c_str());
                h1->Write();
                
            }
            else{
                cout << "RunNumber" << runlist[i] << "does not exist" << endl;
                continue;
            }
        }
        outputfileRuns->Close();
        }

    }

// -----------------------------------------------------------------
//get histograms for multiple timestamps in UNIX format
void getTracksHistoTime(string histName, vector<string> passlist, time_t ts_start, time_t ts_end)
{
    
    o2::ccdb::CcdbApi api;
    api.init("ali-qcdb-gpn.cern.ch:8083");
    string fixedPathPart = "/qc_async/MFT/MO/Tracks/tracks/";
    stringstream tt;
    tt << fixedPathPart << histName;
    string specificPath = tt.str();
    string objectlist = api.list(specificPath.c_str(),false,"text/plain");
    
    stringstream ss(objectlist);
    string word;
    vector <string> timestamps, alltimestamps, runs;
    while(ss>>word){
      if(word=="Created:"){// take the one related to file creation
        ss>>word;
        alltimestamps.push_back(word);
      }
        if(word=="RunNumber"){
          ss>>word;
          ss>>word;
          if(word.size()==3) continue; //protection for fee task in particular: skip runs with 3 digits.
          runs.push_back(word);
          timestamps.push_back(alltimestamps[alltimestamps.size()-1]);//this keep only the timestamps connected to a run number
          //if(stoi(word)==stoi(run1)) break;
        }
    }

    //filter all the timestamps to get the ones within start and end dates (get most recent!!)
    vector <long int> timestamps_selperiod;
    vector <int> runs_selperiod;
    int counter=0;
    for(int its=0; its<(int)timestamps.size()-1; its++){
      if(stol(timestamps[its])>=ts_start && stol(timestamps[its])<=ts_end){
        counter++;
        if(counter==1) {
            if(its==0){
            runs_selperiod.push_back(std::stoi(runs[its]));
                timestamps_selperiod.push_back(stol(timestamps[its]));}//the first (most recent) is taken by definition if it is really the first in the list
          else{
              if(stol(timestamps[its-1])-stol(timestamps[its])>65000) timestamps_selperiod.push_back(stol(timestamps[its]));//if not the real first, check if it is the most recent (in this way the user can insert whatever date interval)
              runs_selperiod.push_back(std::stoi(runs[its]));}
        }
          if(stol(timestamps[its])-stol(timestamps[its+1])>65000){ timestamps_selperiod.push_back(stol(timestamps[its+1]));
          runs_selperiod.push_back(std::stoi(runs[its+1]));
          }
      }

      else if(stol(timestamps[its])>ts_end) continue;
      else break;
    }
    cout<<"\n"<<"Selected timestamps: "<<endl;
    for(int i=0; i<(int)timestamps_selperiod.size();i++){
      cout<<timestamps_selperiod[i]<<endl;
        cout<<runs_selperiod[i]<<endl;
    }
    
    map<string, string> metadata;
    
    if(!passlist.empty()){
    for(int i=0; i<(int)timestamps_selperiod.size();i++){
        long timestamp = timestamps_selperiod[i];
        int runNumber = runs_selperiod[i];
        for(int j = 0; j<passlist.size();j++){
            metadata["PassName"] = passlist[j];
        TH1F* loadedHisto = api.retrieveFromTFileAny<TH1F>(specificPath.c_str(), metadata, timestamp);
            
            if(!loadedHisto){
                cout << "Given Run Pass combination does not exist" << endl;
                continue;
            }
            
        
          //outputfile
             TFile *outputfile = new TFile("DownloadTimePass.root","UPDATE");
          //save histo
          TH1F* h1 = dynamic_cast<TH1F*>(loadedHisto->Clone(Form("%i_%s",runNumber,passlist[j].c_str())));
        outputfile->cd();
        outputfile->cd(histName.c_str());
          h1->Write();
          outputfile->Close();
            }
        }
    }
    else{
        for(int i=0; i<(int)timestamps_selperiod.size();i++){
            long timestamp = timestamps_selperiod[i];
            int runNumber = runs_selperiod[i];
            //map<string, string> metadata;
            TH1F* loadedHisto = api.retrieveFromTFileAny<TH1F>(specificPath.c_str(), metadata, timestamp);
            //cout <<  metadata["RunNumber"] << endl;
            if(!loadedHisto){
                cout << "Given object doesn't exist" << endl;
                continue;
            }
            
              //outputfile
                 TFile *outputfile = new TFile("DownloadTime.root","UPDATE");
              //save histo
              TH1F* h1 = dynamic_cast<TH1F*>(loadedHisto->Clone(to_string(runNumber).c_str()));
            outputfile->cd();
            outputfile->cd(histName.c_str());
              h1->Write();
              outputfile->Close();
        }
    }
}

void getClustersHistoTime(string histName, vector<string> passlist, time_t ts_start, time_t ts_end)
{
    o2::ccdb::CcdbApi api;
    api.init("ali-qcdb-gpn.cern.ch:8083");
    string fixedPathPart = "/qc_async/MFT/MO/Clusters/clusters/";
    stringstream tt;
    tt << fixedPathPart << histName;
    string specificPath = tt.str();
    string objectlist = api.list(specificPath.c_str(),false,"text/plain");
    
    stringstream ss(objectlist);
    string word;
    vector <string> timestamps, alltimestamps, runs;
    while(ss>>word){
      if(word=="Created:"){// take the one related to file creation
        ss>>word;
        alltimestamps.push_back(word);
      }
        if(word=="RunNumber"){
          ss>>word;
          ss>>word;
          if(word.size()==3) continue; //protection for fee task in particular: skip runs with 3 digits.
          runs.push_back(word);
          timestamps.push_back(alltimestamps[alltimestamps.size()-1]);//this keep only the timestamps connected to a run number
          //if(stoi(word)==stoi(run1)) break;
        }
    }

    //filter all the timestamps to get the ones within start and end dates (get most recent!!)
    vector <long int> timestamps_selperiod;
    vector <int> runs_selperiod;
    int counter=0;
    for(int its=0; its<(int)timestamps.size()-1; its++){
      if(stol(timestamps[its])>=ts_start && stol(timestamps[its])<=ts_end){
        counter++;
        if(counter==1) {
            if(its==0){
            runs_selperiod.push_back(std::stoi(runs[its]));
                timestamps_selperiod.push_back(stol(timestamps[its]));}//the first (most recent) is taken by definition if it is really the first in the list
          else{
              if(stol(timestamps[its-1])-stol(timestamps[its])>65000) timestamps_selperiod.push_back(stol(timestamps[its]));//if not the real first, check if it is the most recent (in this way the user can insert whatever date interval)
              runs_selperiod.push_back(std::stoi(runs[its]));}
        }
          if(stol(timestamps[its])-stol(timestamps[its+1])>65000){ timestamps_selperiod.push_back(stol(timestamps[its+1]));
          runs_selperiod.push_back(std::stoi(runs[its+1]));
          }
      }

      else if(stol(timestamps[its])>ts_end) continue;
      else break;
    }
    cout<<"\n"<<"Selected timestamps: "<<endl;
    for(int i=0; i<(int)timestamps_selperiod.size();i++){
      cout<<timestamps_selperiod[i]<<endl;
        cout<<runs_selperiod[i]<<endl;
    }
    
    map<string, string> metadata;
   // stringstream ss;
    
    if(!passlist.empty()){
    
    for(int i=0; i<(int)timestamps_selperiod.size();i++){
        long timestamp = timestamps_selperiod[i];
        int runNumber = runs_selperiod[i];
        for(int j = 0; j<passlist.size();j++){
            metadata["PassName"] = passlist[j];
        TH1F* loadedHisto = api.retrieveFromTFileAny<TH1F>(specificPath.c_str(), metadata, timestamp);
            
            if(!loadedHisto){
                cout << "Given Run Pass combination does not exist" << endl;
                continue;
            }
            
        
          //outputfile
             TFile *outputfile = new TFile("DownloadTimePass.root","UPDATE");
          //save histo
          TH1F* h1 = dynamic_cast<TH1F*>(loadedHisto->Clone(Form("%i_%s",runNumber,passlist[j].c_str())));
        outputfile->cd();
        outputfile->cd(histName.c_str());
          h1->Write();
          outputfile->Close();
            }
        }
    }
    else{
        for(int i=0; i<(int)timestamps_selperiod.size();i++){
            long timestamp = timestamps_selperiod[i];
            int runNumber = runs_selperiod[i];
            //map<string, string> metadata;
            TH1F* loadedHisto = api.retrieveFromTFileAny<TH1F>(specificPath.c_str(), metadata, timestamp);
            //cout <<  metadata["RunNumber"] << endl;
            if(!loadedHisto){
                cout << "Given object doesn't exist" << endl;
                continue;
            }
              //outputfile
                 TFile *outputfile = new TFile("DownloadTime.root","UPDATE");
              //save histo
              TH1F* h1 = dynamic_cast<TH1F*>(loadedHisto->Clone(to_string(runNumber).c_str()));
            outputfile->cd();
            outputfile->cd(histName.c_str());
              h1->Write();
              outputfile->Close();
        }
        
        
        
    }
}

void getClustersHistoRunList(string histName, vector<string> passlist, vector<int> runNumbers){
        
        if(!passlist.empty()){
        for(int i=0;i<(int)runNumbers.size();i++){
            long timestamp = -1;
            o2::ccdb::CcdbApi api;
            map<string, string> metadata;
            metadata["RunNumber"] = to_string(runNumbers[i]);
            for(int j = 0; j<passlist.size();j++){
                metadata["PassName"] = passlist[j];
            api.init("ali-qcdb-gpn.cern.ch:8083");
            string fixedPathPart = "/qc_async/MFT/MO/Clusters/clusters/";
            stringstream ss;
            ss << fixedPathPart << histName;
            string specificPath = ss.str();
            TH1F* loadedHisto = api.retrieveFromTFileAny<TH1F>(specificPath.c_str(), metadata, timestamp);
                if(!loadedHisto){
                    cout << "Given Run Pass combination does not exist" << endl;
                    continue;
                }
            
              //outputfile
                 TFile *outputfile = new TFile("DownloadRunListPass.root","UPDATE");
              //save histo
              TH1F* h1 = dynamic_cast<TH1F*>(loadedHisto->Clone(Form("%i_%s",runNumbers[i],passlist[j].c_str())));
              outputfile->cd();
              outputfile->cd(histName.c_str());
              h1->Write();
              outputfile->Close();
            }
        }
        }
        else{
                for(int i=0;i<(int)runNumbers.size();i++){
                    long timestamp = -1;
                    o2::ccdb::CcdbApi api;
                    map<string, string> metadata;
                    metadata["RunNumber"] = to_string(runNumbers[i]);
                    api.init("ali-qcdb-gpn.cern.ch:8083");
                    string fixedPathPart = "/qc_async/MFT/MO/Clusters/clusters/";
                    stringstream ss;
                    ss << fixedPathPart << histName;
                    string specificPath = ss.str();
                    TH1F* loadedHisto = api.retrieveFromTFileAny<TH1F>(specificPath.c_str(), metadata, timestamp);
                    
                    if(!loadedHisto){
                        cout << "Given Run Pass combination does not exist" << endl;
                        continue;
                    }
                    
                      //outputfile
                         TFile *outputfile = new TFile("DownloadRunList.root","UPDATE");
                      //save histo
                      TH1F* h1 = dynamic_cast<TH1F*>(loadedHisto->Clone(Form("%i",runNumbers[i])));
                      outputfile->cd();
                    outputfile->cd(histName.c_str());
                      h1->Write();
                      outputfile->Close();
                }
        }
    }


void getTracksHistoRunList(string histName, vector<string> passlist, vector<int> runNumbers){

    if(!passlist.empty()){
        
    for(int i=0;i<(int)runNumbers.size();i++){
        long timestamp = -1;
        o2::ccdb::CcdbApi api;
        map<string, string> metadata;
        metadata["RunNumber"] = to_string(runNumbers[i]);
        for(int j = 0; j<passlist.size();j++){
            metadata["PassName"] = passlist[j];
        api.init("ali-qcdb-gpn.cern.ch:8083");
        string fixedPathPart = "/qc_async/MFT/MO/Tracks/tracks/";
        stringstream ss;
        ss << fixedPathPart << histName;
        string specificPath = ss.str();
        TH1F* loadedHisto = api.retrieveFromTFileAny<TH1F>(specificPath.c_str(), metadata, timestamp);
            if(!loadedHisto){
                cout << "Given Run Pass combination does not exist" << endl;
                continue;
            }
        
          //outputfile
             TFile *outputfile = new TFile("DownloadRunListPass.root","UPDATE");
          //save histo
          TH1F* h1 = dynamic_cast<TH1F*>(loadedHisto->Clone(Form("%i_%s",runNumbers[i],passlist[j].c_str())));
          outputfile->cd();
          outputfile->cd(histName.c_str());
          h1->Write();
          outputfile->Close();
        }
    }
    }
    else{
            for(int i=0;i<(int)runNumbers.size();i++){
                long timestamp = -1;
                o2::ccdb::CcdbApi api;
                map<string, string> metadata;
                metadata["RunNumber"] = to_string(runNumbers[i]);
                api.init("ali-qcdb-gpn.cern.ch:8083");
                string fixedPathPart = "/qc_async/MFT/MO/Tracks/tracks/";
                stringstream ss;
                ss << fixedPathPart << histName;
                string specificPath = ss.str();
                TH1F* loadedHisto = api.retrieveFromTFileAny<TH1F>(specificPath.c_str(), metadata, timestamp);
                
                if(!loadedHisto){
                    cout << "Given Run does not exist" << endl;
                    continue;
                }
            
                
                  //outputfile
                     TFile *outputfile = new TFile("DownloadRunList.root","UPDATE");
                  //save histo
                  TH1F* h1 = dynamic_cast<TH1F*>(loadedHisto->Clone(Form("%i",runNumbers[i])));
                  outputfile->cd();
                outputfile->cd(histName.c_str());
                  h1->Write();
                  outputfile->Close();
            }
    }
        
}

