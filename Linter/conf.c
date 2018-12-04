#include "header.h"

void openConfFile(){

    FILE* defaultFile = fopen(DEFAULT_CONF,"r");

    if(defaultFile == NULL){
        printf("Can't open default conf file");
        return NULL;
    }

    readConfFile(defaultFile);


    fclose(defaultFile);
}


void readConfFile(FILE * defaultFile){

    char ** extend;
    int ** rules;
    //int is_recursive;
    //char ** excluded_files;
    char * LineRead;
    int counter = 0;

    if(defaultFile == NULL){
        return NULL;
    }

    LineRead = malloc(sizeof(char)*255);
    extend = malloc(sizeof(int) * 255);

    do{

        fgets(LineRead, 255, defaultFile);

        //extends

        int i =0;

        if(strcmp(LineRead , "=extends\n") == 0){

            while(strcmp(LineRead, "\n") != 0 ){


                fgets(LineRead, 255, defaultFile);
                extend[i] = malloc(sizeof(char) * (strlen(LineRead) +1 ));

                int j;

                for(j=0; j < (strlen(LineRead)); j++){

                    extend[i][j] = LineRead[j];

                    if(extend[i][j] == '\n'){
                        extend[i][j] = '\0';
                    }
                }

                i++;
                counter++;

            }

            printArray2D(extend, counter);


        }


        //rules

        /*

            0 : array-bracket-eol
            1 : operators-spacing
            2 : comma-spacing
            3 : indent
            4 : comments-header
            5 : max-line-numbers
            6 : max-file-line-numbers
            7 : no-trailing-spaces
            8 : no-multi-declaration
            9 : unused-variable
            10 : undeclared-variable
            11 : no-prototype
            12 : unused-function
            13 : undeclared-function
            14 : variable-assignment-type
            15 : function-parameters-type


        */

        free(LineRead);

    }while(!feof(defaultFile));

    freeArray2D(extend);

}
