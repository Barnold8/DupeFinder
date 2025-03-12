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
        printf("Error: initial token in split string function returns NULL (an empty string was passed into the stringSplit function or some other undefined error occurred)\n");
        return splitStrings;
    }

    while (token != NULL) {
        addStringElements(&splitStrings,token);
        token = strtok(NULL, delim);
    }

    return splitStrings;
}


intArray strArrToIntArr(strArray* strArray){

    intArray ints = {0};
    
    for(int i = 0; i < strArray->count; i++){

        if(stringIsNum(strArray->items[i])){
            int num = atoi(strArray->items[i]);
            addIntElements(&ints,num);
        }else{
            printf("PLACEHOLDER ERROR\n");
            ints.count = -1; // using this for an error value
            return ints;
        }
    }

    return ints;
}