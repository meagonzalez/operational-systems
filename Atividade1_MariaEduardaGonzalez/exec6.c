#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 512; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            printf("Erro ao criar o processo.\n");
            return 1;
        } else if (pid == 0) {
            printf("Estou vivo!\n");
            sleep(20);
            exit(0);
        }
    }

    for (int i = 0; i < 512; i++) {
        wait(NULL);
    }

    printf("Todos os processos filhos terminaram.\n");
    return 0;
}

