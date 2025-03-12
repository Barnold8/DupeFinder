#include "stringOps.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int stringIsNum(char* string){

    int pointer = 0;

    while(string[pointer] != '\0'){

        if(!(string[pointer] >=48 && string[pointer] <= 57)) return 0;
        pointer++;
    }
    
    return 1;
}

strArray stringSplit(char* string, const char* delim) {
    
    strArray splitStrings = {0};
    char* token = strtok(string, delim); 

    if(token == NULL){
        printf("Error: initial token in split string function returns NULL\n");
        return splitStrings;
    }

    while (token != NULL) {
        addStringElements(&splitStrings,token);
        token = strtok(NULL, delim);
    }

    return splitStrings;
}
