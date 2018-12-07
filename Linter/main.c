#include "header.h"


int main(int argc, char ** argv){


    //openConfFile();

    FILE* file = fopen("main.c", "r");
    int error = comments_header(file);
    printf("%d" , error);

    return 0;
}
