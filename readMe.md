# DupeFinder  

## Table of Contents  
- [About](#about)  
    - [Supported Platforms](#supported-platforms)  
- [Requirements](#requirements)  
  - [Compilers](#compilers)  
  - [Build Tools](#build-tools)  
    - [Custom python tool](#custom-python-tool)
    - [Hard coded GCC](#hard-coded-GCC)
- [Usage](#usage)  
  - [Flags](#flags)  

## About  
This program aims to find duplicate files in a given directory. Currently this program is single threaded which means it can be slow for folders with high capacities. This is more aimed at the small folders with smaller file sizes. However, I have personally tested this on a folder with hundreds of files boasting up to 3.55GB in size and it was ✨ blazingly ✨ fast.

### Supported platforms
<p align="center"> <img src="https://skillicons.dev/icons?i=windows,linux" /> </p>



## Requirements  

### Compilers  
DupeFinder compiles with the following **GCC-based** compilers due to reliance on [`dirent.h`](http://pubs.opengroup.org/onlinepubs/7908799/xsh/dirent.h.html):  
- [MinGW-w64](https://www.mingw-w64.org/) (Recommended)  
- [MSYS2](https://www.msys2.org/)  
- [Cygwin](https://www.cygwin.com/)  

> **Note:** Written in modern C (GCC default standard).  

## Build tools

### Custom python tool
I wrote my own build tool in [python](https://www.python.org/) which you can use and compiles automatically for the correct platform you are on (given the supported platforms seen in "Runs on")

Its a pretty short file since it doesnt do much but it allows you to write

``python build.py`` to compile without any extra input or 

``python build.py [args here]`` to compile your program with any compiler flags you desire

Run the build script:  
```sh
python build.py
```

Add compiler flags if needed
```
python build.py -wall -wextra
```
### Code

```py
import os
import platform
import sys

binary_name = "DupeFinder"

binary = f" -o build/{binary_name}.exe" if platform.system().lower() == "windows" else f" -o build/{binary_name}"

source = [file for file in os.listdir("src") if ".c" in file]
source[0] = "src/" + source[0] # stupid join function grumble grumble grumble

if len(sys.argv) > 1:
    build = f"gcc {sys.argv[1] } " + " src/".join(source) + binary
else:
    build = "gcc " + " src/".join(source) + binary

os.system(build)
```

### hard coded GCC

The only difference between windows and linux is the end of the binary name (.exe vs no extension name)

> Windows

```sh
gcc args.c fileSystem.c hash.c main.c memory.c stringOps.c utils.c -o build/main.exe
```

> Linux

```sh
gcc args.c fileSystem.c hash.c main.c memory.c stringOps.c utils.c -o build/main
```

# Usage

## Flags

| Flag    | Usage | Example |
| -------- | ------- |----- |
| -d  | To specify a directory path | DupeFinder.exe -d D:\foo\Bar |
| -s | To specify the how much of a file is read (in bytes) per read | DupeFinder.exe -s 1064 |
| -c | To specify optimisation mode. Currently {0: default, 1: size optimisation} | DupeFinder.exe -c 1 |

> **Note:** Flags can be combined like: DupeFinder.exe -d D:\foo\Bar -s 1064