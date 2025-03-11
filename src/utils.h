#ifndef UTILS_H
#define UTILS_H

#include "memory.h"


int compare(const void* a, const void* b);
void sortFiles(hashedFile* files, size_t count);
filePtrArray findDuplicates(filePtrArray* arr);

#endif