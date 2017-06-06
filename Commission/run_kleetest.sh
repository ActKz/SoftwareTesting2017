#!/bin/bash

export LD_LIBRARY_PATH=/home/klee/klee_build/klee/lib/:$LD_LIBRARY_PATH

for testcase in klee-last/test*
do
     KTEST_FILE=testcase ./a.out
done
