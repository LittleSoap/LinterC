#include "header.h"

char * my_flush(char * test){

    for(int i =0; i<(strlen(test)-1); i++){
        if(test[i] == '\n'){
            test[i] = '\0';
        }
    }

    return test;

}

void printArray2D(char ** tab, int counter){

        for(int i=0; i< counter ; i++){

            printf("%s\n", tab[i]);

        }
}

void freeArray2D(char ** tab){

    for(int i =0; i< sizeof(tab); i++){

        free(tab[i]);
    }
    free(tab);

}


