#ifndef STRINGS_H
#define STRINGS_h

#include "memory.h"

int stringIsNum(char* string);

strArray stringSplit(char* string, const char* delim);

intArray strArrToIntArr(strArray* strArray);

intArray parseInput();

#endif