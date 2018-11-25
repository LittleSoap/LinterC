#include "header.h"
FILE* openConfFile(){

    FILE* defaultFile = fopen(DEFAULT_CONF,"r");

    if(defaultFile != NULL){
        //On lit le fichier
        printf("Lecture fichier\n");
        char* LineRead = NULL;

        LineRead = readConfFile(defaultFile, LineRead );
        printf("%s", LineRead);

        return defaultFile;

    }else{

        //On crée le fichier //createConfFile
        //On initialise le fichier avec des valeurs par defaut
        if((defaultFile = createConfFile()) != NULL){
            printf("Fichier cree\n");
            return defaultFile;
        }else{
            printf("Impossible de creer le fichier\n");
            return NULL;
        }

    }

}

FILE* createConfFile(){

    FILE * defaultFile = fopen(DEFAULT_CONF,"w");

    if(defaultFile == NULL){
        return NULL;
    }else{
        return defaultFile;
    }

}

int writeConfFile(FILE* defaultConfFile){

    if(defaultConfFile == NULL){

        printf("Impossible d'écrire dans le fichier de conf\n");
        return 0;

    }

    //On ecrit les valeurs par défaut dans le fichier de conf
    fprintf(defaultConfFile, "%s","=extends\n\n");
    fprintf(defaultConfFile, "%s","=rules\n\n");
    fprintf(defaultConfFile, "%s","=excludedFiles\n\n");
    fprintf(defaultConfFile, "%s","=recursive\ntrue");
    return 1;
}


char* readConfFile(FILE * defaultFile, char* LineRead){

    LineRead = malloc(sizeof(char)* 255);

    if(defaultFile == NULL){
        return NULL;
    }

    fgets(LineRead, 255, defaultFile);

    return LineRead;

}
