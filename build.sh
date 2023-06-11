#!/bin/bash

cd scr 
g++ -std=c++11 -o main main.cpp Map/Map.cpp Node/Node.cpp 

./main

cd ..

cd scr_python

python3 main.py