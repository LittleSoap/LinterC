#define DEFAULT_CONF "default.lconf"

FILE* openConfFile();
FILE* createConfFile();
char* readConfFile(FILE * defaultFile, char* LineRead);
int writeConfFile(FILE* defaultConfFile);
