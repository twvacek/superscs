#!/bin/bash


# Send converage data to codecov
if [[ $CC = *"gcc"* ]]; then bash <(curl -s https://codecov.io/bash); fi