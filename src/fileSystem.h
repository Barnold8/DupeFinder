#ifndef FILE
#define FILE

typedef struct dynamic_file_array fileArray;

typedef struct file {
    char* filePath;
    char* fileName;
} file;

typedef struct hashedFile {
    char* filePath;
    char* fileName;
    unsigned long fileHash;
} hashedFile;


fileArray getFiles(char* path);

int validPath(char* path);

#endif

