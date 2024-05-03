#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t pid;

  pid = fork();

  if (pid == 0) {
    printf("Eu sou o pai e meu pid é: %d\n", getpid());
  } else {
    printf("Eu sou o filho e meu pid é: %d\n", getpid());
    wait(NULL);
  }

  return 0;
}
