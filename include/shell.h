#ifndef _SHELL_H_
#define _SHELL_H_

#define RELEASE_MAJOR 0
#define RELEASE_MINOR  1
#define RELEASE_TESTING 1

#define BUFFER_SIZE 1024
#define ARG_BUFFER_SIZE 64
#define ARG_DELIM " \t\r\n\a"

struct var {
	char *name;
	char *val;
};

typedef struct var var;

// Shell Function Declarations
char *getInput(void);
char **getArgs(char*);
int parse(char**);
int launch(char**);
void printPrompt(void);
void printErr(char*, int);
var *getEnvVar(char*);

var env[];
int envLength;
int run;

#endif
