#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char buf[BUFSIZ];

    strcpy(buf, "date");
    execlp(buf, buf, (char *)0);
    err_ret("couldn't execute: %s", buf);
    exit(127);

    return 0;
}
