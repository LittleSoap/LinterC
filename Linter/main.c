#include "header.h"


int main(int argc, char** argv){

    FILE* defaultConfFile;
    defaultConfFile = openConfFile();

    if(defaultConfFile == NULL){
        printf("Erreur Conf\n");
        return -1;
    }

    writeConfFile(defaultConfFile);

    fclose(defaultConfFile);

    return 0;
}

