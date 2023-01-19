#!/bin/bash

download(){
    echo -e "\n\e[32m============================================\n"
    echo -e "\n\e Download data - Choose an option:\n"
    echo -e "\t 1. Download run interval"
    echo -e "\t 2. Download time interval"
    echo -e "\t 3. Download selected runs"
    echo -e "\n"
    echo -e "Enter option: \c"
    read choice
    case "$choice" in
          1) echo -e "\n\e[32m=> Choose what to download\n"
                echo -e "1. Track Tan l"
                echo -e "2. Track ROF Size"
                echo -e "3. Track Number Of Clusters"
                echo -e "4. Track Phi"
                echo -e "5. Track Eta"
                echo -e "6. Cluster Pattern Index"
                echo -e "7. Cluster ROF Size"
                echo -e "8. Cluster Sensor Index"
                echo -e "9. All of the above"
                echo -e "Enter option \c"
                read downloadoption
                case "$downloadoption" in
                1) echo -e "\n\e[32m=> Enter first run number: \c"
                   read runNumber1
                   echo -e "\n\e[32m=> Enter second run number: \c"
                   read runNumber2
                   echo -e "\n\e[32m=> Downloading data for tracks\e[39m"
                   root -b -q "download.cxx(1,1,$runNumber1,$runNumber2)"
                   echo -e "\n"
                   ;;
                2) echo -e "\n\e[32m=> Enter first run number: \c"
                   read runNumber1
                   echo -e "\n\e[32m=> Enter second run number: \c"
                   read runNumber2
                   echo -e "\n\e[32m=> Downloading data for clusters\e[39m"
                   root -b -q "download.cxx(1,2,$runNumber1,$runNumber2)"
                   echo -e "\n"
                   ;;
                3) echo -e "\n\e[32m=> Enter first run number: \c"
                   read runNumber1
                   echo -e "\n\e[32m=> Enter second run number: \c"
                   read runNumber2
                   echo -e "\n\e[32m=> Downloading data for clusters\e[39m"
                   root -b -q "download.cxx(1,3,$runNumber1,$runNumber2)"
                   echo -e "\n"
                   ;;
                4) echo -e "\n\e[32m=> Enter first run number: \c"
                   read runNumber1
                   echo -e "\n\e[32m=> Enter second run number: \c"
                   read runNumber2
                   echo -e "\n\e[32m=> Downloading data for clusters\e[39m"
                   root -b -q "download.cxx(1,4,$runNumber1,$runNumber2)"
                   echo -e "\n"
                   ;;
                5) echo -e "\n\e[32m=> Enter first run number: \c"
                   read runNumber1
                   echo -e "\n\e[32m=> Enter second run number: \c"
                   read runNumber2
                   echo -e "\n\e[32m=> Downloading data for clusters\e[39m"
                   root -b -q "download.cxx(1,5,$runNumber1,$runNumber2)"
                   echo -e "\n"
                   ;;
                6) echo -e "\n\e[32m=> Enter first run number: \c"
                   read runNumber1
                   echo -e "\n\e[32m=> Enter second run number: \c"
                   read runNumber2
                   echo -e "\n\e[32m=> Downloading data for clusters\e[39m"
                   root -b -q "download.cxx(1,6,$runNumber1,$runNumber2)"
                   echo -e "\n"
                   ;;
                7) echo -e "\n\e[32m=> Enter first run number: \c"
                   read runNumber1
                   echo -e "\n\e[32m=> Enter second run number: \c"
                   read runNumber2
                   echo -e "\n\e[32m=> Downloading data for clusters\e[39m"
                   root -b -q "download.cxx(1,7,$runNumber1,$runNumber2)"
                   echo -e "\n"
                   ;;
                8) echo -e "\n\e[32m=> Enter first run number: \c"
                   read runNumber1
                   echo -e "\n\e[32m=> Enter second run number: \c"
                   read runNumber2
                   echo -e "\n\e[32m=> Downloading data for clusters\e[39m"
                   root -b -q "download.cxx(1,8,$runNumber1,$runNumber2)"
                   echo -e "\n"
                   ;;
                9) echo -e "\n\e[32m=> Enter first run number: \c"
                   read runNumber1
                   echo -e "\n\e[32m=> Enter second run number: \c"
                   read runNumber2
                   echo -e "\n\e[32m=> Downloading data for clusters\e[39m"
                   root -b -q "download.cxx(1,9,$runNumber1,$runNumber2)"
                   echo -e "\n"
                   ;;
                *) echo -e "\n\e[32m=> Option not valid. Rerun the script. \e[39m" ;;
            esac
            ;;
            2) echo -e "\n\e[32m=> Choose what to download\n"
                echo -e "1. Track Tan l"
                echo -e "2. Track ROF Size"
                echo -e "3. Track Number Of Clusters"
                echo -e "4. Track Phi"
                echo -e "5. Track Eta"
                echo -e "6. Cluster Pattern Index"
                echo -e "7. Cluster ROF Size"
                echo -e "8. Cluster Sensor Index"
                echo -e "9. All of the above"
                echo -e "Enter option \c"
                read downloadoption
                case "$downloadoption" in
                1) echo -e "\n\e[32m=> Downloading data for tracks\e[39m"
                   root -b -q "download.cxx(2,1,0,0)"
                   echo -e "\n"
                   ;;
                2) echo -e "\n\e[32m=> Downloading data for tracks\e[39m"
                   root -b -q "download.cxx(2,2,0,0)"
                   echo -e "\n"
                   ;;
                3) echo -e "\n\e[32m=> Downloading data for tracks\e[39m"
                   root -b -q "download.cxx(2,3,0,0)"
                   echo -e "\n"
                   ;;
                4) echo -e "\n\e[32m=> Downloading data for tracks\e[39m"
                   root -b -q "download.cxx(2,4,0,0)"
                   echo -e "\n"
                   ;;
                5) echo -e "\n\e[32m=> Downloading data for tracks\e[39m"
                   root -b -q "download.cxx(2,5,0,0)"
                   echo -e "\n"
                   ;;
                6) echo -e "\n\e[32m=> Downloading data for tracks\e[39m"
                   root -b -q "download.cxx(2,6,0,0)"
                   echo -e "\n"
                   ;;
                7) echo -e "\n\e[32m=> Downloading data for tracks\e[39m"
                   root -b -q "download.cxx(2,7,0,0)"
                   echo -e "\n"
                   ;;
                8) echo -e "\n\e[32m=> Downloading data for tracks\e[39m"
                   root -b -q "download.cxx(2,8,0,0)"
                   echo -e "\n"
                   ;;
                9) echo -e "\n\e[32m=> Downloading data for tracks\e[39m"
                   root -b -q "download.cxx(2,9,0,0)"
                   echo -e "\n"
                   ;;
                   
                 *) echo -e "\n\e[32m=> Option not valid. Rerun the script. \e[39m" ;;
             esac
             ;;
            3) echo -e "\n\e=> Choose what to download\n"
                echo -e "1. Track Tan l"
                echo -e "2. Track ROF Size"
                echo -e "3. Track Number Of Clusters"
                echo -e "4. Track Phi"
                echo -e "5. Track Eta"
                echo -e "6. Cluster Patter Index"
                echo -e "7. Cluster ROF Size"
                echo -e "8. Cluster Sensor Index"
                echo -e "9. All of the above"
                echo -e "Enter option \c"
                read downloadoption
                case "$downloadoption" in
                1) echo -e "\n\e=> Downloading data \e"
                   root -b -q "download.cxx(3,1,0,0)"
                   echo -e "\n"
                   ;;
                2) echo -e "\n\e=> Downloading data \e"
                   root -b -q "download.cxx(3,2,0,0)"
                   echo -e "\n"
                   ;;
                3) echo -e "\n\e=> Downloading data \e"
                   root -b -q "download.cxx(3,3,0,0)"
                   echo -e "\n"
                   ;;
                4) echo -e "\n\e=> Downloading data \e"
                   root -b -q "download.cxx(3,4,0,0)"
                   echo -e "\n"
                   ;;
                5) echo -e "\n\e=> Downloading data \e"
                   root -b -q "download.cxx(3,5,0,0)"
                   echo -e "\n"
                   ;;
                6) echo -e "\n\e=> Downloading data \e"
                   root -b -q "download.cxx(3,6,0,0)"
                   echo -e "\n"
                   ;;
                7) echo -e "\n\e=> Downloading data \e"
                   root -b -q "download.cxx(3,7,0,0)"
                   echo -e "\n"
                   ;;
                8) echo -e "\n\e=> Downloading data \e"
                   root -b -q "download.cxx(3,8,0,0)"
                   echo -e "\n"
                   ;;
                9) echo -e "\n\e=> Downloading data \e"
                   root -b -q "download.cxx(3,9,0,0)"
                   echo -e "\n"
                   ;;
                *) echo -e "\n\e[32m=> Option not valid. Rerun the script. \e[39m" ;;
            esac
            ;;
        esac
        analysis
}
        
 analysis(){
          echo -e "\n\e Do you want to compare downloaded histograms?\n"
          echo -e "\t 1. Yes, data from runs."
          echo -e "\t 2. Yes, data from timestamps."
          echo -e "\t 3. Yes, data from run list."
          echo -e "\t 4. No"
          echo -e "Enter option \c"
          read analyse
          case "$analyse" in
                    1) echo -e "\n\e[32m=> Choose what to analyse\n"
                       echo -e "1. Track Tan l"
                       echo -e "2. Track ROF Size"
                       echo -e "3. Track Number Of Clusters"
                       echo -e "4. Track Phi"
                       echo -e "5. Track Eta"
                       echo -e "6. Cluster Pattern Index"
                       echo -e "7. Cluster ROF Size"
                       echo -e "8. Cluster Sensor Index"
                       echo -e "9. All of the above"
                       echo -e "Enter option \c"
                       read analoption
                       case "$analoption" in
                       1) root -b -q "analysis.cxx(1,1)" ;;
                       2) root -b -q "analysis.cxx(1,2)" ;;
                       3) root -b -q "analysis.cxx(1,3)" ;;
                       4) root -b -q "analysis.cxx(1,4)" ;;
                       5) root -b -q "analysis.cxx(1,5)" ;;
                       6) root -b -q "analysis.cxx(1,6)" ;;
                       7) root -b -q "analysis.cxx(1,7)" ;;
                       8) root -b -q "analysis.cxx(1,8)" ;;
                       9) root -b -q "analysis.cxx(1,9)" ;;
                    esac
                    ;;
                    2) echo -e "\n\e[32m=> Choose what to analyse\n"
                       echo -e "1. Track Tan l"
                       echo -e "2. Track ROF Size"
                       echo -e "3. Track Number Of Clusters"
                       echo -e "4. Track Phi"
                       echo -e "5. Track Eta"
                       echo -e "6. Cluster Patter Index"
                       echo -e "7. Cluster ROF Size"
                       echo -e "8. Cluster Sensor Index"
                       echo -e "9. All of the above"
                       echo -e "Enter option \c"
                       read analoption
                       case "$analoption" in
                       1) root -b -q "analysis.cxx(2,1)" ;;
                       2) root -b -q "analysis.cxx(2,2)" ;;
                       3) root -b -q "analysis.cxx(2,3)" ;;
                       4) root -b -q "analysis.cxx(2,4)" ;;
                       5) root -b -q "analysis.cxx(2,5)" ;;
                       6) root -b -q "analysis.cxx(2,6)" ;;
                       7) root -b -q "analysis.cxx(2,7)" ;;
                       8) root -b -q "analysis.cxx(2,8)" ;;
                       9) root -b -q "analysis.cxx(2,9)" ;;
                       esac
                       ;;
                    3) echo -e "\n\e[32m=> Choose what to analyse\n"
                       echo -e "1. Track Tan l"
                       echo -e "2. Track ROF Size"
                       echo -e "3. Track Number Of Clusters"
                       echo -e "4. Track Phi"
                       echo -e "5. Track Eta"
                       echo -e "6. Cluster Pattern Index"
                       echo -e "7. Cluster ROF Size"
                       echo -e "8. Cluster Sensor Index"
                       echo -e "9. All of the above"
                       echo -e "Enter option \c"
                       read analoption
                       case "$analoption" in
                       1) root -b -q "analysis.cxx(3,1)" ;;
                       2) root -b -q "analysis.cxx(3,2)" ;;
                       3) root -b -q "analysis.cxx(3,3)" ;;
                       4) root -b -q "analysis.cxx(3,4)" ;;
                       5) root -b -q "analysis.cxx(3,5)" ;;
                       6) root -b -q "analysis.cxx(3,6)" ;;
                       7) root -b -q "analysis.cxx(3,7)" ;;
                       8) root -b -q "analysis.cxx(3,8)" ;;
                       9) root -b -q "analysis.cxx(3,9)" ;;
                       esac
                       ;;
                    4) echo -e "Have a nice day!\n" ;;
                    *) echo -e "\n\e[32m=> Option not valid. Rerun the script. \e" ;;
            esac
            }
        
#MAIN TASK
echo -e "\n\e[32m============================================\n"
echo -e "========== Welcome to QCAnalysis ===========\e[39m"
echo -e "\n\e[32m============================================\e[39m"
        
 download
                   
                
