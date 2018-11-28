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

    int error = max_line_numbers(80, "main.c");

    if(error){
        printf("Une ligne depasse la longueur autorisee ");
    }else{
        printf("Fichier OK");
    }




    return 0;
}

//
//



