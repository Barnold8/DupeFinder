#ifndef FILE
#define FILE

typedef struct hashedFile{
    char* filePath;
    unsigned long fileHash;
}hashedFile;


int validPath(char* path);

void getFiles(char* path);

#endif 