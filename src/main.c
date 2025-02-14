#include <stdio.h>
#include "args.h"
#include "hash.h"

// This program aims to find duplicate files by hashing the entire byte array read from a file and comparing hashes with other hashes

int main(int argc, char *argv[]){

    FILE *fptr;

    handleArgs(argc,argv);

    char buf[1028];

    setbuf(stdin, buf);

    fptr = fopen("test/video1.mp4", "rb");

    if (fptr == NULL)
    {
         printf("The file could not be read");
         return 0;     
    }   

    // fileHash(fptr);

    return 0;
}