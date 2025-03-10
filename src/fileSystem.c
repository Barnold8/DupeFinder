#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileSystem.h"


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

void getFiles(char* path){
    

    #ifdef _WIN32 

        printf("Win32");

    #elif __linux__

        printf("Linux");

    #else

        printf("Warning! You are attempting to run this code ona system that does not support it. This program is intended for Windows and Linux systems\n");
        // return something to signify that an error has ocurred 
    #endif

}
