#include "file.h"


int validPath(char* path);{

    #ifdef _WIN32 
        printf("System Windows");
        system("dir");
    
    #elif __linux__ 
        printf("System Linux");
        system("ls");

    return 1;
}