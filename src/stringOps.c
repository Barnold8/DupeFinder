#include "stringOps.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int stringIsNum(char* string){

    int boolean = 0;
    int pointer = 0;

    while(string[pointer] != '\0'){

        if((string[pointer] >=48 && string[pointer] <= 57)) return 0;
        pointer++;
    }
    
    return 1;
}

strArray stringSplit(char* string, char delim){

    strArray splitStrings;

    char* token = strtok(string, " ");
 

    while (token != NULL) {
        printf(" % s\n", token);
        token = strtok(NULL, " - ");
    }

    return splitStrings;

}

