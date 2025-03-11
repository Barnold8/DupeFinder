#include <stdio.h>
#include <string.h>
#include "args.h"
#include "hash.h"
#include "fileSystem.h"
#include "memory.h"
#include "utils.h"

// This program aims to find duplicate files by hashing the entire byte array read from a file and comparing hashes with other hashes

//TODO: Sort the array of files and then use that for checking adjacent hashes for duplicates

int main(int argc, char *argv[]){

    argsResult arguments = {0};
    arguments = handleArgs(argc,argv);
   
    if(!(validArgs(&arguments))){
        printf("Invalid args\n");
        return 1;
    }

    if(validPath(arguments.folderPath)){
        //printf("\nFile[%d]\n\n\t\t[FILE_PATH]: %s\n\t\t[FILE_NAME]: %s\n\t\t[FILE_HASH] %lu\n\n",i,files.items[i].filePath,files.items[i].fileName,files.items[i].fileHash);
        filePtrArray files = getFiles(arguments.folderPath);
        filePtrArray dupes = findDuplicates(&files);

        for(int i = 0; i < dupes.count; i++){
            printf("\nDuplicate found: \n\n\t\t[FILE_NAME] %s\n\n\t\t[FILE_PATH] %s\n\n", dupes.items[i].filePath,dupes.items[i].fileName);
        }

    }

    else {
        printf("%s is a not valid path!\n",arguments.folderPath);
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