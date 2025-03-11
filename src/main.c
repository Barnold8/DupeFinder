#include <stdio.h>
#include <string.h>
#include "args.h"           // for parsing cli args
#include "fileSystem.h"
#include "utils.h"

// This program aims to find duplicate files by hashing the entire byte array read from a file and comparing hashes with other hashes

//TODO: give functionality to delete specific files given idexes or delete all files or just quit

int main(int argc, char *argv[]){

    argsResult arguments = {0};
    arguments = handleArgs(argc,argv);
   
    if(!(validArgs(&arguments))){
        printf("Invalid args\n");
        return 1;
    }

    if(validPath(arguments.folderPath)){
       
        filePtrArray files = getFiles(arguments.folderPath, arguments.bufSize);

        if(files.count >=1){
            filePtrArray dupes = findDuplicates(&files);

            if(dupes.count >=1){
                printf("===================Duplicates found===================\n\n");
                for(int i = 0; i < dupes.count; i++){
                    printf("\n\t\t[%d] [FILE_NAME] %s | [FILE_PATH] %s\n\n",i,dupes.items[i].fileName,dupes.items[i].filePath);
                }
            }else{
                printf("===================No duplicates found===================\n\n");
            }
    
        }else{
            printf("===================No files found===================\n\n");
        }
    }

    else {
        printf("%s is a not valid path!\n",arguments.folderPath);
        return 1;
    }

    return 0;
}
