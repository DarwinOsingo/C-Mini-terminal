#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sigint_handler(int sig) {
    printf("\nUse 'exit' to quit.\n");
    printf("Cmini> ");
    fflush(stdout);
}

void setup_signals() {
    signal(SIGINT, sigint_handler);
}
