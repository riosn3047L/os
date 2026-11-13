#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }

    if (pid == 0) {
        printf("Child : PID = %d, Parent PID = %d\n", getpid(), getppid());
        exit(0);
    }
    wait(NULL);
    printf("Parent: PID = %d, Child PID  = %d\n", getpid(), pid);
    return 0;
}
