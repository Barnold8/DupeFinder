#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "fileSystem.h"
#include "memory.h"


int validPath(char* path){

    char* string = (char*) malloc((1024)*sizeof(char)); // personally, might be overkill

    int pathLen = strlen(path);

    if (string == NULL){
        free(string);
        string = NULL;
        return 0;
    }

    #ifdef _WIN32 // my version stops me needing windows.h at this moment in time so thats how im doing it 

        char* dir = "dir ";
        int dirLen = strlen(dir);
        
        //+1 for \0
        memcpy(string, dir, dirLen); 
        memcpy(string + dirLen,path,pathLen+1);

        int returnValue = system(string);
        system("cls"); // just to clean up really

        if(string != NULL){
            free(string);
            string = NULL;
        }
    
        return (returnValue != 0) ? 0 : 1; // stupid

    #elif __linux__ 

        char* ls = "ls ";
        int lsLen = strlen(ls);
        
        //+1 for \0
        memcpy(string, ls, lsLen); 
        memcpy(string + lsLen,path,pathLen+1);

        int returnValue = system(string);
        system("clear"); // just to clean up really

        if(string != NULL){
            free(string);
            string = NULL;
        }
    
        return (returnValue != 0) ? 0 : 1; // stupid
    
    #else

        printf("Warning! You are attempting to run this code ona system that does not support it. This program is intended for Windows and Linux systems\n");
        if(string != NULL){
            free(string);
            string = NULL;
        }

        return 0;
    #endif

    if(string != NULL){
        free(string);
        string = NULL;
    }

    return 0;
}

fileArray getFiles(char* path) {

    // Only compatible compilers:
        // GCC (MinGW-w64)
        // MSYS2 (GCC-based) 
        // Cygwin (GCC-based) 

    DIR *d;
    struct dirent *dir;
    struct stat fileStat;
    char fullPath[1024];
    fileArray files = {0};

    d = opendir(path);
    if (!d) {
        printf("Failed to open directory: %s\n", path);
        return files;
    }

    while ((dir = readdir(d)) != NULL) {
        if (dir->d_name[0] == '.') continue; 

        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, dir->d_name);

        if (stat(fullPath, &fileStat) == 0) {
                if (S_ISREG(fileStat.st_mode)) {

                    file _file = {
                        .filePath = strdup(fullPath),
                        .fileName = strdup(dir->d_name)
                    };

                    addFileElements(&files,_file);
                }

        } else {
            printf("Error getting info for: %s\n", fullPath);
        }
    }

    closedir(d);

    return files;
}
