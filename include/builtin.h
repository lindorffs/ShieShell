#ifndef _BUILTIN_H_
#define _BUILTIN_H_

// Builtin Shell Commands
char *builtin_names[];
// Bultin Shell Command Functions
int (*builtin_func[]) (char **);

const int numBuiltin;

int shChdir(char**);
int shVer(char**);
int shHelp(char**);
int shExit(char**);
int shSet(char**);
int shShowEnv(char **);

#endif
