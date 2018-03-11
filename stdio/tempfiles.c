#include "apue.h"
#include <stdio.h>

int main(void)
{
    char name[L_tmpnam], line[MAXLINE];
    FILE *fp;

    /* first temp name */
    printf("%s\n", tmpnam(NULL));

    /* second temp name */
    tmpnam(name);
    printf("%s\n", name);

    if ((fp = tmpfile()) == NULL)
        err_sys("tmpfile error");
    
    /* write to temp file */
    fputs("one line of output\n", fp);
    fputs("good morning\n", fp);

    /* then read it back */
    rewind(fp);

    while ((fgets(line, sizeof(line), fp)) != NULL)
        printf("%s", line);

/*
    if (fgets(line, sizeof(line), fp) == NULL)
        err_sys("fgets error");
    
    puts(line);
*/
    return 0;
}