#include "apue.h"
#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
        err_quit("Usage: ls1 <dir>");
    
    dp = opendir(argv[1]);
    if (dp == NULL)
        err_sys("can't open %s", argv[1]);
    
    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);

    return 0;
}