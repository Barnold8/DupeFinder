#include <stdio.h>
#include <string.h>
#include "args.h"
#include "hash.h"

// This program aims to find duplicate files by hashing the entire byte array read from a file and comparing hashes with other hashes

int main(int argc, char *argv[]){

    FILE *fptr;

    argsResult arguments = {0};
    arguments = handleArgs(argc,argv);
   
    if(!(validArgs(&arguments))){
        printf("Invalid args\n");
        return 1;
    }

    return 0;
}
    // fptr = fopen("test/video1.mp4", "rb");
    // fptr = fopen("test/test.txt", "rb");

    // if (fptr == NULL)
    // {
    //      printf("The file could not be read");
    //      fflush(stdout);
    //      return 1;     
    // }   

    // fileHash(fptr,arguments.bufSize);