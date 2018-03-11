#include "apue.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    if (open("tempfile", O_RDWR) < 0)
        err_sys("open error");
    
    if (unlink("tempfile") < 0)
        err_sys("unlink error");
    
    printf("file unlinked\n");
    sleep(15);
    printf("done\n");

    return 0;
}