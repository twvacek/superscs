#!/bin/bash

if [[ $TRAVIS_OS_NAME == 'osx' ]]; then
else
    sudo gem install coveralls-lcov
    # Build SuperSCS and the unit tests
    make COV=1 test
    # Build the Python SuperSCS module
    cd python/
    sudo python setup.py install
    cd ..
fi