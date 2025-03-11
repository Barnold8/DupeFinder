#ifndef FILE_H
#define FILE_H

typedef struct dynamic_fileptr_array filePtrArray;

typedef struct hashedFile {
    char* filePath;
    char* fileName;
    unsigned long fileHash;
} hashedFile;

filePtrArray getFiles(char* path);

int validPath(char* path);



#endif

