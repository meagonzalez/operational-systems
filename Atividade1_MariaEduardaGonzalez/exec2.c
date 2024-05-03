#include <stdio.h>
#include <unistd.h>

int variavel_global = 10;

int main() {
  pid_t pid_filho;

  pid_filho = fork();

  if (pid_filho == 0) {
    printf("Processo filho: valor da variável global = %d\n", variavel_global);
  } else {
    printf("Processo pai: valor da variável global = %d\n", variavel_global);
  }

  return 0;
}

