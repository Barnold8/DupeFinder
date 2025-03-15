#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "args.h"           // for parsing cli args
#include "fileSystem.h"
#include "memory.h"
#include "stringOps.h"

// This program aims to find duplicate files by hashing the entire byte array read from a file and comparing hashes with other hashes

//TODO: give functionality to delete specific files given idexes,delete all files, delete range, or just quit


// Only compatible compilers:
    // GCC (MinGW-w64)
    // MSYS2 (GCC-based) 
    // Cygwin (GCC-based) 

// Compile on latest version of C for best results (Written in 2025)


int main(int argc, char *argv[]){

    argsResult arguments = {0};
    arguments = handleArgs(argc,argv);
   
    if(validArgs(&arguments) == -1){
        printf("FATAL ERROR: Invalid args\n");
        return 1;
    }

    if(validPath(arguments.folderPath)){   
        filePtrArray files = getFiles(arguments.folderPath, arguments.bufSize);
    
        if(files.count >=1) handleDupes(&files);
        else printf("===================No files found===================\n\n");
    }

    else {
        printf("FATAL ERROR: %s is a not valid path!\n",arguments.folderPath);
        return 1;
    }

    return 0;
}
