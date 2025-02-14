#include "stringOps.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* removeCharByIndex(const char* string, int index){

    int len = strlen(string);
    int bufferIndex = 0;
    if (index < 0 || index >= len) return NULL;

    char* stringBuffer= malloc(len*sizeof(char));
    if(!stringBuffer){return NULL;}

    for(int i = 0; i < len; i++){

        if(i != index){
            
            stringBuffer[bufferIndex] = string[i];
            bufferIndex++;
        }

    }
    stringBuffer[bufferIndex++] = '\0';

    return stringBuffer;
}


int stringIsNum(const char* string){



    return -1;
}
