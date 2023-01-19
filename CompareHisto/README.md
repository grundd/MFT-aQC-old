# QCAsync-Histo-Compare instructions
The code in this repository was created in order to downlaod histograms from ccdb based on choice of time, run, pass or histogram name and to compare them.

## Prepare the environment
In order to be able to run the scripts you will need to build the QualityControl (origin/master) or O2 (origin/dev) software (please note that O2 is crucial for the scripts to function). The installation is based on *aliBuild*. For installing aliBuild, see the pre-requisites [here](https://alice-doc.github.io/alice-analysis-tutorial/building/custom.html#prerequisites) and follow [these](https://alice-doc.github.io/alice-analysis-tutorial/building/custom.html#get-or-upgrade-alibuild) instructions for the installation. Then, you need to build the packages. To do so you can follow the standard guide [here](https://alice-doc.github.io/alice-analysis-tutorial/building/build.html#%F0%9F%9B%A0-build-the-packages).

After installation check that command
```bash
alienv enter QualityControl/latest
```
or

```bash
alienv enter O2/latest
```
works on your computer.

Before running, give permissions to execute the script **start.sh** by writing in the terminal
```bash
chmod +x start.sh
```

## Download
1. Before running the bash script, enter O2 or QualityControl environment
```bash
alienv enter QualityControl/latest
```
or

```bash
alienv enter O2/latest
```

2. Start the bash script in a folder containing **start.sh**, **download.cxx**, **analysis.cxx** by
```bash
./start.sh
```

The script will first let you choose between 3 download options
1. Download run interval
2. Download time interval
3. Donwlaod selected runs

After choosing one of these options you may choose what histogram you want to download
1. Track Tan l
2. Track ROF Size
3. Track Number Of Clusters
4. Track Phi
5. Track Eta
6. Cluster Pattern Index
7. Cluster ROF Size
8. Cluster Sensor Index
9. All of the above

you will be asked to enter additional information such as run or time interval endpoints or list of selected runs.
**NOTE** List of selected runs must be entered in a format ending by 0, e.g.
```bash
519041 519045 0
```

Last option is to choose whether to download based on choose of passes, please enter you answer in a format with a space as delimination, e.g.
```bash
apass1 apass2 apass3
```

Afterwards the script downloads files based on previous choices and saves them in a given file.
1. Download run interval -> DownloadRuns.root (if pass was chosen -> DownloadRunsPass.root)
2. Download time interval -> DownloadTime.root (if pass was chosen -> DownloadTimePass.root)
3. Download selected runs -> DownloadRunList.root (if pass was chosen -> DownloadRunListPass.root)

Please note that each time you run the same download and pass choice, the files will be rewritten.

## Analysis
Afterwards the script will ask about analysis, whether you want to compare histogram, where you enter the same choices as for download. Furthermore the program will ask whether the user wants to create a ratio plot of given two runs. The Y axis has to be corrected by the user in TBrowser, as it depends on given runs. Results are stored in files named according to choices of download (Download is exchanged for Analysis).

The analysis is done by a separate functions in the bash script and a separate script. This leaves an open window for any future macros used for analysis that can be just added as a bash option. Furthermore it allows to run only analysis script on previously downloaded data without the need to download it everytime one wants to analyse them.
