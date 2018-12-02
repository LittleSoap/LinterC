#include "header.h"


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
        for(i = 0; i<(strlen(string)-1); i++)
        {

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

int operators_spacing(char * test){


    FILE* file = fopen(test, "r");

    if(file == NULL){
        printf("Impossible d'ouvrir le fichier");
        return -1;
    }
    char * string = malloc(sizeof(char) * 255);

    do {

        fgets(string, 255, file);
        int i;

        for(i = 0; i<(strlen(string)-1); i++)
        {

            switch(string[i]){

                case '+':

                    //Case ++
                    if(string[i-1] == '+'){

                        if(string[i+1] != ' ' || string[i-2] != ' '){
                            return 0;
                        }

                    }

                    //Case ++
                    else if(string[i+1] == '+'){

                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }

                    }

                    //Case +=
                    else if(string[i+1] == '='){
                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }
                    }

                    else{

                        if(string[i-1] != ' ' || string[i+1] != ' '){
                            return 1;
                        }

                    }



                break;

                case '-' :

                    //Case --
                    if(string[i-1] == '-'){

                        if(string[i+1] != ' ' || string[i-2] != ' '){
                            return 1;
                        }

                    }

                    //Case --
                    else if(string[i+1] == '-'){

                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }

                    }

                    //Case -=
                    else if(string[i+1] == '='){
                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }
                    }

                    else{

                        if(string[i-1] != ' ' || string[i+1] != ' '){
                            return 1;
                        }

                    }



                break;

                case '*' :

                    //case *=
                    if(string[i+1] == '='){
                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }
                    }else{

                        if(string[i-1] != ' ' || string[i+1] != ' '){
                            return 1;
                        }

                    }

                break;

                case '/':

                    //case /=
                    if(string[i+1] == '='){
                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }
                    }else{

                        if(string[i-1] != ' ' || string[i+1] != ' '){
                            return 1;
                        }

                    }

                break;

                case '%':

                    //case %=
                    if(string[i+1] == '='){
                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }
                    }else{

                        if(string[i-1] != ' ' || string[i+1] != ' '){
                            return 1;
                        }

                    }

                break;

                case '=' :

                    //Case affectation and comparison
                    if(string[i-1] == '+' || string[i-1] == '-' || string[i-1] == '*' || string[i-1] == '/' || string[i-1] == '%' || string[i-1] == '<' || string[i-1] == '>' || string[i-1] == '!'){
                        if(string[i-2] != ' ' || string[i+1] != ' '){
                            return 1;
                        }
                    }

                    //Case ==
                    else if(string[i-1] == '='){

                        if(string[i+1] != ' ' || string[i-2] != ' '){
                            return 1;
                        }

                    }

                    //Case ==
                    else if(string[i+1] == '='){

                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }

                    }

                    else{

                        if(string[i-1] != ' ' || string[i+1] != ' '){
                            return 1;
                        }

                    }

                break;

                case '<' :

                    //Case <<
                    if(string[i+1] == '<'){

                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }
                    }

                    //Case <<
                    else if(string[i-1] == '<'){

                        if(string[i-2] != ' ' || string[i+1] != ' '){
                            return 1;
                        }
                    }

                    //Case <=
                    if(string[i+1] == '='){

                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }
                    }

                    else{

                        if(string[i-1] != ' ' || string[i+1] != ' '){
                            return 1;
                        }

                    }

                break;

                case '>' :

                    //Case >>
                    if(string[i+1] == '>'){

                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }
                    }

                    //Case >>
                    else if(string[i-1] == '>'){

                        if(string[i-2] != ' ' || string[i+1] != ' '){
                            return 1;
                        }
                    }


                    //Case >=
                    else if(string[i+1] == '='){

                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }
                    }

                    else{

                        if(string[i-1] != ' ' || string[i+1] != ' '){
                            return 1;
                        }

                    }

                break;

                case '!' :

                    //Case !=
                    if(string[i+1] == '='){

                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }
                    }

                    else{

                        if(string[i-1] != ' ' || string[i+1] != ' '){
                            return 1;
                        }

                    }

                break;


                case '&':

                    //Case &&
                    if(string[i-1] == '&'){

                        if(string[i-2] != ' ' || string[i+1] != ' '){
                            return 1;
                        }

                    }

                    //Case &&
                    if(string[i+1] == '&'){

                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }

                    }

                break;

                case '|':

                    //Case ||
                    if(string[i-1] == '|'){

                        if(string[i-2] != ' ' || string[i+1] != ' '){
                            return 1;
                        }

                    }

                    //Case ||
                    if(string[i+1] == '|'){

                        if(string[i-1] != ' ' || string[i+2] != ' '){
                            return 1;
                        }

                    }

                break;
            }

        }


    }while(!feof(file));

    return 0;

}
