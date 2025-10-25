#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "executor.h"
#include "builtins.h"

void execute_command(char **args) {
    if (args[0] == NULL) return;

    if (handle_builtin(args))
        return;

    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1)
            perror("Command failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        waitpid(pid, NULL, 0);
    } else {
        perror("fork failed");
    }
}
