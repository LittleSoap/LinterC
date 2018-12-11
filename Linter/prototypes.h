#define DEFAULT_CONF "default.lconf"

//Part 1
void openConfFile();
int readConfFile(FILE * defaultFile);
void read_function_parameters (int ** rules, char * LineRead, int index);
int call_function(char ** extend, int ** rules, char ** excluded_files, int counter_extend, int counter_excluded, int is_recursive);


//Functions part 2
int max_file_line_number(int n, char* test);
int max_line_numbers(int n, char * test);
int comma_spacing(char * test);
int array_bracket_eol(char *test);
int operators_spacing(char * test);
int indent(int n, char * test);
int comments_header(char * test);

//Functions part 3
int no_multi_declaration(char * test);

//Utilitaries
void printArray2D(char ** tab, int counter);
char * my_flush(char * test);
