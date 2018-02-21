#include "apue.h"
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char* argv[])
{
    char buff[BUFFER_SIZE];
    int n;

    while ((n = read(STDIN_FILENO, buff, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buff, n) != n)
            err_sys("write error");
    }

    if (n < 0)
        err_sys("read error");

    return 0;
}