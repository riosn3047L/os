#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("/tmp", 65);       /* same key as writer */
    int id = shmget(key, 1024, 0666 | IPC_CREAT);
    if (id < 0) { perror("shmget"); return 1; }

    char *str = shmat(id, NULL, 0);
    if (str == (char *)-1) { perror("shmat"); return 1; }

    printf("Data read from memory: %s", str);

    shmdt(str);
    shmctl(id, IPC_RMID, NULL);         /* destroy segment */
    return 0;
}
