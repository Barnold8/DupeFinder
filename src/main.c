#include <stdio.h>
#include <string.h>
#include "args.h"           // for parsing cli args
#include "fileSystem.h"
#include "utils.h"

// This program aims to find duplicate files by hashing the entire byte array read from a file and comparing hashes with other hashes

//TODO: pass the buffer size to dictate the read width

int main(int argc, char *argv[]){

    argsResult arguments = {0};
    arguments = handleArgs(argc,argv);
   
    if(!(validArgs(&arguments))){
        printf("Invalid args\n");
        return 1;
    }

    if(validPath(arguments.folderPath)){

        filePtrArray files = getFiles(arguments.folderPath, arguments.bufSize);
        filePtrArray dupes = findDuplicates(&files);

        for(int i = 0; i < dupes.count; i++){
            printf("\nDuplicate found: \n\n\t\t[FILE_NAME] %s\n\n\t\t[FILE_PATH] %s\n\n",dupes.items[i].fileName,dupes.items[i].filePath);
        }

    }

    else {
        printf("%s is a not valid path!\n",arguments.folderPath);
        return 1;
    }

    return 0;
}
