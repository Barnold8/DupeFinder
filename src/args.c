#include "args.h"
#include <stdio.h>

void handleArgs(int argc, char *argv[]){

    if (argc <=1){

        printf("Not enough CLI args passed\n");

        return;
    }

    for (int i = 1; i < argc; ++i)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
}

