#ifndef FILE_H
#define FILE_H

typedef struct dynamic_fileptr_array filePtrArray;

typedef struct hashedFile {
    char* filePath;
    char* fileName;
    long int fileSize;
    unsigned long fileHash;
} hashedFile;

filePtrArray getFiles(char* path,unsigned int buffer_size, int sizeOptimisation);

int validPath(char* path);

void handleDupes(filePtrArray* files);

void delWindows();

void delLinux();


#endif

