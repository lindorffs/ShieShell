#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

#include <builtin.h>
#include <shell.h>

int shChdir(char **args) {
        if (args[1] == NULL) {
			fprintf(stderr,"Invalid argument\n");
        } else {
                if (chdir(args[1]) != 0) {
                        perror("ShieShell");
			printf("%s\n",args[1]);
                } else {
		}
        }
        return 1;
}

