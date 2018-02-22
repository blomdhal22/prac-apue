#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

extern void set_fl(int fd, int flags);

int main(void)
{
    char buf[2048];
    int n;

    set_fl(STDIN_FILENO, O_SYNC);

    while ((n = read(STDIN_FILENO, buf, 2048)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            perror("write error");
            exit(1);
        }
    }

    if (n < 0)
        perror("read error");

    return 0;
}