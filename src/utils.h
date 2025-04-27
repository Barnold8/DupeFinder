#ifndef UTILS_H
#define UTILS_H

#include "memory.h"


int compareHash(const void* a, const void* b);
int compareSize(const void* a, const void* b);
void sortFilesByHash(hashedFile* files, size_t count);
void sortFilesBySize(hashedFile* files, size_t count);
filePtrArray findDuplicates(filePtrArray* arr);

#endif