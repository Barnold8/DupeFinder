#include <stdio.h>
#include <stdlib.h>
#include "args.h"
#include "stringOps.h"

void handleArgs(int argc, char *argv[]){

    char* usageString = "Hello :D";

    if (argc <=1){

        printf(usageString);

        return;
    }

    for (int i = 1; i < argc; ++i) // i set to 1 to ignore the path where the exe was ran
    {

        if(argv[i][0] == '-'){

            switch(argv[i][1]){

                case 's':
                   
                    char* numberString = removeCharByIndex("187653",0);
                    
                    printf("Number string %s | IsNumber %d \n",numberString,stringIsNum(numberString));
                    
                    // long num1 = strtol(str1, &endptr, 10);

                    free(numberString);

                    break;
                
                case 'd':
                    
                    break;
                    
                default:
                    break;

            }

        }
    }
}

