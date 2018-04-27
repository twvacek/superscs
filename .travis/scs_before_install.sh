#!/bin/bash

if [[ $TRAVIS_OS_NAME == 'linux' ]]; then
    sudo ldconfig;
    # The following line is because travis CI can't locate 
    # clang under sudo.
    export CC=`which $CC`;
fi