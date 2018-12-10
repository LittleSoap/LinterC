#include "header.h"

char * my_flush(char * tab){

    int i;
    for(i =0; i<(strlen(tab)-1); i++){
        if(tab[i] == '\n'){
            tab[i] = '\0';
        }
    }

    return tab;

}

void printArray2D(char ** tab, int counter){
        int i;
        for(i=0; i< counter; i++){
            printf("%s\n", tab[i]);
        }
}


