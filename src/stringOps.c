#include "stringOps.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_BUFFER 1024

int stringIsNum(char* string){

    int pointer = 0;

    while(string[pointer] != '\0'){
        if(pointer == 0 && string[pointer] == '-'){
            pointer++;
            continue;
        }else{
            if(!(string[pointer] >= 48 && string[pointer] <= 57)) return 0;
        }
        pointer++;
    }
    
    return 1;
}

strArray stringSplit(char* string, const char* delim) {
    
    strArray splitStrings = {0};
    char* token = strtok(string, delim); 

    if(token == NULL){
        printf("Program-Error: initial token in split string function returns NULL (an empty string was passed into the stringSplit function or some other undefined error occurred)\n");
        return splitStrings;
    }

    while (token != NULL) {
        addStringElements(&splitStrings,token);
        token = strtok(NULL, delim);
    }

    return splitStrings;
}


intArray strArrToIntArr(strArray* strArray){ // error in here with negative numbers

    intArray ints = {0};

    for(int i = 0; i < strArray->count; i++){
        if(stringIsNum(strArray->items[i])){
            int num = atoi(strArray->items[i]);
            addIntElements(&ints,num);

        }else{
            
            printf("Program-Error: Trying to convert %s to an integer but failed in strArrToIntArr\n\n",strArray->items[i]);
            ints.count = -1; // using this for an error value
            return ints;
            
        }
    }

    free(strArray->items);

    return ints;
}


intArray parseInput(){ 

    char userInput[INPUT_BUFFER];
    intArray parsedInput = {0};

    printf("Enter here: ");

    if (fgets(userInput, sizeof(userInput), stdin) != NULL) {
        userInput[strcspn(userInput, "\n")] = '\0'; 
    }
    
    strArray splitStrings = stringSplit(userInput," ");

    if(splitStrings.capacity <= 0){
        if(splitStrings.items != NULL) free(splitStrings.items);
        
        parsedInput.count = -1;
        
        printf("Program-Error: 0 items found when splitting user input into sub strings\n");

        return parsedInput;
    }

    if(splitStrings.count != -1){
        parsedInput = strArrToIntArr(&splitStrings);
        if(parsedInput.count == -1){

            parsedInput.count = -1;
            printf("Program-Error: Could not convert string array to integer array equivalent\n");
            return parsedInput;
        }


        return parsedInput;
        
    }
    return parsedInput;
} 


void fixPath(char* path) {
    int pointer = 0;

    while (path != NULL && path[pointer] != '\0') {

        if (path[pointer] == '/') {
            path[pointer] = '\\'; 
        }
        pointer++;
    }
} 


char* mergeStrings(char* leftString, char* rightString){

    if(leftString == NULL){
        printf("Program-Error: In mergeStrings, left string was found to be NULL\n");
        return "";
    }
    if(rightString == NULL){
        printf("Program-Error: In mergeStrings, right string was found to be NULL\n");
        return "";
    }

    int leftLen = strlen(leftString);
    int rightLen = strlen(rightString);

                            // Total size of left string + right string and a null termination char
    char* newString = (char*)malloc(sizeof(char)*(leftLen+rightLen+1));

    memcpy(newString,leftString,sizeof(char)*leftLen);
    memcpy(newString + strlen(leftString),rightString, sizeof(char)*rightLen +1);
    newString[strlen(newString)+1] = '\0';

    return newString;
}