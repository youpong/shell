#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdnoreturn.h>

noreturn static void execute(FILE* f);

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;

    char *filename = "output";
    FILE *f = fopen(filename, "w");
    if (!f)
    {
        err_ret("couldn't open file: %s", filename);
    }

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) { // child
        execute(f);
    }

    // parent
    if ((pid = waitpid(pid, &status, 0)) < 0)
        err_sys("waitpid error");
    fclose(f);    
    return 0;
}

noreturn static void execute(FILE *f)
{
    char exec_file[BUFSIZ];
    char arg1[BUFSIZ];

    dup2(fileno(f), fileno(stdout));

    strcpy(exec_file, "date");
    strcpy(arg1, "-R");
    execlp(exec_file, exec_file, arg1, (char *)0);

    fclose(f);
    err_ret("couldn't execute: %s", exec_file);
    exit(127);
}
