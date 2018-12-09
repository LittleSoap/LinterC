#include "header.h"

char * my_flush(char * test){

    int i;
    for(i =0; i<(strlen(test)-1); i++){
        if(test[i] == '\n'){
            test[i] = '\0';
        }
    }

    return test;

}

void printArray2D(char ** tab, int counter){
        int i;
        for(i=0; i< counter; i++){
            printf("%s\n", tab[i]);
        }
}


