#!/bin/bash

# Execute the unit tests with coverage support
make COV=1 run-test

# Run the unit tests in Python
cd python/
python -m unittest -v test_superscs
cd ..

# Run profiler on an easy problem (just to make sure it works)
sudo make clean
make profile-run PF=1 PROBLEM_YAML_FILE='\"tests/c/data/test-5.yml\"' -s

# Run coverage (only for gcc)
if [[ $CC = *"gcc"* ]] && [[ $SCS_RUN_COV == 1 ]]; then 
    make COV=1 cov; 
fi
