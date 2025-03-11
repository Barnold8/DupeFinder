#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    const hashedFile* fileA = (const hashedFile*)a; 
    const hashedFile* fileB = (const hashedFile*)b;  
    
    if (fileA->fileHash < fileB->fileHash) {
        return -1;  
    } else if (fileA->fileHash > fileB->fileHash) {
        return 1;  
    } else {
        return 0;  
    }
}
void sortFiles(hashedFile* files, size_t count) {
    qsort(files, count, sizeof(hashedFile), compare);
}

void findDuplicates(filePtrArray* arr){

    sortFiles(arr->items, arr->count);

    for (int i = 0; i < arr->count - 1; i++) {
        if (arr->items[i].fileHash == arr->items[i+1].fileHash) {
            printf("\nDuplicate found: \n\n\t\t[FILE_NAME] %s\n\n\t\t[FILE_PATH] %s\n\n", arr->items[i+1].filePath,arr->items[i+1].fileName);
        }
    }

}


