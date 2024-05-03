#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void print_even_numbers(int n) {
    for (int i = 2; i <= n * 2; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <quantidade de números pares>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    pid_t pid = fork();

    if (pid == 0) {
        printf("Processo filho: Imprimindo %d números pares:\n", n);
        print_even_numbers(n);
    } else if (pid > 0) {
        wait(NULL);
        printf("Processo pai: Processo filho terminou. Terminando execução.\n");
    } else {
        printf("Erro ao criar o processo filho\n");
        return 1;
    }

    return 0;
}

