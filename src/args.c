#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "args.h"
#include "stringOps.h"

void flushInputBuffer(){
    while(getchar() != '\n');
}


argsResult handleArgs(int argc, char *argv[]){

    char* usageString = "USAGE DupeFinder.exe [-d C:/users/user/desktop] [-s 1064] [-c 1]";
    argsResult args = {0,0,""};

    if (argc <=1){

        printf(usageString);

        return args;
    }

    for (int i = 1; i < argc; ++i) // i set to 1 to ignore the path where the exe was ran
    {
        
        if(argv[i][0] == '-'){
      
            switch(argv[i][1]){

                case 's':
           
                    char* numberString;
                    int num;

                    if (i+1 >= argc){// check if there is data in i+1 by seeing if the length of args is at least 1 more than i
                        // FAILURE
   
                        printf("User-Error: A number was expected for the -s flag but no number was provided for this flag\n");
                        return args;
                    } 
                    numberString = argv[i+1];

                    if(!(numberString && stringIsNum(numberString))){
                        // FAILURE
                        printf("Program-Error: Cannot process non number input for bytesize of file reader\n");
                        return args;
                    }
                    num = atoi(numberString);

                    args.bufSize = num;
                    break;
                
                case 'd':
                    
                    if (i+1 >= argc){// check if there is data in i+1 by seeing if the length of args is at least 1 more than i
                        // FAILURE
     
                        printf("User-Error: A path was expected for the -d flag, however, none was given\n");
                        return args;
                    }
                    args.folderPath = argv[i+1];
                    break;

                case 'c':
                    
                    char* optmisationString;
                    int optimiseNum;

                    if (i+1 >= argc){// check if there is data in i+1 by seeing if the length of args is at least 1 more than i
                        // FAILURE

                        printf("User-Error: A number was expected for the -c flag but no number was provided for this flag\n");
                        return args;
                    } 
                    optmisationString = argv[i+1];

                    if(!(optmisationString && stringIsNum(optmisationString))){
                        // FAILURE
                        printf("Program-Error: Cannot process non number input for conditional of size optimisation\n");
                        return args;
                    }
                    optimiseNum = atoi(optmisationString);

                    args.optimiseSize = optimiseNum;
                    break;
                    
                case 'h':
                    printf("This program works by finding duplicate files and deleting the duplicates for you. Here are the flags and usages for them\n\n");
                    printf("-d This flag requires the path of where you want to search for duplicates | [-d C:/users/user/desktop]\n\n");
                    printf("-s This flag requires a number, this number determines the block size of the file stream buffer, if you have ram to use, make this number bigger, itll reduce I/O usage and thus be somewhat quicker.\n\tThis is in bytes however so you will need to know how many bytes you want to use at a time | [-s 1064]\n\n");
                    printf("-c This determines the optimisation mode\n\n");
                    printf("-h This flag prints this lovely help information\n\n");
                    

                break;

                default:
                    break;

            }

        }
    }

    if(args.bufSize == 0) args.bufSize = 1024;
    if(strlen(args.folderPath) <= 0 ) args.folderPath = ".";

    return args;
}

int validArgs(argsResult * args){

    char decision;

    if(args->bufSize <= 0){
        printf("User-Error: cannot set buffer size to %d.\nREASON: Too small\n",args->bufSize);    
        return 0;
    }

    if(args->bufSize >= 1073741824){

        printf("WARNING! You have selected a big amount of memory to be used for the file buffer stream (over 1GB), if you don't want to use this amount of memory, please restart the program, else type Y\nDecision: ");
        
        scanf("%c", &decision);
        flushInputBuffer();

        if(!(decision == 89 || decision == 121 )) return 0; // it still passed?

    }

    if (args->folderPath == NULL || strlen(args->folderPath) <= 0) {
        // Check if folderPath is NULL before using strlen
        printf("User-Error: The folder path is invalid or not provided.\n");
        return -1;
    }

    return 1;
}