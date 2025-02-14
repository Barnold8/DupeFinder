#include <stdio.h>
#include <stdlib.h>
#include "args.h"
#include "stringOps.h"

argsResult handleArgs(int argc, char *argv[]){

    char* usageString = "USAGE dff.exe [-d C:/users/user/desktop] [-s 1064]";
    argsResult args;

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

                    if (i >= argc){// check if there is data in i+1 by seeing if the length of args is at least 1 more than i
                        // FAILURE
                        printf("PLACEHOLDER FAILURE\n");
                        return args;
                    } 
                    numberString = argv[i+1];

                    if(!(numberString && stringIsNum(numberString))){
                        // FAILURE
                        printf("PLACEHOLDER FAILURE\n");
                        return args;
                    }
                    num = atoi(numberString);

                    args.bufSize = num;
                    break;
                
                case 'd':
                    
                    if (i >= argc){// check if there is data in i+1 by seeing if the length of args is at least 1 more than i
                        // FAILURE
                        printf("PLACEHOLDER FAILURE\n");
                        return args;
                    } 
                    args.folderPath = argv[i+1];
                    break;
                
                case 'h':

                    printf("This program works by finding duplicate files and deleting the duplicates for you. Here are the flags and usages for them\n\n");
                    printf("-d This flag requires the path of where you want to search for duplicates | [-d C:/users/user/desktop]\n\n");
                    printf("-s This flag requires a number, this number determines the block size of the file stream buffer, if you have ram to use, make this number bigger, itll reduce I/O usage and thus be somewhat quicker.\n\tThis is in bytes however so you will need to know how many bytes you want to use at a time | [-s 1064]\n\n");
                    printf("-h This flag prints this lovely help information\n\n");

                break;

                default:
                    break;

            }

        }
    }

    return args;
}

