#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include <shell.h>
#include <builtin.h>

#define RELEASE_MAJOR 0
#define RELEASE_MINOR  1
#define RELEASE_TESTING 1

// Main Function Declarations
void config(void);
void shell(int, char**);
void cleanup(void);

// Environment variables
var env[] = {
	{ "prompt", "" }
};

envLength = sizeof(env) / sizeof(var);

// Builtin Shell Commands
char *builtin_names[] = {
	"cd",
	"help",
	"version",
	"exit",
	"set",
	"env"
};

// Bultin Shell Command Functions
int (*builtin_func[]) (char **) = {
	&shChdir,
	&shHelp,
	&shVer,
	&shExit,
	&shSet,
	&shShowEnv
};

const int numBuiltin = sizeof(builtin_names) / sizeof(char *);

// Main Function Definitions
int main(int argc, char **argv) {
	config();

	shell(argc, argv);

	cleanup();	
	return EXIT_SUCCESS;
}

void config(void) {
	// do config things here
	getEnvVar("prompt")->val = "(\\u@\\h)[\\d]\\n--> ";

	// An int controls our running,
	// this way it can be toggled from a variety
	// of places. Eventually like a signal handler
	// to allow for a safe ctrl-c exit when it gets
	// to the point of actually needing to clean
	// things up.
	run = 1;
}

void shell(int argc, char **argv) {
	// do shell things here
	char *input;
	char **args;
	int ret;

	shVer(NULL);
	do {
		printPrompt();
		input = getInput();
		args = getArgs(input);
		ret = parse(args);

		free(input);
		free(args);
	} while (run != 0);
}

void cleanup(void) {
	// do cleanup here
}
// Builtin Shell Command Funtions

int shHelp(char **args) {
	int i;

	printf("ShieShell\n");
	printf("A basic shell, written in C.");
	printf("Builtin commands include the following.\n");
	for (i = 0; i < numBuiltin; i++) {
		printf("     %s\n", builtin_names[i]);
	}
	printf("Use man for help on other programs.\n");
	return 0;
}

int shExit(char **args) {
	run = 0;
}
