#!/bin/bash

make

if [ $? -eq 0 ]; then
    ./a.exe
fi