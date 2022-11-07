#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{   /* fork a child process */
    int pid = fork();
    if (!pid)
        printf("Child process\n");

    /* fork another child process */
    fork();
    /* and fork another */
    fork();
    return EXIT_SUCCESS;
}
// Sao criados 8 processos pois é o resultado de 2^3 sendo 3 o numero de forks