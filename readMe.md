# DupeFinder  

## Table of Contents  
- [About](#about)  
- [Requirements](#requirements)  
- [Usage](#usage)  
  - [Flags](#flags)  

## About  

IVE NOT FINISHED THE PYTHON VERSION YET

I decided to make this project so I have a version of the program that I know will work since it's 10x easier to make. I use this software on a regular basis and I want a version I know works and wont fail so the python branch is just that. It also gives me a platform to make new features for the software in a quick and timely, and less buggy, manner rather than the headache that C can bring sometimes. As of writing this 05/11/2025, I am not sure the C version works as intended so I need to probably re-write some parts, mainly the hashing algorithm. 

## Requirements  

Python 3.12.0 (might work on older versions but this is the version I wrote the software in)

# Usage

## Flags

| Flag    | Usage | Example |
| -------- | ------- |----- |
| -d  | To specify a directory path | DupeFinder.py -d D:\foo\Bar |
| -s | To specify the how much of a file is read (in bytes) per read | DupeFinder.py -s 1064 |
| -c | To specify optimisation mode. Currently {0: default, 1: size optimisation} | DupeFinder.py -c 1 |