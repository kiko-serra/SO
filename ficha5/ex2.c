#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    for (int i = 0; i < 4; i++)
        fork();
    return EXIT_SUCCESS;
}
// Sao criados 16 processos pois é o resultado de 2^4 sendo 4 o numero de forks