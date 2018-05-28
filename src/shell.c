#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <pwd.h>

#include <shell.h>
#include <builtin.h>

// Shell Function Declarations
char *getInput() {
        int bufsize = BUFFER_SIZE;
        int position = 0;
        char *buffer = malloc(sizeof(char) * bufsize);
        int c;

        if (!buffer) {
                printErr("Buffer allocation error.", 0);
                exit(EXIT_FAILURE);
        }

        while (1) {
                c = getchar();

                if (c == EOF || c == '\n') {
                        buffer[position] = '\0';
                        return buffer;
                } else {
                        buffer[position] = c;
                }
                position++;

                if (position >= bufsize) {
                        bufsize += BUFFER_SIZE;
                        buffer = realloc(buffer, bufsize);
                        if (!buffer) {
                                printErr("Buffer allocation error.", 0);
                                exit(EXIT_FAILURE);
                        }
                }
        }
}

char **getArgs(char* input) {
        int bufsize = ARG_BUFFER_SIZE, position = 0;
	int c;
	enum states { DULL, IN_WORD, IN_STRING } state = DULL;
        char **arguments = malloc(bufsize * sizeof(char*));
        char *argument;
	char *p, start_of_arg;

        if (!arguments) {
                printErr("Buffer allocation error.", 0);
                exit(EXIT_FAILURE);
        }

        argument = strtok(input, ARG_DELIM);

        while (argument != NULL) {
                arguments[position] = argument;
                position++;

                if (position >= bufsize) {
                        bufsize += ARG_BUFFER_SIZE;
                        arguments = realloc(arguments, bufsize * sizeof(char*));
                        if (!arguments) {
                                printErr("Buffer allocation error.", 0);
                                exit(EXIT_FAILURE);
                        }
                }
                argument = strtok(NULL, ARG_DELIM);
        }
        arguments[position] = NULL;
        return arguments;
}

int parse(char **args) {
        int i;
        if (args[0] == NULL) {
                return 1;
        }

        for (i = 0; i < numBuiltin; i++) {
                if (strcmp(args[0],builtin_names[i]) == 0) {
                        return (*builtin_func[i])(args);
                }
        }

        return launch(args);
}

int launch(char** args) {
        pid_t pid, wpid;
        int ret;

        pid = fork();
        if (pid == 0) {
                if (execvp(args[0],args) == -1) {
                        perror("ShieShell");
                }
                exit(EXIT_FAILURE);
        } else if (pid < 0) {
                perror("ShieShell");
		ret = 0;
        } else {
                do {
                        wpid = waitpid(pid, &ret, WUNTRACED);
                } while (!WIFEXITED(ret) && !WIFSIGNALED(ret));
        }
	return ret;
}

void printErr(char* error, int level) {
        fprintf(stderr, "ShieShell %sError: %s\n", level == 0 ? "Fatal " : "", error);
}

void printPrompt(void) {
	char *prompt = env[0].val, *uname, hname[64], directory[256];
	struct passwd *pass;
	int i;
	for (i = 0; i < strlen(prompt); i++) {
		if (prompt[i] == '\\') {
			switch(prompt[++i]) {
				case 'u':
					pass = getpwuid(getuid());
					uname = pass->pw_name;
					printf("%s",uname);
					break;
				case 'd':
					getcwd(directory, sizeof(directory));
					printf("%s",directory);
					break;
				case 'h':
					gethostname(hname, sizeof(hname));	
					printf("%s",hname);
					break;
				case 'n':
					printf("\n");
					break;
				default:
					break;
			}	
		} else {
			printf("%c",prompt[i]);
		}
	}
};

var *getEnvVar(char *name) {
	int i;
	for (i = 0; i < envLength; i++) {
		if (strcmp(env[i].name,name)==0) {
			return &env[i];
		}
	}
	return NULL;
}
