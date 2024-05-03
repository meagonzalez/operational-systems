#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int nfilho;

void proc_filho() {
    printf("Processo FILHO %d iniciado\n", nfilho);
    printf("Vai dormir por %d segundos\n", nfilho * 10);
    sleep(nfilho * 10);
    printf("Processo FILHO %d encerrado\n", nfilho);
}

int main() {
    printf("Processo PAI iniciado\n");

    for (nfilho = 1; nfilho <= 4; nfilho++) {
        pid_t pid = fork();

        if (pid < 0) {
            printf("Erro ao criar o processo.\n");
            return 1;
        } else if (pid == 0) {
            proc_filho();
            exit(0);
        }
    }

    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }

    printf("Processo PAI encerrado\n");
    return 0;
}

