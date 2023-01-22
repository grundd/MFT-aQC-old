# shell script must be first allowed: chmod +x aQC_run.sh
#!/bin/bash
# to run it do (inside ali shell):
# ./aQC_run.sh

inputFile='LHC22o_apass2_O2-3496.txt'
#root 'aQC.cxx("'$inputFile'")'

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
        #papermill -p _period $period -p _run $run aQC_notebook.ipynb temp.ipynb
        #jupyter nbconvert --to html temp.ipynb --no-input
        #rm -r temp.ipynb
    fi
    n=$((n+1))
done < $inputFile

# https://stackoverflow.com/questions/36901154/how-export-a-jupyter-notebook-to-html-from-the-command-line
# https://stackoverflow.com/questions/49907455/hide-code-when-exporting-jupyter-notebook-to-html
# https://www.wrighters.io/parameters-jupyter-notebooks-with-papermill/
# https://pypi.org/project/jupyter-runner/ 

