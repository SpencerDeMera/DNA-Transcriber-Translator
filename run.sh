#!/bin/bash

# Author: Spencer DeMera
# Email: spencer.demera@csu.fullerton.edu
# Date: 01/2022
# Purpose: Personal Project

# This is a bash shell script to be used for compiling, linking, and executing the C++ files of this assignment.
# Execute this file by navigating the terminal window to the folder where this file resides, and then enter either of the commands below:
# sh run.sh

# System requirements:
#  A Linux system with BASH shell (in a terminal window).
#  The gcc/g++ compiler must be installed.  If not installed run the command "sudo apt install build-essential" without quotes.
#  The source files and this script file must be in the same folder.
#  This file, run.sh, must have execute permission.  Go to the properties window of build.sh and put a check in the
#  permission to execute box.

# Compile C++ files to object files
g++ -c main.cpp -o main.o

# Link object files
g++ -o DNA-Translate.out main.o

# ----- Run the program -----
./DNA-Translate.out

# ----- Program finished -----