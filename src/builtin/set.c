#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <builtin.h>
#include <shell.h>

int shSet(char **args) {
	var *set;
	if (args[1] == NULL) {
		fprintf(stderr,"Set what!?\n");
		return 1;
	} else if (args[2] == NULL) {
		fprintf(stderr,"Set %s to what!?\n", args[1]);
		return 1;
	}
	set = getEnvVar(args[1]);	
	if (set == NULL) {
		env[envLength+1].name = args[1];
		envLength += 1;
	} else {
		set->val = args[2];
	}
}
