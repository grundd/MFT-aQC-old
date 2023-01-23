# shell script must be first allowed: chmod +x aQC_run.sh
#!/bin/bash
# to run it do (inside ali shell):
# ./aQC_run.sh

inputFile='LHC22o_apass2_O2-3496_group2.txt'
root -q 'aQC.cxx("'$inputFile'")'

n=1 
period=""
pass=""
run=500000
while read line; do
    if (( $n == 1 )) ; then
        period=$line
        echo "period: $period"
    fi
    if (( $n == 2 )) ; then
        pass=$line
        echo "pass:   $pass"
    fi
    if (( $n > 3 )) ; then
        run=$line
        echo "run: $run"
        # single pass run statistics
        mkdir -p Results/${period}/notebook_singlePass/
        # apass1
        file_p1=MFTaQC_${run}_apass1
        papermill -p _period $period -p _run $run -p _pass apass1 notebook_aQC_singlePass.ipynb ${file_p1}.ipynb
        jupyter nbconvert --to html ${file_p1}.ipynb --no-input
        rm -r ${file_p1}.ipynb
        mv ${file_p1}.html Results/${period}/notebook_singlePass/${run}_apass1.html
        # apass2
        file_p2=MFTaQC_${run}_apass2
        papermill -p _period $period -p _run $run -p _pass apass2 notebook_aQC_singlePass.ipynb ${file_p2}.ipynb
        jupyter nbconvert --to html ${file_p2}.ipynb --no-input
        rm -r ${file_p2}.ipynb
        mv ${file_p2}.html Results/${period}/notebook_singlePass/${run}_apass2.html
        # comparison of the two passes
        mkdir -p Results/${period}/notebook_compPasses/
        file=MFTaQC_${run}_apass1_vs_apass2
        papermill -p _period $period -p _run $run -p _pass1 apass1 -p _pass2 apass2 notebook_aQC_compPasses.ipynb ${file}.ipynb
        jupyter nbconvert --to html ${file}.ipynb --no-input
        rm -r ${file}.ipynb
        mv ${file}.html Results/${period}/notebook_compPasses/${run}_apass1_vs_apass2.html
    fi
    #if (( $n == 4 )) ; then
    #    break
    #fi
    n=$((n+1))
done < $inputFile

# https://stackoverflow.com/questions/36901154/how-export-a-jupyter-notebook-to-html-from-the-command-line
# https://stackoverflow.com/questions/49907455/hide-code-when-exporting-jupyter-notebook-to-html
# https://www.wrighters.io/parameters-jupyter-notebooks-with-papermill/
# https://pypi.org/project/jupyter-runner/ 

