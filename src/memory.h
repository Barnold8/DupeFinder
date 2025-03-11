#ifndef MEMORY
#define MEMORY
#include <stddef.h>

#include "fileSystem.h"


typedef struct dynamic_int_array{
    int* items;
    size_t count;
    size_t capacity;
} intArray;

typedef struct dynamic_file_array{
    file* items;
    size_t count;
    size_t capacity;
}fileArray;

void addElements(fileArray* fileArray, file _file);


#endif