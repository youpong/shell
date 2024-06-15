#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdnoreturn.h>

noreturn static void execute(int);

int main(void) {
    pid_t pid;
    int status;
    int fd[2];

    if (pipe(fd) < 0)
        err_sys("pipe error");

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) { // child
        close(fd[0]);
        execute(fd[1]);
    }

    // parent
    close(fd[1]);
    FILE *f = fdopen(fd[0], "r");
    if (f == NULL)
        err_sys("fdopen error");
    for(int c; (c = fgetc(f)) != EOF;) {
        fputc(c, stdout);
    }

    if ((pid = waitpid(pid, &status, 0)) < 0)
        err_sys("waitpid error");
    return 0;
}

noreturn static void execute(int fd)
{
    char exec_file[BUFSIZ];
    char arg1[BUFSIZ];

    dup2(fd, fileno(stdout));

    strcpy(exec_file, "date");
    strcpy(arg1, "-R");
    execlp(exec_file, exec_file, arg1, (char *)0);

    close(fd);
    err_ret("couldn't execute: %s", exec_file);
    exit(127);
}
