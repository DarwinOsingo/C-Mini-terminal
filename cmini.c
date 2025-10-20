#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

void execute(char *input) {
    char *args[MAX_ARGS];
    char *token = strtok(input, " \n");
    int i = 0;

    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;

    if (args[0] == NULL) return; // empty input

    if (strcmp(args[0], "exit") == 0) {
        printf("Goodbye.\n");
        exit(0);
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Command failed");
        }
        exit(1);
    } else if (pid > 0) {
        // Parent waits
        waitpid(pid, NULL, 0);
    } else {
        perror("fork failed");
    }
}

int main() {
    char input[MAX_INPUT];

    while (1) {
        printf("Cmini> ");
        fflush(stdout);

        if (!fgets(input, sizeof(input), stdin))
            break;

        execute(input);
    }

    return 0;
}
