# README for simple_shell :page_with_curl:

A simple Unix shell Project as part of the [Holberton School]
(https://holbertonschool.com.au/) Foundations curriculum for Low-Level Programming.

## Usage :clapper:
To use the shell, compile all files in the directory and run
```
shell
```

### Compilation
All files are compiled with gcc as follows:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

### Example
```
$ ./hsh
```

### Coding Style
All files are written in C programming language and follows the
[Betty coding style](https://github.com/holbertonschool/Betty/wiki).

## Description :open_book:
### File Description
- **AUTHORS:** lists contributors to this repository
- **_env.c:** function to print environment variables
- **_getenv.c:** function to get environment members
- **_strlen.c:** function to get string length
- **findpath.c:** function to find path of commands entered
- **flushargv.c:** function to set argv to NULL
- **fwe.c:** function to fork a child process
- **shell.c:** main function to run shell
- **shell.h:** header file containing all prototypes
- **builtins.c:** contains functions to handle built-ins

### Program Description
Our shell waits for input, takes the given string and compares it
with existing built-ins or commands. If the command exists, the program will
fork, wait and execute the built-in or command.

### Built-ins
- `env` : displays all environment variables
- `exit` : exits the process
- `cd` : changes directory

## Authors :pencil2:
- James Honey [[jashoney](https://github.com/jashoney)]
- Karoline Silva [[Karoline-S](https://github.com/Karoline-S)]
- Farah McCurdy [[farahmc](https://github.com/farahmc)]
