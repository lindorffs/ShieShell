#include <stdio.h>

#include <builtin.h>
#include <shell.h>

int shShowEnv(char** args) {
	int i;
	for (i = 0; i < envLength; i++) {
		printf("%07s %07s\n",env[i].name, env[i].val);
	}
}
