#define DEFAULT_CONF "default.lconf"

//Part 1
void openConfFile();
void readConfFile(FILE * defaultFile);

//Functions part 2
int max_file_line_number(int n, char* test);
int max_line_numbers(int n, char * test);
int comma_spacing(char * test);
int array_bracket_eol(char *test);
int operators_spacing(char * test);
int indent(int n, char * test);


//Utilitaries
void printArray2D(char ** tab, int counter);
void freeArray2D(char ** tab);
char * my_flush(char * test);
