#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileSystem.h"


int validPath(char* path){

    char* string = (char*) malloc((1024)*sizeof(char)); // personally, might be overkill

    int pathLen = strlen(path);

    if (string == NULL){
        free(string);
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

        return (returnValue == 1) ? 0 : 1; // stupid

    #elif __linux__ 

        char* ls = "ls ";



        // system("ls " + path);

    #endif


    return 0;
}