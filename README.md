# :page_with_curl: README for simple_shell :shell:

A simple Unix shell Project as part of the [Holberton School](https://holbertonschool.com.au/) Foundations curriculum for Low-Level Programming.

## Usage :clapper:
To use the shell, compile all .c files in the directory and run the executable.

### Compilation
All files are compiled with gcc as follows:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

### Example
```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
$ ./hsh
```

### Invocation :woman_technologist:
The shell can be invoked interactively and non-interactively.

### Coding Style :technologist:
All files are written in C programming language and follows the
[Betty coding style](https://github.com/holbertonschool/Betty/wiki).

## Description :speech_balloon:

### File Descriptions :floppy_disk:
- **AUTHORS:** lists contributors to this repository
- **_env.c:** function to print environment variables
- **_getenv.c:** function to get environment members
- **_strtok.c:** function to split string into tokens
- **buffstring_to_tokens.c:** splits buffer string into tokens
- **builtins.c:** function to handle built-ins
- **error_print.c:** function to print error messages
- **findpath.c:** function to find path of commands entered
- **fork_exec.c:** function to fork and execute process
- **help-cd:** help page for cd builtin
- **help-env:** help page for env builtin
- **help-exit:** help page for exit builtin
- **help-getenv:** help page for getenv builtin
- **help-help:** help page for help builtin
- **help-setenv:** help page for setenv builtin
- **help.c:** function to handle help page builtins
- **man_1_simple_shell:** manual for simple shell
- **processinput.c:** function to process entered input
- **prompt_read.c:** function to read entered input
- **shell.c:** main function to run shell
- **shell.h:** header file containing all prototypes
- **stringfuncs.c:** funtion to manipulate strings

### Program Description :computer:
The shell reads the given input and splits it into tokens if the input is more
than one word. The first word is recognised as the command and any additional
words are recognised as arguments to the command. The shell then performs the
following:

1. Compares to a list of built-ins. If the word matches a built-in, the
corresponding function is executed. A new line with `$` follows the
execution, waiting for a new command (unless the `exit` function is run,
which exits the parent process).

2. Checks if the first word starts with a `/`. If it starts with a
`/`, the shell goes directly to the path (all the characters following the
`/` and before the delimiter (space) and executes the command. If the path
is not found, an error message is displayed.

3. If the word does not start with a `/`, the shell lists all paths,
splits the string into tokens with delimiter `:` and concatenates the
command onto the end of each directory to find an existing executable. If the
executable is found, the shell forks into a child process and executes the
command along with any arguments. A new line with `$` follows the executed
command, and waits for a new command.

### Built-ins :battery:
- `cd` : changes directory
- `env` : displays all environment variables
- `exit` : exits the process
- `help` : displays a help page for builtins in stdout
- `setenv` : adds a variable name to the environment
- `unsetenv` : removes the variable name from the environment

### Signals :triangular_flag_on_post:
In interactive mode, **hsh** will terminate the child process upon entering
`Ctrl + C` and terminate the parent process upong entering `Ctrl + D`.

### Exit Status :wave:
**hsh** exits with a return of 0.

## Authors :pencil2:
- James Honey [[jashoney](https://github.com/jashoney)]
- Karoline Silva [[Karoline-S](https://github.com/Karoline-S)]
- Farah McCurdy [[farahmc](https://github.com/farahmc)]
