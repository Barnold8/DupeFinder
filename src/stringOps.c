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
        printf("Error: initial token in split string function returns NULL (an empty string was passed into the stringSplit function or some other undefined error occurred)\n");
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
            addIntElements(&ints,atoi(strArray->items[i]));

        }else{
            
            printf("PLACEHOLDER ERROR\n");
            ints.count = -1; // using this for an error value
            return ints;
            
        }
    }

    free(strArray->items);

    for(int i = 0; i < ints.count; i++){

        printf("ints[%d]: %d\n\n",i, ints.items[i]);

    }

    return ints;
}


intArray parseInput(){ 

    char userInput[INPUT_BUFFER];
    int stringLen;
    intArray parsedInput = {0};

    printf("Enter here: ");

    if (fgets(userInput, sizeof(userInput), stdin) != NULL) {
        userInput[strcspn(userInput, "\n")] = '\0'; 
    }
    
    strArray splitStrings = stringSplit(userInput," ");

    if(splitStrings.capacity <= 0){
        if(splitStrings.items != NULL) free(splitStrings.items);
        
        parsedInput.count = -1;
        
        printf("Error PLACEHOLDER\n");

        return parsedInput;
    }

    if(splitStrings.count != -1){
        parsedInput = strArrToIntArr(&splitStrings);
        return parsedInput;
        
    }
    return parsedInput;
} 
