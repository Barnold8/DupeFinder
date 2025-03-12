
#include "memory.h"
#include "fileSystem.h" 
#include <stdlib.h>

void addFilePtrElements(filePtrArray* filePtrArray, hashedFile _filePtr){

    if(filePtrArray->count >= filePtrArray->capacity){ // if the count is equal to or higher than the capacity
        
        if(filePtrArray->capacity == 0) filePtrArray->capacity = 256; // if the capacity of the array is empty, fill up to 256 values
        else filePtrArray->capacity *= 2; // else double it

        filePtrArray->items = realloc(filePtrArray->items,filePtrArray->capacity*sizeof(*filePtrArray->items)); // do the actual memory management
    }
    
    filePtrArray->items[filePtrArray->count++] = _filePtr; // add element to array at position while also incrementing the count

}

void addStringElements(strArray* stringArray, char* string){

    if(stringArray->count >= stringArray->capacity){ // if the count is equal to or higher than the capacity
        
        if(stringArray->capacity == 0) stringArray->capacity = 256; // if the capacity of the array is empty, fill up to 256 values
        else stringArray->capacity *= 2; // else double it

        stringArray->items = realloc(stringArray->items,stringArray->capacity*sizeof(*stringArray->items)); // do the actual memory management
    }

    stringArray->items[stringArray->count++] = string; // add element to array at position while also incrementing the count
}

void addIntElements(intArray* intArray, int num){
    
    if(intArray->count >= intArray->capacity){ // if the count is equal to or higher than the capacity
        
        if(intArray->capacity == 0) intArray->capacity = 256; // if the capacity of the array is empty, fill up to 256 values
        else intArray->capacity *= 2; // else double it

        intArray->items = realloc(intArray->items,intArray->capacity*sizeof(*intArray->items)); // do the actual memory management
    }

    intArray->items[intArray->count++] = num; // add element to array at position while also incrementing the count
}



