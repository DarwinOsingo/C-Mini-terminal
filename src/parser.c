#include <string.h>
#include "parser.h"

int parse_input(char *input, char **args) {
    char *token = strtok(input, " \t\n");
    int i = 0;

    while (token && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
    return i;
}
