#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "builtins.h"

int handle_builtin(char **args) {
    if (strcmp(args[0], "exit") == 0) {
        printf("Goodbye.\n");
        exit(0);
    }

    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL)
            fprintf(stderr, "cd: missing argument\n");
        else if (chdir(args[1]) != 0)
            perror("cd failed");
        return 1;
    }

    if (strcmp(args[0], "clear") == 0) {
        printf("\033[H\033[J");
        return 1;
    }

    if (strcmp(args[0], "help") == 0) {
        printf("Cmini Terminal v1.0 built-in commands:\n");
        printf("  cd <dir>    - change directory\n");
        printf("  clear       - clear the screen\n");
        printf("  help        - show this help menu\n");
        printf("  exit        - exit the terminal\n");
        return 1;
    }

    return 0; // Not a builtin
}
