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

int max_file_line_number(int n, char * test){

    FILE* file = fopen(test, "r");

    if(file == NULL){
        printf("Impossible d'ouvrir le fichier");
        return -1;
    }

    int counter = 0;
    char * string = malloc(sizeof(char)*255);

    while (fgets(string, 255, file)){
        printf("counter = %d\n", counter);
        counter++;
    }

    free(string);

    if(counter >= n){
        return 1;
    }else{
        return 0;
    }

}


int max_line_numbers(int n, char * test){

    FILE* file = fopen(test, "r");

    if(file == NULL){
        printf("Impossible d'ouvrir le fichier");
        return -1;
    }

    char * string = malloc(sizeof(char)*255);

    while (fgets(string, 255, file)){

        if((strlen(string) -1) > n ){
            printf("lenght : %d\n", strlen(string));
            free(string);
            return 1;
        }
    }
    free(string);
    return 0;
}


int comma_spacing(char * test){

    FILE* file = fopen(test, "r");

    if(file == NULL){
        printf("Impossible d'ouvrir le fichier");
        return -1;
    }
    char c;
    do {
        c = fgetc(file);
        if(feof(file)){
            break;
        }
        printf("%c\n", c);
        if(c == ','){
            c = fgetc(file);
            if(c != ' '){
                return 1;
            }
        }
    }while(c);

    return 0;
}


int array_bracket_eol(char *test){

    FILE* file = fopen(test, "r");

    if(file == NULL){
        printf("Impossible d'ouvrir le fichier");
        return -1;
    }
    char * string = malloc(sizeof(char) * 255);

    do {

        fgets(string, 255, file);
        int i;
        for(i = 0; i<(strlen(string)-1); i++){

            if(string[i] == '{'){

                    if(string[i-1] != ')' && string[i-1] != '\n' && (string[i-1] != 'o')){
                        printf("%c", string[i-1]);
                        return 1;
                    }

            }

        }


    }while(!feof(file));

    return 0;
}

int indent(int n, char * test){

    FILE* file = fopen(test, "r");

    if(file == NULL){
        printf("Impossible d'ouvrir le fichier");
        return -1;
    }
    char * string = malloc(sizeof(char) * 255);

    do {
        fgets(string, 255, file);
        int i=0;

        while(string[i] == ' '){
            i++;
        }
        if((i%n) != 0){
            return 1;
        }

    }while(!feof(file));

    return 0;

}





