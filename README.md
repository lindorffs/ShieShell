# ShieShell

ShieShell's a simple shell, shelling shells by the shelly shore.
It's more education than functional, and was written in less than
a day by following Stephen Brennan's brilliant tutorial:
https://brennan.io/2015/01/16/write-a-shell-in-c/

It's been expanded slightly to include a "enviroment variable",
which is the prompt, and has been spread out into a few different
files and directories. There's some other fun stuff going on, so
stick around it might get interesting?

Offers:

* Single line commands

* Whitespace seperated arguments

* No argument quotation, or escaping characters

* No piping, or redirection

* Enviroment variable (only prompt, but can be expanded quite easily)

* cd, help, exit, version, set, env



`cd - change directory. Takes one argument. That is the directory.`

`help - print help. Not very helpful at the moment.`

`exit - quits the shell safely.`

`version - displays current version info.`

`set - sets enviroment variable.`

`env - dumps current environment variables.`

## Installation

### Prerequisites

There are none! Short of the standard headers provided with most Linux
distributions, there's nothing fancy going on here. Yet. Maybe ncurses
at some point..... Possibility? Maybe.

### Building

Run the makefile. It should drop a binary named shieshell in the bin/
directory. If it doesn't, it likely didn't compile.

```
(user@host)[/home/user/shieshell]
--> make
make -C src/
make[1]: Entering directory '/home/user/shell/src'
gcc -I../include/   -c -o main.o main.c

	GCC Screaming and Yelling Here

gcc -o ../bin/shieshell main.o shell.o builtin/cd.o builtin/env.o builtin/set.o builtin/version.o -I../include/
make[1]: Leaving directory '/home/user/shell/src'
(user@host)[/home/user/shieshell]
--> ./bin/shieshell
ShieShell v.0.1.1
(user@host)[/home/user/shieshell]
--> env
prompt (\u@\h)[\d]\n-->
```

### Installing

If you really must, you can copy it yourself to wherever you want  it to be installted at.
It's not meant to really be used more than once or twice for funsies at this point.

# Okay, what can I do with it?

## The Prompt
This is the only customizable part right now.
sadly, due to the lack of " "able arguments, setting it is
a little limited. It's a good introduction to environment
variables however!

The `env` command will show the current prompt string.
```
(user@host)[/home/user/shieshell]
--> env
prompt (\u@\h)[\d]\n-->
```

It can be set using the `set` command, like so.
```
(user@host)[/home/user/shieshell]
--> set prompt [\u]{\d}\n-->
[user]{/home/user/shieshell}
--> env
prompt [\u]{\d}\n-->
```

There are four escapes available for the prompt.
`\u` is replaced with the current users name.
`\d` is replaced with the current working directory.
`\h` is replaced with the host name.
`\n` triggers a new line.

## Make It Better

It's not a whole lotta code. It's hopefully not too hard to read.

Expanding it could be fun, too! Think of a few things that you'd want,
try your hand at implementing if you want!

Perhaps we could create a better shell together via the awesome powers
of open-source collaboration! Or not.....


### Acknowledgments
https://github.com/brenns10/lsh

### Licensing
Ehh. You do you.

