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
#include "TH1.h"
#include "TFile.h"
#include "TLegend.h"
#include "TDirectory.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TCollection.h"
#include "TKey.h"
#include "TRatioPlot.h"
#include "TLine.h"

void compareHisto(string histName, int plot, string run_1, string run_2);
void compareHistoRuns(string histName, int plot, string run_1, string run_2);
void compareHistoRunList(string histName, int plot, string run_1, string run_2);
void compareHistoRunListPass(string histName, int plot, string run_1, string run_2);
void compareHistoPass(string histName, int plot, string run_1, string run_2);
void compareHistoRunsPass(string histName, int plot, string run_1, string run_2);
void analysisRuns(int option);
void analysisTime(int option);
void analysisRunList(int option);
void DrawHistos(string histName, THStack *hStack,TFile *outputfile, TLegend *legend);
void DrawHistosRatio(string histName, THStack *hStack,TH1F *ratio,TLegend *legend,TFile *outputfile, string run_1, string run_2);
//
//------------------------------------------------------------------
//main program
void analysis(int choice, int option){
    if(choice==1){
        analysisRuns(option);
    }
    if(choice==2){
        analysisTime(option);
    }
    if(choice==3)
    {
        analysisRunList(option);
    }
    return;
}


void analysisTime(int option){
    int pass;
    cout << endl;
    cout << "Analyse data with given pass?" << endl;
    cout << "1. Yes, analyse previously downloaded passes." << endl;
    cout << "2. No, without chosen passes." << endl;
    cout << "Enter option number: ";
    cin >> pass;
    
    int plot;
    cout << endl;
    cout << "Do you want to create ratio plots?" << endl;
    cout << "1. Yes." << endl;
    cout << "2. No." << endl;
    cin >> plot;
    
    string run_1;
    string run_2;
    
    if(plot==1){
        cout << endl;
        cout << "Enter first run:" << endl;
        cin >> run_1;
        cout << "Enter second run:" << endl;
        cin >> run_2;
    }
    
    if(pass==1){
    TFile *outputfile = new TFile("AnalysisTimePass.root","RECREATE");
    outputfile->Close();
        if(option==1){
            if(plot==1){
                compareHistoPass("mMFTTrackTanl",1,run_1,run_2);
            }
            if(plot==2){
                compareHistoPass("mMFTTrackTanl",2,"0","0");
            }
    }
    if(option==2){
        if(plot==1){
            compareHistoPass("mMFTTrackROFSize",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoPass("mMFTTrackROFSize",2,"0","0");
        }
    }
    if(option==3){
        if(plot==1){
            compareHistoPass("mMFTTrackNumberOfClusters",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoPass("mMFTTrackNumberOfClusters",2,"0","0");
        }
    }
    if(option==4){
        if(plot==1){
            compareHistoPass("mMFTTrackPhi",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoPass("mMFTTrackPhi",2,"0","0");
        }
    }
    if(option==5){
        if(plot==1){
            compareHistoPass("mMFTTrackEta",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoPass("mMFTTrackEta",2,"0","0");
        }
    }
    if(option==6){
        if(plot==1){
            compareHistoPass("mMFTClusterPatternIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoPass("mMFTClusterPatternIndex",2,"0","0");
        }
    }
    if(option==7){
        if(plot==1){
            compareHistoPass("mMFTClustersROFSize",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoPass("mMFTClustersROFSize",2,"0","0");
        }
    }
    if(option==8){
        if(plot==1){
            compareHistoPass("mMFTClusterSensorIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoPass("mMFTClusterSensorIndex",2,"0","0");
        }
    }
    if(option==9){
        if(plot==1){
            compareHistoPass("mMFTTrackTanl",1,run_1,run_2);
            compareHistoPass("mMFTTrackPhi",1,run_1,run_2);
            compareHistoPass("mMFTTrackEta",1,run_1,run_2);
            compareHistoPass("mMFTTrackNumberOfClusters",1,run_1,run_2);
            compareHistoPass("mMFTTrackROFSize",1,run_1,run_2);
            compareHistoPass("mMFTClusterPatternIndex",1,run_1,run_2);
            compareHistoPass("mMFTClustersROFSize",1,run_1,run_2);
            compareHistoPass("mMFTClusterSensorIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoPass("mMFTTrackTanl",2,"0","0");
            compareHistoPass("mMFTTrackPhi",2,"0","0");
            compareHistoPass("mMFTTrackEta",2,"0","0");
            compareHistoPass("mMFTTrackNumberOfClusters",2,"0","0");
            compareHistoPass("mMFTTrackROFSize",2,"0","0");
            compareHistoPass("mMFTClusterPatternIndex",2,"0","0");
            compareHistoPass("mMFTClustersROFSize",2,"0","0");
            compareHistoPass("mMFTClusterSensorIndex",2,"0","0");
        }
    }
    }
    if(pass==2){
        TFile *outputfile = new TFile("AnalysisTime.root","RECREATE");
        outputfile->Close();
        if(option==1){
            if(plot==1){
                compareHisto("mMFTTrackTanl",1,run_1,run_2);
            }
            if(plot==2){
                compareHisto("mMFTTrackTanl",2,"0","0");
            }
    }
    if(option==2){
        if(plot==1){
            compareHisto("mMFTTrackROFSize",1,run_1,run_2);
        }
        if(plot==2){
            compareHisto("mMFTTrackROFSize",2,"0","0");
        }
    }
    if(option==3){
        if(plot==1){
            compareHisto("mMFTTrackNumberOfClusters",1,run_1,run_2);
        }
        if(plot==2){
            compareHisto("mMFTTrackNumberOfClusters",2,"0","0");
        }
    }
    if(option==4){
        if(plot==1){
            compareHisto("mMFTTrackPhi",1,run_1,run_2);
        }
        if(plot==2){
            compareHisto("mMFTTrackPhi",2,"0","0");
        }
    }
    if(option==5){
        if(plot==1){
            compareHisto("mMFTTrackEta",1,run_1,run_2);
        }
        if(plot==2){
            compareHisto("mMFTTrackEta",2,"0","0");
        }
    }
    if(option==6){
        if(plot==1){
            compareHisto("mMFTClusterPatternIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHisto("mMFTClusterPatternIndex",2,"0","0");
        }
    }
    if(option==7){
        if(plot==1){
            compareHisto("mMFTClustersROFSize",1,run_1,run_2);
        }
        if(plot==2){
            compareHisto("mMFTClustersROFSize",2,"0","0");
        }
    }
    if(option==8){
        if(plot==1){
            compareHisto("mMFTClusterSensorIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHisto("mMFTClusterSensorIndex",2,"0","0");
        }
    }
    if(option==9){
        if(plot==1){
            compareHisto("mMFTTrackTanl",1,run_1,run_2);
            compareHisto("mMFTTrackPhi",1,run_1,run_2);
            compareHisto("mMFTTrackEta",1,run_1,run_2);
            compareHisto("mMFTTrackNumberOfClusters",1,run_1,run_2);
            compareHisto("mMFTTrackROFSize",1,run_1,run_2);
            compareHisto("mMFTClusterPatternIndex",1,run_1,run_2);
            compareHisto("mMFTClustersROFSize",1,run_1,run_2);
            compareHisto("mMFTClusterSensorIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHisto("mMFTTrackTanl",2,"0","0");
            compareHisto("mMFTTrackPhi",2,"0","0");
            compareHisto("mMFTTrackEta",2,"0","0");
            compareHisto("mMFTTrackNumberOfClusters",2,"0","0");
            compareHisto("mMFTTrackROFSize",2,"0","0");
            compareHisto("mMFTClusterPatternIndex",2,"0","0");
            compareHisto("mMFTClustersROFSize",2,"0","0");
            compareHisto("mMFTClusterSensorIndex",2,"0","0");
        }
    }
    }
}




void analysisRuns(int option){
    
    int pass;
    cout << endl;
    cout << "Analyse data with given pass?" << endl;
    cout << "1. Yes, analyse previously downloaded passes." << endl;
    cout << "2. No, without chosen passes." << endl;
    cout << "Enter option number: ";
    cin >> pass;
    
    int plot;
    cout << endl;
    cout << "Do you want to create ratio plots?" << endl;
    cout << "1. Yes." << endl;
    cout << "2. No." << endl;
    cin >> plot;
    
    string run_1;
    string run_2;
    
    if(plot==1){
        cout << endl;
        cout << "Enter first run:" << endl;
        cin >> run_1;
        cout << "Enter second run:" << endl;
        cin >> run_2;
    }
    
    if(pass==1){
    TFile *outputfile = new TFile("AnalysisRunsPass.root","RECREATE");
    outputfile->Close();
        if(option==1){
            if(plot==1){
                compareHistoRunsPass("mMFTTrackTanl",1,run_1,run_2);
            }
            if(plot==2){
                compareHistoRunsPass("mMFTTrackTanl",2,"0","0");
            }
    }
    if(option==2){
        if(plot==1){
            compareHistoRunsPass("mMFTTrackROFSize",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunsPass("mMFTTrackROFSize",2,"0","0");
        }
    }
    if(option==3){
        if(plot==1){
            compareHistoRunsPass("mMFTTrackNumberOfClusters",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunsPass("mMFTTrackNumberOfClusters",2,"0","0");
        }
    }
    if(option==4){
        if(plot==1){
            compareHistoRunsPass("mMFTTrackPhi",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunsPass("mMFTTrackPhi",2,"0","0");
        }
    }
    if(option==5){
        if(plot==1){
            compareHistoRunsPass("mMFTTrackEta",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunsPass("mMFTTrackEta",2,"0","0");
        }
    }
    if(option==6){
        if(plot==1){
            compareHistoRunsPass("mMFTClusterPatternIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunsPass("mMFTClusterPatternIndex",2,"0","0");
        }
    }
    if(option==7){
        if(plot==1){
            compareHistoRunsPass("mMFTClustersROFSize",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunsPass("mMFTClustersROFSize",2,"0","0");
        }
    }
    if(option==8){
        if(plot==1){
            compareHistoRunsPass("mMFTClusterSensorIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunsPass("mMFTClusterSensorIndex",2,"0","0");
        }
    }
    if(option==9){
        if(plot==1){
            compareHistoRunsPass("mMFTTrackTanl",1,run_1,run_2);
            compareHistoRunsPass("mMFTTrackPhi",1,run_1,run_2);
            compareHistoRunsPass("mMFTTrackEta",1,run_1,run_2);
            compareHistoRunsPass("mMFTTrackNumberOfClusters",1,run_1,run_2);
            compareHistoRunsPass("mMFTTrackROFSize",1,run_1,run_2);
            compareHistoRunsPass("mMFTClusterPatternIndex",1,run_1,run_2);
            compareHistoRunsPass("mMFTClustersROFSize",1,run_1,run_2);
            compareHistoRunsPass("mMFTClusterSensorIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunsPass("mMFTTrackTanl",2,"0","0");
            compareHistoRunsPass("mMFTTrackPhi",2,"0","0");
            compareHistoRunsPass("mMFTTrackEta",2,"0","0");
            compareHistoRunsPass("mMFTTrackNumberOfClusters",2,"0","0");
            compareHistoRunsPass("mMFTTrackROFSize",2,"0","0");
            compareHistoRunsPass("mMFTClusterPatternIndex",2,"0","0");
            compareHistoRunsPass("mMFTClustersROFSize",2,"0","0");
            compareHistoRunsPass("mMFTClusterSensorIndex",2,"0","0");
        }
    }
    }
    if(pass==2){
        TFile *outputfile = new TFile("AnalysisRuns.root","RECREATE");
        outputfile->Close();
        if(option==1){
            if(plot==1){
                compareHistoRuns("mMFTTrackTanl",1,run_1,run_2);
            }
            if(plot==2){
                compareHistoRuns("mMFTTrackTanl",2,"0","0");
            }
    }
    if(option==2){
        if(plot==1){
            compareHistoRuns("mMFTTrackROFSize",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRuns("mMFTTrackROFSize",2,"0","0");
        }
    }
    if(option==3){
        if(plot==1){
            compareHistoRuns("mMFTTrackNumberOfClusters",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRuns("mMFTTrackNumberOfClusters",2,"0","0");
        }
    }
    if(option==4){
        if(plot==1){
            compareHistoRuns("mMFTTrackPhi",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRuns("mMFTTrackPhi",2,"0","0");
        }
    }
    if(option==5){
        if(plot==1){
            compareHistoRuns("mMFTTrackEta",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRuns("mMFTTrackEta",2,"0","0");
        }
    }
    if(option==6){
        if(plot==1){
            compareHistoRuns("mMFTClusterPatternIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRuns("mMFTClusterPatternIndex",2,"0","0");
        }
    }
    if(option==7){
        if(plot==1){
            compareHistoRuns("mMFTClustersROFSize",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRuns("mMFTClustersROFSize",2,"0","0");
        }
    }
    if(option==8){
        if(plot==1){
            compareHistoRuns("mMFTClusterSensorIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRuns("mMFTClusterSensorIndex",2,"0","0");
        }
    }
    if(option==9){
        if(plot==1){
            compareHistoRuns("mMFTTrackTanl",1,run_1,run_2);
            compareHistoRuns("mMFTTrackPhi",1,run_1,run_2);
            compareHistoRuns("mMFTTrackEta",1,run_1,run_2);
            compareHistoRuns("mMFTTrackNumberOfClusters",1,run_1,run_2);
            compareHistoRuns("mMFTTrackROFSize",1,run_1,run_2);
            compareHistoRuns("mMFTClusterPatternIndex",1,run_1,run_2);
            compareHistoRuns("mMFTClustersROFSize",1,run_1,run_2);
            compareHistoRuns("mMFTClusterSensorIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRuns("mMFTTrackTanl",2,"0","0");
            compareHistoRuns("mMFTTrackPhi",2,"0","0");
            compareHistoRuns("mMFTTrackEta",2,"0","0");
            compareHistoRuns("mMFTTrackNumberOfClusters",2,"0","0");
            compareHistoRuns("mMFTTrackROFSize",2,"0","0");
            compareHistoRuns("mMFTClusterPatternIndex",2,"0","0");
            compareHistoRuns("mMFTClustersROFSize",2,"0","0");
            compareHistoRuns("mMFTClusterSensorIndex",2,"0","0");
        }
    }
    }
}

void analysisRunList(int option){
    
    int pass;
    cout << endl;
    cout << "Analyse data with given pass?" << endl;
    cout << "1. Yes, analyse previously downloaded passes." << endl;
    cout << "2. No, without chosen passes." << endl;
    cout << "Enter option number: ";
    cin >> pass;
    
    
    int plot;
    cout << endl;
    cout << "Do you want to create ratio plots?" << endl;
    cout << "1. Yes." << endl;
    cout << "2. No." << endl;
    cin >> plot;
    
    string run_1;
    string run_2;
    
    if(plot==1){
        cout << endl;
        cout << "Enter first run:" << endl;
        cin >> run_1;
        cout << "Enter second run:" << endl;
        cin >> run_2;
    }
    
    if(pass==1){
    TFile *outputfile = new TFile("AnalysisRunListPass.root","RECREATE");
    outputfile->Close();
        if(option==1){
            if(plot==1){
                compareHistoRunListPass("mMFTTrackTanl",1,run_1,run_2);
            }
            if(plot==2){
                compareHistoRunListPass("mMFTTrackTanl",2,"0","0");
            }
    }
    if(option==2){
        if(plot==1){
            compareHistoRunListPass("mMFTTrackROFSize",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunListPass("mMFTTrackROFSize",2,"0","0");
        }
    }
    if(option==3){
        if(plot==1){
            compareHistoRunListPass("mMFTTrackNumberOfClusters",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunListPass("mMFTTrackNumberOfClusters",2,"0","0");
        }
    }
    if(option==4){
        if(plot==1){
            compareHistoRunListPass("mMFTTrackPhi",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunListPass("mMFTTrackPhi",2,"0","0");
        }
    }
    if(option==5){
        if(plot==1){
            compareHistoRunListPass("mMFTTrackEta",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunListPass("mMFTTrackEta",2,"0","0");
        }
    }
    if(option==6){
        if(plot==1){
            compareHistoRunListPass("mMFTClusterPatternIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunListPass("mMFTClusterPatternIndex",2,"0","0");
        }
    }
    if(option==7){
        if(plot==1){
            compareHistoRunListPass("mMFTClustersROFSize",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunListPass("mMFTClustersROFSize",2,"0","0");
        }
    }
    if(option==8){
        if(plot==1){
            compareHistoRunListPass("mMFTClusterSensorIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunListPass("mMFTClusterSensorIndex",2,"0","0");
        }
    }
    if(option==9){
        if(plot==1){
            compareHistoRunListPass("mMFTTrackTanl",1,run_1,run_2);
            compareHistoRunListPass("mMFTTrackPhi",1,run_1,run_2);
            compareHistoRunListPass("mMFTTrackEta",1,run_1,run_2);
            compareHistoRunListPass("mMFTTrackNumberOfClusters",1,run_1,run_2);
            compareHistoRunListPass("mMFTTrackROFSize",1,run_1,run_2);
            compareHistoRunListPass("mMFTClusterPatternIndex",1,run_1,run_2);
            compareHistoRunListPass("mMFTClustersROFSize",1,run_1,run_2);
            compareHistoRunListPass("mMFTClusterSensorIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunListPass("mMFTTrackTanl",2,"0","0");
            compareHistoRunListPass("mMFTTrackPhi",2,"0","0");
            compareHistoRunListPass("mMFTTrackEta",2,"0","0");
            compareHistoRunListPass("mMFTTrackNumberOfClusters",2,"0","0");
            compareHistoRunListPass("mMFTTrackROFSize",2,"0","0");
            compareHistoRunListPass("mMFTClusterPatternIndex",2,"0","0");
            compareHistoRunListPass("mMFTClustersROFSize",2,"0","0");
            compareHistoRunListPass("mMFTClusterSensorIndex",2,"0","0");
        }
    }
    }
    if(pass==2){
        TFile *outputfile = new TFile("AnalysisRunList.root","RECREATE");
        outputfile->Close();
        if(option==1){
            if(plot==1){
                compareHistoRunList("mMFTTrackTanl",1,run_1,run_2);
            }
            if(plot==2){
                compareHistoRunList("mMFTTrackTanl",2,"0","0");
            }
    }
    if(option==2){
        if(plot==1){
            compareHistoRunList("mMFTTrackROFSize",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunList("mMFTTrackROFSize",2,"0","0");
        }
    }
    if(option==3){
        if(plot==1){
            compareHistoRunList("mMFTTrackNumberOfClusters",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunList("mMFTTrackNumberOfClusters",2,"0","0");
        }
    }
    if(option==4){
        if(plot==1){
            compareHistoRunList("mMFTTrackPhi",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunList("mMFTTrackPhi",2,"0","0");
        }
    }
    if(option==5){
        if(plot==1){
            compareHistoRunList("mMFTTrackEta",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunList("mMFTTrackEta",2,"0","0");
        }
    }
    if(option==6){
        if(plot==1){
            compareHistoRunList("mMFTClusterPatternIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunList("mMFTClusterPatternIndex",2,"0","0");
        }
    }
    if(option==7){
        if(plot==1){
            compareHistoRunList("mMFTClustersROFSize",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunList("mMFTClustersROFSize",2,"0","0");
        }
    }
    if(option==8){
        if(plot==1){
            compareHistoRunList("mMFTClusterSensorIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunList("mMFTClusterSensorIndex",2,"0","0");
        }
    }
    if(option==9){
        if(plot==1){
            compareHistoRunList("mMFTTrackTanl",1,run_1,run_2);
            compareHistoRunList("mMFTTrackPhi",1,run_1,run_2);
            compareHistoRunList("mMFTTrackEta",1,run_1,run_2);
            compareHistoRunList("mMFTTrackNumberOfClusters",1,run_1,run_2);
            compareHistoRunList("mMFTTrackROFSize",1,run_1,run_2);
            compareHistoRunList("mMFTClusterPatternIndex",1,run_1,run_2);
            compareHistoRunList("mMFTClustersROFSize",1,run_1,run_2);
            compareHistoRunList("mMFTClusterSensorIndex",1,run_1,run_2);
        }
        if(plot==2){
            compareHistoRunList("mMFTTrackTanl",2,"0","0");
            compareHistoRunList("mMFTTrackPhi",2,"0","0");
            compareHistoRunList("mMFTTrackEta",2,"0","0");
            compareHistoRunList("mMFTTrackNumberOfClusters",2,"0","0");
            compareHistoRunList("mMFTTrackROFSize",2,"0","0");
            compareHistoRunList("mMFTClusterPatternIndex",2,"0","0");
            compareHistoRunList("mMFTClustersROFSize",2,"0","0");
            compareHistoRunList("mMFTClusterSensorIndex",2,"0","0");
        }
    }
    }
}

void compareHisto(string histName, int plot, string run_1, string run_2){
    TFile *outputfile = new TFile("AnalysisTime.root","UPDATE");
    TFile *file_in = TFile::Open("OutputTime.root", "read");
    if(file_in) Printf("Input data file loaded.");
    file_in->cd(histName.c_str());
    THStack *hStack = new THStack("stack", histName.c_str());
    TLegend *legend = new TLegend(0.7,0.6,0.9,0.9);
    TH1F *run1 = new TH1F();
    TH1F *run2 = new TH1F();
    TIter next(gDirectory->GetListOfKeys());
    TKey *key;
    double norm;
    double norm_1;
    double norm_2;
    int i = 0;
        while ((key=(TKey*)next())) {
            TH1F *histName = (TH1F*)key->ReadObj();
            histName->SetLineColor(i+1);
            norm = 1/histName->GetEntries();
            histName->Sumw2();
            histName->Scale(norm);
            hStack->Add(histName);
            legend->AddEntry(histName,Form("Run %s",histName->GetName()));
            if((histName->GetName())==run_1){
                run1 = (TH1F*)histName->Clone();
                //run1->Sumw2();
                norm_1 = 1/run1->GetEntries();
                run1->Scale(norm_1);
            }
            if((histName->GetName())==run_2){
                run2 = (TH1F*)histName->Clone();
                //run2->Sumw2();
                norm_2 = 1/run2->GetEntries();
                run2->Scale(norm_2);
            }
            i++;
        }
    
    TH1F *ratio = (TH1F*)run1->Clone();
    ratio->Divide(run2);
    //ratio->Sumw2();
    
    //no ratio plot
    if(plot==2){
        DrawHistos(histName,hStack,outputfile,legend);
    }
    //ratio plot
    else if(plot==1){
        DrawHistosRatio(histName,hStack,ratio,legend,outputfile,run_1,run_2);
    }
}

void compareHistoPass(string histName, int plot, string run_1, string run_2){
    TFile *outputfile = new TFile("AnalysisTimePass.root","UPDATE");
    TFile *file_in = TFile::Open("OutputTimePass.root", "read");
    if(file_in) Printf("Input data file loaded.");
    file_in->cd(histName.c_str());
    THStack *hStack = new THStack("stack", histName.c_str());
    TLegend *legend = new TLegend(0.7,0.6,0.9,0.9);
    TH1F *run1 = new TH1F();
    TH1F *run2 = new TH1F();
    TIter next(gDirectory->GetListOfKeys());
    TKey *key;
    double norm;
    double norm_1;
    double norm_2;
    int i = 0;
        while ((key=(TKey*)next())) {
            TH1F *histName = (TH1F*)key->ReadObj();
            histName->SetLineColor(i+1);
            norm = 1/histName->GetEntries();
            histName->Sumw2();
            histName->Scale(norm);
            hStack->Add(histName);
            legend->AddEntry(histName,Form("Run %s",histName->GetName()));
            if((histName->GetName())==run_1){
                run1 = (TH1F*)histName->Clone();
                //run1->Sumw2();
                norm_1 = 1/run1->GetEntries();
                run1->Scale(norm_1);
            }
            if((histName->GetName())==run_2){
                run2 = (TH1F*)histName->Clone();
                //run2->Sumw2();
                norm_2 = 1/run2->GetEntries();
                run2->Scale(norm_2);
            }
            i++;
        }
    
    TH1F *ratio = (TH1F*)run1->Clone();
    ratio->Divide(run2);
    //ratio->Sumw2();
    
    //no ratio plot
    if(plot==2){
        DrawHistos(histName,hStack,outputfile,legend);
    }
    //ratio plot
    else if(plot==1){
        DrawHistosRatio(histName,hStack,ratio,legend,outputfile,run_1,run_2);
    }
}
void compareHistoRuns(string histName, int plot, string run_1, string run_2){
    TFile *outputfile = new TFile("AnalysisRuns.root","UPDATE");
    TFile *file_in = TFile::Open("DownloadRuns.root", "read");
    if(file_in) Printf("Input data file loaded.");
    file_in->cd(histName.c_str());
    THStack *hStack = new THStack("stack", histName.c_str());
    TLegend *legend = new TLegend(0.7,0.6,0.9,0.9);
    TH1F *run1 = new TH1F();
    TH1F *run2 = new TH1F();
    //string run_1 = "519041";
    //string run_2 = "519045";
    TIter next(gDirectory->GetListOfKeys());
    TKey *key;
    double norm;
    double norm_1;
    double norm_2;
    int i = 0;
        while ((key=(TKey*)next())) {
            TH1F *histName = (TH1F*)key->ReadObj();
            histName->SetLineColor(i+1);
            norm = 1/histName->GetEntries();
            histName->Sumw2();
            histName->Scale(norm);
            hStack->Add(histName);
            legend->AddEntry(histName,Form("Run %s",histName->GetName()));
            if((histName->GetName())==run_1){
                run1 = (TH1F*)histName->Clone();
                //run1->Sumw2();
                norm_1 = 1/run1->GetEntries();
                run1->Scale(norm_1);
                
            }
            if((histName->GetName())==run_2){
                run2 = (TH1F*)histName->Clone();
                //run2->Sumw2();
                norm_2 = 1/run2->GetEntries();
                run2->Scale(norm_2);
            }
            i++;
        }
    
    TH1F *ratio = (TH1F*)run1->Clone();
    ratio->Divide(run2);
    //ratio->Sumw2();
    
    //no ratio plot
    if(plot==2){
        DrawHistos(histName,hStack,outputfile,legend);
    }
    //ratio plot
    else if(plot==1){
        DrawHistosRatio(histName,hStack,ratio,legend,outputfile,run_1,run_2);
    }
}

void compareHistoRunsPass(string histName, int plot, string run_1, string run_2){
    TFile *outputfile = new TFile("AnalysisRunsPass.root","UPDATE");
    TFile *file_in = TFile::Open("DownloadRunsPass.root", "read");
    if(file_in) Printf("Input data file loaded.");
    file_in->cd(histName.c_str());
    THStack *hStack = new THStack("stack", histName.c_str());
    TLegend *legend = new TLegend(0.7,0.6,0.9,0.9);
    TH1F *run1 = new TH1F();
    TH1F *run2 = new TH1F();
    TIter next(gDirectory->GetListOfKeys());
    TKey *key;
    double norm;
    double norm_1;
    double norm_2;
    int i = 0;
        while ((key=(TKey*)next())) {
            TH1F *histName = (TH1F*)key->ReadObj();
            histName->SetLineColor(i+1);
            norm = 1/histName->GetEntries();
            histName->Sumw2();
            histName->Scale(norm);
            hStack->Add(histName);
            legend->AddEntry(histName,Form("Run %s",histName->GetName()));
            if((histName->GetName())==run_1){
                run1 = (TH1F*)histName->Clone();
                //run1->Sumw2();
                norm_1 = 1/run1->GetEntries();
                run1->Scale(norm_1);
            }
            if((histName->GetName())==run_2){
                run2 = (TH1F*)histName->Clone();
                //run2->Sumw2();
                norm_2 = 1/run2->GetEntries();
                run2->Scale(norm_2);
            }
            i++;
        }
    
    TH1F *ratio = (TH1F*)run1->Clone();
    ratio->Divide(run2);
    //ratio->Sumw2();
    
    //no ratio plot
    if(plot==2){
        DrawHistos(histName,hStack,outputfile,legend);
    }
    //ratio plot
    else if(plot==1){
        DrawHistosRatio(histName,hStack,ratio,legend,outputfile,run_1,run_2);
    }
}

void compareHistoRunList(string histName, int plot, string run_1, string run_2){
    TFile *outputfile = new TFile("AnalysisRunList.root","UPDATE");
    TFile *file_in = TFile::Open("DownloadRunList.root", "read");
    if(file_in) Printf("Input data file loaded.");
    file_in->cd(histName.c_str());
    THStack *hStack = new THStack("stack", histName.c_str());
    TLegend *legend = new TLegend(0.7,0.6,0.9,0.9);
    TH1F *run1 = new TH1F();
    TH1F *run2 = new TH1F();
    TIter next(gDirectory->GetListOfKeys());
    TKey *key;
    double norm;
    double norm_1;
    double norm_2;
    int i = 0;
        while ((key=(TKey*)next())) {
            TH1F *histName = (TH1F*)key->ReadObj();
            histName->SetLineColor(i+1);
            norm = 1/histName->GetEntries();
            histName->Sumw2();
            histName->Scale(norm);
            hStack->Add(histName);
            legend->AddEntry(histName,Form("Run %s",histName->GetName()));
            if((histName->GetName())==run_1){
                run1 = (TH1F*)histName->Clone();
                //run1->Sumw2();
                norm_1 = 1/run1->GetEntries();
                run1->Scale(norm_1);
            }
            if((histName->GetName())==run_2){
                run2 = (TH1F*)histName->Clone();
                //run2->Sumw2();
                norm_2 = 1/run2->GetEntries();
                run2->Scale(norm_2);
            }
            i++;
        }
    
    TH1F *ratio = (TH1F*)run1->Clone();
    ratio->Divide(run2);
    //ratio->Sumw2();
    
    //no ratio plot
    if(plot==2){
        DrawHistos(histName,hStack,outputfile,legend);
    }
    //ratio plot
    else if(plot==1){
        DrawHistosRatio(histName,hStack,ratio,legend,outputfile,run_1,run_2);
    }
}

void compareHistoRunListPass(string histName, int plot, string run_1, string run_2){
    TFile *outputfile = new TFile("AnalysisRunListPass.root","UPDATE");
    TFile *file_in = TFile::Open("DownloadRunListPass.root", "read");
    if(file_in) Printf("Input data file loaded.");
    file_in->cd(histName.c_str());
    THStack *hStack = new THStack("stack", histName.c_str());
    TLegend *legend = new TLegend(0.7,0.6,0.9,0.9);
    TH1F *run1 = new TH1F();
    TH1F *run2 = new TH1F();
    TIter next(gDirectory->GetListOfKeys());
    TKey *key;
    double norm;
    double norm_1;
    double norm_2;
    int i = 0;
        while ((key=(TKey*)next())) {
            TH1F *histName = (TH1F*)key->ReadObj();
            histName->SetLineColor(i+1);
            norm = 1/histName->GetEntries();
            histName->Sumw2();
            histName->Scale(norm);
            hStack->Add(histName);
            legend->AddEntry(histName,Form("Run %s",histName->GetName()));
            if((histName->GetName())==run_1){
                run1 = (TH1F*)histName->Clone();
                //run1->Sumw2();
                norm_1 = 1/run1->GetEntries();
                run1->Scale(norm_1);
            }
            if((histName->GetName())==run_2){
                run2 = (TH1F*)histName->Clone();
                //run2->Sumw2();
                norm_2 = 1/run2->GetEntries();
                run2->Scale(norm_2);
            }
            i++;
        }
    
    TH1F *ratio = (TH1F*)run1->Clone();
    ratio->Divide(run2);
    //ratio->Sumw2();
    
    //no ratio plot
    if(plot==2){
        DrawHistos(histName,hStack,outputfile,legend);
    }
    //ratio plot
    else if(plot==1){
        DrawHistosRatio(histName,hStack,ratio,legend,outputfile,run_1,run_2);
    }
}

void DrawHistos(string histName, THStack *hStack,TFile *outputfile, TLegend *legend){
    TCanvas *c1 = new TCanvas(histName.c_str(),histName.c_str());
    c1->cd();
    if(histName=="mMFTClusterSensorIndex" || histName=="mMFTClusterPatternIndex"){
        gPad->SetLogy();
    }
    else if(histName=="mMFTTrackROFSize" || histName=="mMFTClustersROFSize"){
        gPad->SetLogy();
        gPad->SetLogx();
    }
    
    hStack->Draw("nostack,histo");
    legend->Draw();
    //axis and histogram title
    if(histName=="mMFTClusterSensorIndex"){
        hStack->SetTitle("Cluster Sensor Index;Chip ID");
    }
    if(histName=="mMFTClustersROFSize"){
        hStack->SetTitle("Cluster ROF Size;ROF Size");
    }
    if(histName=="mMFTTrackROFSize"){
        hStack->SetTitle("Track ROF Size;ROF Size");
    }
    if(histName=="mMFTClusterPatternIndex"){
        hStack->SetTitle("Cluster Pattern Index;Pattern ID");
    }
    if(histName=="mMFTTrackNumberOfClusters"){
        hStack->SetTitle("Track Number Of Clusters;#clusters");
    }
    if(histName=="mMFTTrackTanl"){
        hStack->SetTitle("Track Tan #lambda;tan #lambda");
    }
    if(histName=="mMFTTrackPhi"){
        hStack->SetTitle("Track #varphi;#varphi");
    }
    if(histName=="mMFTTrackEta"){
        hStack->SetTitle("Track #eta;#eta");
    }
    hStack->GetYaxis()->SetTitle("#entries");
    outputfile->cd();
    c1->Write();
    outputfile->Close();
    
}

void DrawHistosRatio(string histName, THStack *hStack, TH1F *ratio,TLegend *legend, TFile *outputfile, string run_1, string run_2){
    TCanvas *c1 = new TCanvas(histName.c_str(),histName.c_str());
    c1->cd();
    TPad *pad1 = new TPad("pad1","pad1",0,0.3,1,1);
    pad1->SetBottomMargin(0.03);
    pad1->Draw();
    pad1->cd();
    ratio->SetStats(0);
    ratio->SetLineColor(kRed);
    ratio->SetTitle("");
    ratio->GetYaxis()->SetTitle(Form("%s/%s",run_1.c_str(),run_2.c_str()));
    ratio->GetXaxis()->SetTitleSize(0.12);
    ratio->GetXaxis()->SetLabelSize(0.12);
    ratio->GetYaxis()->SetTitleSize(0.15);
    ratio->GetYaxis()->SetLabelSize(0.1);
    //ratio->GetYaxis()->SetRangeUser(-1,1);
    
    if(histName=="mMFTClusterSensorIndex" || histName=="mMFTClusterPatternIndex"){
        pad1->SetLogy(true); //gPad
    }
    else if(histName=="mMFTTrackROFSize" || histName=="mMFTClustersROFSize"){
        pad1->SetLogy(true);
        pad1->SetLogx(true);
    }
    
    hStack->Draw("nostack,hist");
    legend->Draw();
    //axis and histogram title
    if(histName=="mMFTClusterSensorIndex"){
        hStack->SetTitle("Cluster Sensor Index;Chip ID");
    }
    if(histName=="mMFTClustersROFSize"){
        hStack->SetTitle("Cluster ROF Size;ROF Size");
    }
    if(histName=="mMFTTrackROFSize"){
        hStack->SetTitle("Track ROF Size;ROF Size");
    }
    if(histName=="mMFTClusterPatternIndex"){
        hStack->SetTitle("Cluster Pattern Index;Pattern ID");
    }
    if(histName=="mMFTTrackNumberOfClusters"){
        hStack->SetTitle("Track Number Of Clusters;#clusters");
    }
    if(histName=="mMFTTrackTanl"){
        hStack->SetTitle("Track Tan #lambda;tan #lambda");
    }
    if(histName=="mMFTTrackPhi"){
        hStack->SetTitle("Track #varphi;#varphi");
    }
    if(histName=="mMFTTrackEta"){
        hStack->SetTitle("Track #eta;#eta");
    }
    hStack->GetYaxis()->SetTitle("#entries");
    hStack->GetXaxis()->SetLabelSize(0);
    hStack->GetXaxis()->SetTitleSize(0);
    
    c1->cd();
    TPad *pad2 = new TPad("pad2","pad2", 0,0.05,1,0.3);
    if(histName=="mMFTTrackROFSize" || histName=="mMFTClustersROFSize"){
        pad2->SetLogx(true);}
    pad2->SetTopMargin(0.03);
    pad2->SetBottomMargin(0.25);
    pad2->Draw();
    pad2->cd();
    ratio->Draw("pe");
    outputfile->cd();
    c1->Write();
    outputfile->Close();
    
}
