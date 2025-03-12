
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

void addFilePtrElements(strArray* stringArray, char* string){

    
    if(stringArray->count >= stringArray->capacity){ // if the count is equal to or higher than the capacity
        
        if(stringArray->capacity == 0) stringArray->capacity = 256; // if the capacity of the array is empty, fill up to 256 values
        else stringArray->capacity *= 2; // else double it

        stringArray->items = realloc(stringArray->items,stringArray->capacity*sizeof(*stringArray->items)); // do the actual memory management
    }

    stringArray->items[stringArray->count++] = string; // add element to array at position while also incrementing the count
}


