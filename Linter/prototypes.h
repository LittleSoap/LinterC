#define DEFAULT_CONF "default.lconf"

//Part 1
void openConfFile();
int readConfFile(FILE * defaultFile);
void read_function_parameters (int ** rules, char * LineRead, int index);


//Functions part 2
int max_file_line_number(int n, char* test);
int max_line_numbers(int n, char * test);
int comma_spacing(char * test);
int array_bracket_eol(char *test);
int operators_spacing(char * test);
int indent(int n, char * test);
int comments_header(char * test);


//Utilitaries
void printArray2D(char ** tab, int counter);
char * my_flush(char * test);

