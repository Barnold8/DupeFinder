#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "fileSystem.h"
#include "memory.h"
#include "hash.h"
#include "utils.h"
#include "stringOps.h"


int validPath(char* path){

    char* os_depend;

    #ifdef _WIN32
    
        os_depend = mergeStrings("dir \"",path);

    #elif __linux__ 
        
        os_depend = mergeStrings("ls \"",path); 

    #endif

    fixPath(os_depend);

    int returnValue = system(os_depend);

    #ifdef _WIN32
    
        system("cls"); // just to clean up really

    #elif __linux__ 
        
        system("clear"); // just to clean up really 

    #endif
 
    if(os_depend != NULL){
        free(os_depend);
        os_depend = NULL;
    }

    return (returnValue != 0) ? 0 : 1; // stupid
}

filePtrArray getFiles(char* path, unsigned int buffer_size) {

    DIR *d;
    struct dirent *dir;
    struct stat fileStat;
    char fullPath[1024];
    filePtrArray files = {0};

    d = opendir(path);
    if (!d) {
        printf("Failed to open directory: %s\n", path);
        return files;
    }

    while ((dir = readdir(d)) != NULL) {
        if (dir->d_name[0] == '.') continue; 

        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, dir->d_name);

        printf("Grabbing file [%s]\n\n",fullPath);

        if (stat(fullPath, &fileStat) == 0) {
                if (S_ISREG(fileStat.st_mode)) {

                    FILE* fptr;

                    fptr = fopen(strdup(fullPath), "rb");
                    
                    if(!fptr){
                        printf("Error reading %s\n",strdup(fullPath));
                        continue;
                    }

                    hashedFile _file = {
                        .filePath = strdup(fullPath),
                        .fileName = strdup(dir->d_name),
                        .fileHash = fileHash(fptr,buffer_size)
                    };
                    
                    addFilePtrElements(&files,_file);

                    fclose(fptr);
                }

        } else {
            printf("Error getting info for: %s\n", fullPath);
        }
    }

    closedir(d);

    return files;
}

void handleDupes(filePtrArray* files){ 

    filePtrArray dupes = findDuplicates(files);
    char* string = (char*) malloc((1024)*sizeof(char)); // personally, might be overkill
    char* optionsString = "\n\nOptions:\n\n\t\tWrite the file numbers (as seen on the left of each found file, to remove them)\n\n\t\tWrite -1 to remove all files\n\n\t\tWrite -2 and then a range to delete that range of files (n-m). This deletes files in range n to m\n\n\t\tWrite -3 to quit\n\n\n\n";

    if(files->items != NULL) free(files->items);

    if(dupes.count >=1){
        printf("===================Duplicates found===================\n\n");
        
        for(int i = 0; i < dupes.count; i++){
            printf("\n\t\t[%d] [FILE_NAME] %s | [FILE_PATH] %s\n\n",i,dupes.items[i].fileName,dupes.items[i].filePath);
        }

        printf(optionsString);
        
        intArray parsedInput = parseInput();

        if(parsedInput.count != -1){

            if(parsedInput.count >= 1 &&parsedInput.items[0] <= -1){

                switch(parsedInput.items[0]){

                    case -1:
                        // remove all files

                        for(int i = 0; i < dupes.count; i++){

                            char* pathAmmended = mergeStrings(dupes.items[i].filePath,"\"");
                            int pathLen = strlen(dupes.items[i].filePath);

                            #ifdef _WIN32 // attempted to merge strings but failed lol
                            
                                char* del = mergeStrings("del \"",pathAmmended);

                                if(pathAmmended != NULL){
                                    free(pathAmmended);
                                    pathAmmended = NULL;
                                }

                                fixPath(del);

                                system(del);

                                free(del);
                            
                            #elif __linux__
                              
                                char* rm = mergeStrings("rm \"",pathAmmended);
                      
                                fixPath(rm);

                                system(rm);

                                free(rm);

                            #endif
                        }

                        break;

                    case -2:
                        return;

                    default:
                        return;
                }


            }

        }else{


        }


    }else{
        printf("===================No duplicates found===================\n\n");
    }


    if(string != NULL){
        free(string);
    }

}
