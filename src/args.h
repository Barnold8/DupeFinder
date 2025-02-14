#ifndef ARGS
#define ARGS

struct argsResult{

    int bufSize;
    char* folderPath;

};

void handleArgs(int argc, char *argv[]);

#endif