#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char exec_file[BUFSIZ];
    char arg1[BUFSIZ];

    char* filename = "output";
    FILE* f = fopen(filename, "w");
    if (!f) {
        err_ret("couldn't open file: %s", filename);
    }
    dup2(fileno(f), fileno(stdout));

    strcpy(exec_file, "date");
    strcpy(arg1, "-R");
    execlp(exec_file, exec_file, arg1, (char *)0);
    fclose(f);
    err_ret("couldn't execute: %s", exec_file);
    exit(127);

    return 0;
}
