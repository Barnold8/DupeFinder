#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "args.h"           // for parsing cli args
#include "fileSystem.h"
#include "memory.h"
#include "stringOps.h"


// This program aims to find duplicate files by hashing the entire byte array read from a file and comparing hashes with other hashes

// Only compatible compilers:
    // GCC (MinGW-w64)
    // MSYS2 (GCC-based) 
    // Cygwin (GCC-based) 

// Compile on latest version of C for best results (Written in 2025)


int main(int argc, char *argv[]){

    clock_t begin = clock();
    double time_spent;

    int divident = 1000000;

    argsResult arguments = {0};
    arguments = handleArgs(argc,argv);
   
    if(validArgs(&arguments) == -1){
        printf("FATAL ERROR: Invalid args\n");
        return 1;
    }

    if(validPath(arguments.folderPath)){   

        filePtrArray files = getFiles(arguments.folderPath, arguments.bufSize,0);

        clock_t end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
        printf("FILES COUNT %d\n",files.count);
        if(files.count >=1) handleDupes(&files);
        else printf("===================No files found===================\n\n");

    }

    else {
        printf("FATAL ERROR: %s is a not valid path!\n",arguments.folderPath);
        return 1;
    }

    printf("Executed in %f seconds\n",time_spent);

    return 0;
}
