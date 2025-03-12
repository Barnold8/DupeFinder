#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "args.h"           // for parsing cli args
#include "fileSystem.h"
#include "utils.h"
#include "stringOps.h"


#define INPUT_BUFFER 1024

// This program aims to find duplicate files by hashing the entire byte array read from a file and comparing hashes with other hashes

//TODO: give functionality to delete specific files given idexes,delete all files, delete range, or just quit

void parseInput(){

    char userInput[INPUT_BUFFER];
    int stringLen;

    printf("Enter here: ");

    if (fgets(userInput, sizeof(userInput), stdin) != NULL) {
        userInput[strcspn(userInput, "\n")] = '\0'; 
    }
    
    stringLen = strlen(userInput); // needed because user input string can be < INPUT_BUFFER

    stringSplit(userInput," ");


} 

void handleDupes(filePtrArray* files){

    filePtrArray dupes = findDuplicates(files);

    if(dupes.count >=1){
        printf("===================Duplicates found===================\n\n");
        for(int i = 0; i < dupes.count; i++){
            printf("\n\t\t[%d] [FILE_NAME] %s | [FILE_PATH] %s\n\n",i,dupes.items[i].fileName,dupes.items[i].filePath);
        }
        printf("\n\nOptions:\n\n\t\tWrite the file numbers (as seen on the left of each found file, to remove them)\n\n\t\tWrite -1 to remove all files\n\n\t\tWrite a range to delete that range of files (n-m) delete files in range n to m\n\n\t\tWrite -2 to quit\n\n\n\n");
        parseInput();
    }else{
        printf("===================No duplicates found===================\n\n");
    }
}

int main(int argc, char *argv[]){

    argsResult arguments = {0};
    arguments = handleArgs(argc,argv);
   
    if(!(validArgs(&arguments))){
        printf("Invalid args\n");
        return 1;
    }

    if(validPath(arguments.folderPath)){
       
        filePtrArray files = getFiles(arguments.folderPath, arguments.bufSize);
        
        if(files.count >=1) handleDupes(&files);
        else printf("===================No files found===================\n\n");

    }

    else {
        printf("%s is a not valid path!\n",arguments.folderPath);
        return 1;
    }

    return 0;
}
