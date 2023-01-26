# shell script must be first allowed: chmod +x aQC_run.sh
#!/bin/bash
# to run it do (inside ali shell):
# ./aQC_run.sh

inputFile='LHC22i1_passMC_O2-3486.txt'
#inputFile='LHC22o_apass2_O2-3496_group1.txt'
#inputFile='LHC22o_apass2_O2-3496_group2.txt'
root -q 'aQC.cxx("'$inputFile'")'

n=1 
period=""
pass1=""
pass2=""
type=""
nRuns=0
run=500000
while read line; do
    if (( $n == 1 )) ; then
        period=$line
        echo "period:  $period"
    elif (( $n == 2 )) ; then
        pass1=$line
        echo "pass1:   $pass1"
    elif (( $n == 3 )) ; then
        pass2=$line
        echo "pass2:   $pass2"
    elif (( $n == 4 )) ; then
        type=$line
        echo "data/MC: $type"
    elif (( $n == 5 )) ; then
        nRuns=$line
        echo "# runs:  $nRuns"
    else
        run=$line
        echo "run: $run"
        # single pass run statistics
        mkdir -p Results/${period}/notebook_singlePass/
        # apass1
        file1=MFTaQC_${run}_${pass1}
        papermill -p _period $period -p _type $type -p _pass $pass1 -p _run $run notebook_aQC_singlePass.ipynb ${file1}.ipynb
        jupyter nbconvert --to html ${file1}.ipynb --no-input
        rm -r ${file1}.ipynb
        mv ${file1}.html Results/${period}/notebook_singlePass/${run}_${pass1}.html
        # if other pass available, plot it and then do comparison
        if [ $pass2 = "none" ] ; then
            echo "no other passes"
        else
            # apass2
            file2=MFTaQC_${run}_${pass2}
            papermill -p _period $period -p _type $type -p _pass $pass2 -p _run $run notebook_aQC_singlePass.ipynb ${file2}.ipynb
            jupyter nbconvert --to html ${file2}.ipynb --no-input
            rm -r ${file2}.ipynb
            mv ${file2}.html Results/${period}/notebook_singlePass/${run}_${pass2}.html
            # comparison of the two passes
            mkdir -p Results/${period}/notebook_compPasses/
            file=MFTaQC_${run}_${pass1}_vs_${pass2}
            papermill -p _period $period -p _type $type -p _pass1 $pass1 -p _pass2 $pass2 -p _run $run notebook_aQC_compPasses.ipynb ${file}.ipynb
            jupyter nbconvert --to html ${file}.ipynb --no-input
            rm -r ${file}.ipynb
            mv ${file}.html Results/${period}/notebook_compPasses/${run}_${pass1}_vs_${pass2}.html
        fi
    fi
    n=$((n+1))
done < $inputFile

# https://stackoverflow.com/questions/36901154/how-export-a-jupyter-notebook-to-html-from-the-command-line
# https://stackoverflow.com/questions/49907455/hide-code-when-exporting-jupyter-notebook-to-html
# https://www.wrighters.io/parameters-jupyter-notebooks-with-papermill/
# https://pypi.org/project/jupyter-runner/ 

