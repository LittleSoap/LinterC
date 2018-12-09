#include "header.h"


int max_file_line_number(int n, char * file_function){

    FILE* file = fopen(file_function, "r");

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


int max_line_numbers(int n, char * file_function){

    FILE* file = fopen(file_function, "r");

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


int comma_spacing(char * file_function){

    FILE* file = fopen(file_function, "r");

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


int array_bracket_eol(char *file_function){

    FILE* file = fopen(file_function, "r");

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

int indent(int n, char * file_function){

    FILE* file = fopen(file_function, "r");

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

int comments_header(char * file_function){

    FILE* file = fopen(file_function, "r");

    if(file == NULL){
        printf("Impossible d'ouvrir le fichier");
        return -1;
    }

    char c;

    c = fgetc(file);
    if(c == '/'){
        c = fgetc(file);
        if(c == '*'){
            while(!feof(file)){
                c = fgetc(file);
                if(c == '*' && ((c = fgetc(file)) == '/')){
                    return 0;
                }
            }
            return 1;
        }else{
            return 1;
        }
    }else{
        return 1;
    }
}

int operators_spacing(char * file_function){


    FILE* file = fopen(file_function, "r");

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

int no_multi_declaration(char * file_function){

    FILE* file = fopen(file_function, "r");

    if(file == NULL){
        printf("Impossible d'ouvrir le fichier");
        return -1;
    }
    char c;

    c = fgetc(file);
    while(!feof(file)){
        if(c != '('){
            //int
            if(c == 'i'){
                c = fgetc(file);
                if(c == 'n'){
                    c = fgetc(file);
                    if(c == 't'){
                        c = fgetc(file);
                        while(c != ';' || c == '{'){
                            if(c == '('){
                                break;
                            }else if(c == ','){
                                return 1;
                            }else{
                                c = fgetc(file);
                            }
                        }
                    }
                }
            }
            //char
            if(c == 'c'){
                c = fgetc(file);
                if(c == 'h'){
                    c = fgetc(file);
                    if(c == 'a'){
                        c = fgetc(file);
                        if(c == 'r'){
                            c = fgetc(file);
                            while(c != ';' || c == '{'){
                                if(c == '('){
                                    break;
                                }else if(c == ','){
                                    return 1;
                                }else{
                                    c = fgetc(file);
                                }
                            }
                        }
                    }
                }
            }
            //float
            if(c == 'f'){
                c = fgetc(file);
                if(c == 'l'){
                    c = fgetc(file);
                    if(c == 'o'){
                        c = fgetc(file);
                        if(c == 'a'){
                            c = fgetc(file);
                            if(c == 't'){
                                c = fgetc(file);
                                while(c != ';' || c == '{'){
                                    if(c == '('){
                                        break;
                                    }else if(c == ','){
                                        return 1;
                                    }else{
                                        c = fgetc(file);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            //double
            if(c == 'd'){
                c = fgetc(file);
                if(c == 'o'){
                    c = fgetc(file);
                    if(c == 'u'){
                        c = fgetc(file);
                        if(c == 'b'){
                            c = fgetc(file);
                            if(c == 'l'){
                                c = fgetc(file);
                                if(c == 'e'){
                                    c = fgetc(file);
                                    while(c != ';' || c == '{'){
                                        if(c == '('){
                                            break;
                                        }else if(c == ','){
                                            return 1;
                                        }else{
                                            c = fgetc(file);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            //short
            if(c == 's'){
                c = fgetc(file);
                if(c == 'h'){
                    c = fgetc(file);
                    if(c == 'o'){
                        c = fgetc(file);
                        if(c == 'r'){
                            c = fgetc(file);
                            if(c == 't'){
                                c = fgetc(file);
                                while(c != ';' || c == '{'){
                                    if(c == '('){
                                        break;
                                    }else if(c == ','){
                                        return 1;
                                    }else{
                                        c = fgetc(file);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            //unsigned
            if(c == 'u'){
                c = fgetc(file);
                if(c == 'n'){
                    c = fgetc(file);
                    if(c == 's'){
                        c = fgetc(file);
                        if(c == 'i'){
                            c = fgetc(file);
                            if(c == 'g'){
                                c = fgetc(file);
                                if(c == 'n'){
                                    c = fgetc(file);
                                    if(c == 'e'){
                                        c = fgetc(file);
                                        if(c == 'd'){
                                            c = fgetc(file);
                                            while(c != ';' || c == '{'){
                                                if(c == '('){
                                                    break;
                                                }else if(c == ','){
                                                    return 1;
                                                }else{
                                                    c = fgetc(file);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            //long
            if(c == 'l'){
                c = fgetc(file);
                if(c == 'o'){
                    c = fgetc(file);
                    if(c == 'n'){
                        c = fgetc(file);
                        if(c == 'g'){
                            c = fgetc(file);
                            while(c != ';' || c == '{'){
                                if(c == '('){
                                    break;
                                }else if(c == ','){
                                    return 1;
                                }else{
                                    c = fgetc(file);
                                }
                            }
                        }
                    }
                }
            }
            c = fgetc(file);
        }
    }
    return 0;

}

void read_function_parameters (int ** rules, char * LineRead, int index ){

    int i = 0;

    rules[index] = malloc(sizeof(int));
    char * substring = malloc(sizeof(char) * 255);

    int l;
    for (l=0; l< (strlen(LineRead) -1); l++){

        if(LineRead[l] == '=' && LineRead[l+1] == ' '){
            l+= 2;
            do{
                substring[i] = LineRead[l];
                i++;
                l++;
            }while(LineRead[l] != '\n' );

            substring[i] = '\0';
        }

    }

    if((strcmp(substring, "off")) == 0){
        rules[index][0] = 0;
    }else if((strcmp(substring, "on")) == 0){
        rules[index][0] = 1;
    }else{
        rules[index][0] = atoi(substring);
    }

    free(substring);

}
