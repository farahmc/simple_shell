# README for simple_shell :page_with_curl: :shell:

A simple Unix shell Project as part of the [Holberton School](https://holbertonschool.com.au/) Foundations curriculum for Low-Level Programming.

## Usage :clapper:
To use the shell, compile all .c files in the directory and run the executable.

### Compilation
All files are compiled with gcc as follows:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell`

### Example
```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
$ ./shell
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
- **findpath.c:** function to find path of commands entered
- **fork_exec.c:** function to fork and execute process
- **help-cd:** help page for cd builtin
- **help-env:** help page for env builtin
- **help-exit:** help page for exit builtin
- **help-help:** help page forhelp builtin
- **help.c:** function to handle help page builtins
- **man_1_simple_shell:** manual for simple shell
- **processinput.c:** function to process entered input
- **prompt_read.c:** function to read entered input
- **shell.c:** main function to run shell
- **shell.h:** header file containing all prototypes
- **stringfuncs.c:** funtion to manipulate strings

### Program Description :computer:
Our shell waits for input, takes the given string and compares it
with existing built-ins or commands. If the command exists, the program will
fork into a child process and execute the function.

### Built-ins :battery:
- `cd` : changes directory
- `env` : displays all environment variables
- `exit` : exits the process
- `help` : displays a help page for builtins in stdout
- `getenv` : searches and points to an environment variable
- `setenv` : adds a variable name to the environment

### Signals :triangular_flag_on_post:
In interactive mode, `shell` ignores the input `Ctrl + C`, and will exit the
program with `Ctrl + D`.

### Exit Status :wave:
`shell` returns the exit status of the last command exeuted, with `0` indicating
success any other number indicating failure.

## Authors :pencil2:
- James Honey [[jashoney](https://github.com/jashoney)]
- Karoline Silva [[Karoline-S](https://github.com/Karoline-S)]
- Farah McCurdy [[farahmc](https://github.com/farahmc)]
