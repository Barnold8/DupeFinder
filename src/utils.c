#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int compareHash(const void* a, const void* b) {
    const hashedFile* fileA = (const hashedFile*)a; 
    const hashedFile* fileB = (const hashedFile*)b;  
    
    if (fileA->fileHash < fileB->fileHash) {
        return 1;  
    } else if (fileA->fileHash > fileB->fileHash) {
        return -1;  
    } else {
        return 0;  
    }
}

int compareSize(const void* a, const void* b) {
    const hashedFile* fileA = (const hashedFile*)a; 
    const hashedFile* fileB = (const hashedFile*)b;  
    
    if (fileA->fileSize < fileB->fileSize) {
        return 1;  
    } else if (fileA->fileSize > fileB->fileSize) {
        return -1;  
    } else {
        return 0;  
    }
}


void sortFilesByHash(hashedFile* files, size_t count) {
    qsort(files, count, sizeof(hashedFile), compareHash);
}

void sortFilesBySize(hashedFile* files, size_t count) {
    qsort(files, count, sizeof(hashedFile), compareSize);
}

filePtrArray findDuplicates(filePtrArray* arr){
    
    filePtrArray duplicateFiles = {0};

    sortFilesByHash(arr->items, arr->count);

    for (int i = 0; i < arr->count - 1; i++) {
        if (arr->items[i].fileHash == arr->items[i+1].fileHash) { // Note: due to the sorting algorithm, it wont differentiate the original from a copy
            addFilePtrElements(&duplicateFiles,arr->items[i]);
        }
    }

    if(arr->items){
        // We are now done with the hashed files on the disk so we can free their contents
        free(arr->items);
        arr->items = NULL;
    }

    return duplicateFiles;
}


