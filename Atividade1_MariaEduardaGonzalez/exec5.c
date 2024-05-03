#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <programa>\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        printf("Erro ao criar o processo.\n");
        return 1;
    } else if (pid == 0) {
        execl(argv[1], argv[1], NULL);
        perror("execl");
        return 1;
    } else {
        wait(NULL);
        printf("Processo pai terminou.\n");
    }

    return 0;
}

