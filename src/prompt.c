#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "prompt.h"

void show_prompt() {
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    char *user = getenv("USER");
    if (!user) user = "user";

    printf("\033[1;32m[%s@Cmini\033[0m \033[1;34m%s\033[0m]$ ", user, cwd);
    fflush(stdout);
}
