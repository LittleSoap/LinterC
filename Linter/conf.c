#include "header.h"

void openConfFile(){

    FILE* defaultFile = fopen(DEFAULT_CONF,"r");

    if(defaultFile == NULL){
        printf("Can't open default conf file");
        return NULL;
    }

    readConfFile(defaultFile);



}


int readConfFile(FILE * defaultFile){

    char ** extend;
    int ** rules;
    int is_recursive;
    char ** excluded_files;
    char * LineRead;
    int counter_extend =0;
    int counter_excluded = 0;
    int counter_rules = 0;


    if(defaultFile == NULL){
        return NULL;
    }

    LineRead = malloc(sizeof(char)*255);
    extend = malloc(sizeof(int) * 255);
    rules = malloc(sizeof(int) * 255);
    excluded_files = malloc(sizeof(int) * 255);

    do{

        fgets(LineRead, 255, defaultFile);

        //extends

        int i =0;
        int counter = 0;

        if(strcmp(LineRead , "=extends\n") == 0){

            while(strcmp(LineRead, "\n") != 0 ){


                fgets(LineRead, 255, defaultFile);
                extend[i] = malloc(sizeof(char) * (strlen(LineRead) +1 ));

                int j;

                for(j=0; j < (strlen(LineRead)); j++){

                    extend[i][j] = LineRead[j];

                    if(extend[i][j] == '\n'){
                        extend[i][j] = '\0';
                    }
                }

                i++;
                counter_extend++;

            }




        }


        //rules

        i = 0;
        int index = -1;

        /*

            0 : array-bracket-eol
            1 : operators-spacing
            2 : comma-spacing
            3 : indent
            4 : comments-header
            5 : max-line-numbers
            6 : max-file-line-numbers
            7 : no-trailing-spaces
            8 : no-multi-declaration
            9 : unused-variable
            10 : undeclared-variable
            11 : no-prototype
            12 : unused-function
            13 : undeclared-function
            14 : variable-assignment-type
            15 : function-parameters-type


        */

        if(strcmp(LineRead , "=rules\n") == 0){

                counter_rules =0;

            /*

            1) - nom_fonction
            2) Dans rules on se place à l'indice de la fonction correspondante
            3) fseek : on se place sur le procahin =
            4)

            */

            while(strcmp(LineRead, "\n") != 0 ){

                fgets(LineRead, 255, defaultFile);

                if(strstr(LineRead, "array_bracket_eol")){
                    index = 0;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;

                }else if(strstr(LineRead, "operators_spacing")){
                    index = 1;
                    read_function_parameters (rules, LineRead, index);
                    counter_rules++;

                }else if(strstr(LineRead, "comma_spacing")){
                    index = 2;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;

                }else if(strstr(LineRead, "indent")){
                     index = 3;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;

                }else if(strstr(LineRead, "comments_header")){
                    index = 4;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;

                }else if(strstr(LineRead, "max_line_numbers")){
                    index = 5;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;
                }else if(strstr(LineRead, "max_file_line_number")){
                    index = 6;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;

                }else if(strstr(LineRead, "no_trailing_spaces")){
                    index = 7;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;

                }else if(strstr(LineRead, "no_multi_declaration")){
                    index = 8;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;

                }else if(strstr(LineRead, "unused_variable")){
                    index = 9;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;

                }else if(strstr(LineRead, "undeclared_variable")){
                    index = 10;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;

                }else if(strstr(LineRead, "no_prototype")){
                    index = 11;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;
                }else if(strstr(LineRead, "unused_function")){
                    index = 12;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;

                }else if(strstr(LineRead, "undeclared_function")){
                    index = 13;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;

                }else if(strstr(LineRead, "variable_assignment_type")){
                    index = 14;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;

                }else if(strstr(LineRead, "function_parameters_type")){
                    index = 15;
                    read_function_parameters (rules, LineRead,index);
                    counter_rules++;
                }

            }


        }


        //excludedFiles

        i=0;
        counter_excluded =0;

        if(strcmp(LineRead , "=excludedFiles\n") == 0){

            while(strcmp(LineRead, "\n") != 0 ){


                fgets(LineRead, 255, defaultFile);
                excluded_files[i] = malloc(sizeof(char) * (strlen(LineRead) +1 ));

                int j;

                for(j=0; j < (strlen(LineRead)); j++){

                    excluded_files[i][j] = LineRead[j];

                    if(excluded_files[i][j] == '\n'){
                        excluded_files[i][j] = '\0';
                    }
                }

                i++;
                counter_excluded++;
            }

        }

        //recursive

        if(strcmp(LineRead , "=recursive\n") == 0){

            fgets(LineRead, 255, defaultFile);

                if(strcmp(LineRead , "true") == 0){
                    is_recursive = 1;
                }else if(strcmp(LineRead , "false") == 0){
                    is_recursive = 0;
                }else{
                    is_recursive = -1;
                }

        }


    }while(!feof(defaultFile));

    printf(" recursive : %d\n", is_recursive);
    free(LineRead);

    return 0;

}
