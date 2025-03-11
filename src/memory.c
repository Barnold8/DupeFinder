
#include "memory.h"
#include "fileSystem.h" 
#include <stdlib.h>


void addFileElements(fileArray* fileArray, file _file){

    if(fileArray->count >= fileArray->capacity){ // if the count is equal to or higher than the capacity
        
        if(fileArray->capacity == 0) fileArray->capacity = 256; // if the capacity of the array is empty, fill up to 256 values
        else fileArray->capacity *= 2; // else double it

        fileArray->items = realloc(fileArray->items,fileArray->capacity*sizeof(*fileArray->items)); // do the actual memory management
    }
    
    fileArray->items[fileArray->count++] = _file; // add element to array at position while also incrementing the count

}

void addFilePtrElements(filePtrArray* filePtrArray, hashedFile _filePtr){

    if(filePtrArray->count >= filePtrArray->capacity){ // if the count is equal to or higher than the capacity
        
        if(filePtrArray->capacity == 0) filePtrArray->capacity = 256; // if the capacity of the array is empty, fill up to 256 values
        else filePtrArray->capacity *= 2; // else double it

        filePtrArray->items = realloc(filePtrArray->items,filePtrArray->capacity*sizeof(*filePtrArray->items)); // do the actual memory management
    }
    
    filePtrArray->items[filePtrArray->count++] = _filePtr; // add element to array at position while also incrementing the count

}

