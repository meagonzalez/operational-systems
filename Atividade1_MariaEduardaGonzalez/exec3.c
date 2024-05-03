#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int variavel_global = 10;

int main()
{
    printf("Valor da variável global antes do fork: %d\n", variavel_global);

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Erro no fork()\n");
        exit(-1);
    }
    else if (pid == 0)
    {
        printf("Eu sou o filho e meu pid é: %d\n", getpid());
        printf("Pressione a tecla Enter para continuar");
        getchar();
        printf("Global filho após espera: %d\n", variavel_global);
        exit(0);
    }
    else
    {
        printf("Eu sou o pai com pid: %d\n", getpid());
        variavel_global = 20;
        printf("Global pai após alteração: %d\n", variavel_global);
        wait(NULL);
        exit(0);
    }

    return 0;
}
