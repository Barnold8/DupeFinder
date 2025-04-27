#ifndef ARGS
#define ARGS

typedef struct argsResult{

    unsigned int bufSize;
    unsigned int optimiseSize;
    char* folderPath;

}argsResult;

argsResult handleArgs(int argc, char *argv[]);

int validArgs(argsResult * args);

#endif