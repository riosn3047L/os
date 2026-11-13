#include <stdio.h>
#define P 5                             /* processes */
#define R 3                             /* resource types */

int main() {
    int alloc[P][R] = {{0,1,0}, {2,0,0}, {3,0,2}, {2,1,1}, {0,0,2}};
    int max[P][R]   = {{7,5,3}, {3,2,2}, {9,0,2}, {2,2,2}, {4,3,3}};
    int avail[R] = {3, 3, 2}, need[P][R], done[P] = {0}, seq[P], cnt = 0;

    printf("Need matrix\n");
    for (int i = 0; i < P; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    for (int pass = 0; pass < P; pass++)
        for (int i = 0; i < P; i++) {
            if (done[i]) continue;
            int j = 0;
            while (j < R && need[i][j] <= avail[j]) j++;
            if (j < R) continue;        /* cannot satisfy now */
            for (j = 0; j < R; j++) avail[j] += alloc[i][j];
            done[i] = 1;
            seq[cnt++] = i;
        }

    if (cnt < P) {
        printf("\nSystem is NOT in a safe state\n");
        return 0;
    }
    printf("\nSafe sequence: ");
    for (int i = 0; i < P; i++)
        printf("P%d%s", seq[i], i < P - 1 ? " -> " : "\n");
    return 0;
}
