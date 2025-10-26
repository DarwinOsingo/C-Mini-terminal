#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "executor.h"
#include "prompt.h"
#include "signals.h"
#include "utils.h"

#define MAX_INPUT 1024

int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    setup_signals();

    printf("Welcome to Cmini Terminal v1.0\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        show_prompt();

        if (!fgets(input, sizeof(input), stdin))
            break;

        trim_newline(input);

        if (strlen(input) == 0)
            continue;

        parse_input(input, args);
        execute_command(args);
    }
    

    return 0;
}
