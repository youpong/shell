#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char buf[BUFSIZ];

    char* filename = "output";
    FILE* f = fopen(filename, "w");
    if (!f) {
        err_ret("couldn't open file: %s", filename);
    }
    dup2(fileno(f), fileno(stdout));

    strcpy(buf, "date");
    execlp(buf, buf, (char *)0);
    err_ret("couldn't execute: %s", buf);
    exit(127);

    return 0;
}
