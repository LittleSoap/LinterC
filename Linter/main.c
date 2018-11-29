#include "header.h"


int main(int argc, char** argv){


    FILE* defaultConfFile;
    defaultConfFile = openConfFile();

    if(defaultConfFile == NULL){
        printf("Erreur Conf\n");
        return -1;
    }

    //writeConfFile(defaultConfFile);

    fclose(defaultConfFile);

    int error = array_bracket_eol("main.c");

    printf("\n%d", error);

    return 0;
}
