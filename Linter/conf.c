#include "header.h"

void openConfFile(){

    FILE* defaultFile = fopen(DEFAULT_CONF,"r");

    if(defaultFile == NULL){
        printf("Can't open default conf file\n");
    }

    int valueConf = readConfFile(defaultFile);
    if(valueConf != 0){
        printf("Error in configuration file\n");
    }




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
        return -1;
    }

    LineRead = malloc(sizeof(char)*255);
    extend = malloc(sizeof(int) * 255);
    rules = malloc(sizeof(int) * 255);
    excluded_files = malloc(sizeof(int) * 255);

    do{

        fgets(LineRead, 255, defaultFile);

        //extends

        int i =0;

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
                }else if(index == -1){
                    printf("Rules doesn't exist");
                    return -1;
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


    int is_call = call_function(extend, rules, excluded_files, counter_extend, counter_excluded, is_recursive);
    if(is_call == 1){
        printf("error");
    }

    return 0;

}

int call_function(char ** extend, int ** rules, char ** excluded_files, int counter_extend, int counter_excluded, int is_recursive){
    /*int i;
    for(i=0; i<15; i++){
        printf("%d   ", rules[i][0]);
    }*/
    int result;
    if((rules[0][0]) == 1){
         printf("array_bracket_eol\n");
         result = array_bracket_eol("testfunction/array_bracket_eol.txt");
         printf("%d\n", result);
    }
    if((rules[1][0]) == 1){
         printf("operators_spacing\n");
         result = operators_spacing("testfunction/operators_spacing.txt");
         printf("%d\n", result);
    }
    if((rules[2][0]) == 1){
         printf("comma_spacing\n");
         result = comma_spacing("testfunction/comma_spacing.txt");
         printf("%d\n", result);
    }
    if((rules[3][0]) > 1){
         printf("indent\n");
         result = indent(rules[3][0], "testfunction/indent.txt");
         printf("%d\n", result);
    }
    if((rules[4][0]) == 1){
         printf("comments_header\n");
         result = comments_header("testfunction/comments_header.txt");
         printf("%d\n", result);
    }
    if((rules[5][0]) > 1){
         printf("max_line_numbers\n");
         result = max_line_numbers(rules[5][0], "testfunction/max_line_numbers.txt");
         printf("%d\n", result);
    }
    if((rules[6][0]) > 1){
         printf("max_file_line_number\n");
         result = max_file_line_number(rules[6][0], "testfunction/max_file_line_number.txt");
         printf("%d\n", result);
    }
    /*if((rules[7][0]) == 1){
         printf("no_trailing_spaces\n");
         no_trailing_spaces("testfunction/no_trailing_spaces.txt");
    }*/
    if((rules[8][0]) == 1){
         printf("no_multi_declaration\n");
         result = no_multi_declaration("testfunction/no_multi_declaration.txt");
         printf("%d\n", result);
    }
    /*if((rules[9][0]) == 1){
         printf("unused_variable\n");
         unused_variable("testfunction/unused_variable.txt");
    }
    if((rules[10][0]) == 1){
         printf("undeclared_variable\n");
         undeclared_variable("testfunction/undeclared_variable.txt");
    }
    if((rules[11][0]) == 1){
         printf("no_prototype\n");
         no_prototype("testfunction/no_prototype.txt");
    }
    if((rules[12][0]) == 1){
         printf("unused_function\n");
         unused_function("testfunction/unused_function.txt");
    }
    if((rules[13][0]) == 1){
         printf("undeclared_function\n");
         undeclared_function("testfunction/undeclared_function.txt");
    }
    if((rules[14][0]) == 1){
         printf("variable_assignment_type\n");
         variable_assignment_type("testfunction/variable_assignment_type.txt");
    }
    if((rules[15][0]) == 1){
         printf("function_parameters_type\n");
         function_parameters_type("testfunction/function_parameters_type.txt");
    }*/
    return 0;
}



