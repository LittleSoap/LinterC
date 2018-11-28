#include "header.h"


int main(int argc, char** argv){

    int line = 0;

    FILE* defaultConfFile;
    defaultConfFile = openConfFile();

    if(defaultConfFile == NULL){
        printf("Erreur Conf\n");
        return -1;
    }

    //writeConfFile(defaultConfFile);

    fclose(defaultConfFile);

    int space = comma_spacing("main.c");

    if(space){
        printf("Il manque un espace apres une virgule");
    }else{
        printf("Fichier OK");
    }

    return 0;
}
