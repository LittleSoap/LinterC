#define DEFAULT_CONF "default.lconf"

FILE* openConfFile();
FILE* createConfFile();
char* readConfFile(FILE * defaultFile, char* LineRead);
int writeConfFile(FILE* defaultConfFile);

//Functions part 2
int max_file_line_number(int n, char* test);
int max_line_numbers(int n, char * test);
int comma_spacing(char * test);
int array_bracket_eol(char *test);
int operators_spacing(char *test);
int indent(int n, char * test);
