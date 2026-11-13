#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Before fork\n");
    fflush(stdout);                 /* avoid printing it twice */

    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }

    if (pid == 0) {
        printf("\nChild executing...\n");
        printf("Child PID  : %d\nParent PID : %d\n", getpid(), getppid());
        exit(0);
    }
    wait(NULL);                     /* parent waits for child */
    printf("\nParent resumed...\n");
    printf("Parent PID : %d\nChild PID  : %d\n", getpid(), pid);
    return 0;
}
