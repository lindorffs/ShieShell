#include <stdio.h>

#include <builtin.h>
#include <shell.h>

int shVer(char **args) {
	printf("ShieShell v.%i.%i.%i\n", RELEASE_MAJOR, RELEASE_MINOR, RELEASE_TESTING);
	return 0;
}
