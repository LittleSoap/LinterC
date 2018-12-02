#include "header.h"


int main(int argc, char * * argv){


    int error = operators_spacing("test.txt");

    if(error == 1){
        printf("error");
    }else if(error == 0){
        printf("pas d'erreur");
    }

    int a = 1;


    return 0;
}
