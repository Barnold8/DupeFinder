#ifndef ARGS
#define ARGS

typedef struct argsResult{

    int bufSize;
    char* folderPath;

}argsResult;

argsResult handleArgs(int argc, char *argv[]);

#endif