#include <stdio.h>

int main() {
    int nb, np, blk[50], prc[50], used[50] = {0};

    printf("Number of blocks: ");
    scanf("%d", &nb);
    printf("Block sizes: ");
    for (int i = 0; i < nb; i++) scanf("%d", &blk[i]);
    printf("Number of processes: ");
    scanf("%d", &np);
    printf("Process sizes: ");
    for (int i = 0; i < np; i++) scanf("%d", &prc[i]);

    printf("\nProcess\tSize\tBlock\tFragment\n");
    for (int i = 0; i < np; i++) {
        int b = -1;                     /* largest block that fits */
        for (int j = 0; j < nb; j++)
            if (!used[j] && blk[j] >= prc[i] &&
                (b < 0 || blk[j] > blk[b])) b = j;

        if (b < 0) {
            printf("P%d\t%d\tNot allocated\n", i + 1, prc[i]);
            continue;
        }
        used[b] = 1;
        printf("P%d\t%d\tB%d\t%d\n", i + 1, prc[i], b + 1, blk[b] - prc[i]);
    }
    return 0;
}
