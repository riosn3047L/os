#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Current date and time:\n");
    fflush(stdout);                 /* exec replaces the buffer */
    execlp("date", "date", NULL);
    perror("execlp");               /* runs only if exec fails */
    return 1;
}
