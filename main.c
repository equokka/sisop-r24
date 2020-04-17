// Escreva um programa que chama fork e, em seguida, chama uma das formas de
// exec para correr o programa bin/ls. Experimente as seguintes variantes de
// exec, execlp e execvp, explicando as diferencas.

// Run `man 3 exec` for info on "exec" and its variants
// Or read it online: https://linux.die.net/man/3/exec

// int execlp(const char *file, const char *arg, ...);
// int execvp(const char *file, char *const argv[]);

// The difference between the two is execlp takes arguments as string, and
// execvp takes arguments as an array.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void) {
  pid_t pid = fork();

  if (pid < 0) { // Failed fork
    fprintf(stderr, "Failed fork\n");
    exit(1);
  }
  else if (pid == 0) { // Child process
    // execlp
    printf("Child PID#%d: Running `execlp` : `ls --color /var`\n", pid);
    execlp("/bin/ls", "ls", "--color", "/var", NULL);
  }
  else { // Parent process
    // Wait for child process to finish
    wait(NULL);

    // execvp
    printf("Parent PID#%d: Running `execvp` : `ls --color /`\n", pid);
    char* argv[4];
    argv[0] = "ls";
    argv[1] = "--color";
    argv[2] = "/";
    argv[3] = NULL;
    execvp("/bin/ls", argv);
  }

  return 0;
}
