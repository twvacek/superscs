#!/bin/bash

# Execute the unit tests with coverage support
make COV=1 run-test

# Run the unit tests in Python
if [[ $CC = *"gcc"* ]] && [[ $SCS_RUN_PYTHON == 1 ]]; then 
    cd python/;
    python -m unittest -v test_superscs;
    cd ..;
fi

# Run profiler on an easy problem (just to make sure it works)
if [[ $TRAVIS_OS_NAME == 'linux' ]]; then
    sudo make clean
    make profile-run PF=1 PROBLEM_YAML_FILE='\"tests/c/data/test-5.yml\"' -s
fi

# Run coverage (only for gcc)
if [[ $CC = *"gcc"* ]] && [[ $SCS_RUN_COV == 1 ]]; then 
    make COV=1 cov; 
fi
