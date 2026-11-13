#include <stdio.h>
#include <stdlib.h>

int cur, total;

void go(int to) {                       /* move head, add seek */
    total += abs(to - cur);
    cur = to;
    printf(" -> %d", to);
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
    int size, n, r[100], dir, k = 0;

    printf("Number of cylinders: ");
    scanf("%d", &size);
    printf("Number of requests: ");
    scanf("%d", &n);
    printf("Request queue: ");
    for (int i = 0; i < n; i++) scanf("%d", &r[i]);
    printf("Initial head position: ");
    scanf("%d", &cur);
    printf("Direction (1 = high, 0 = low): ");
    scanf("%d", &dir);

    qsort(r, n, sizeof(int), cmp);
    while (k < n && r[k] < cur) k++;    /* r[k..] are above head */

    printf("\nSeek sequence: %d", cur);
    if (dir) {
        for (int i = k; i < n; i++) go(r[i]);
        if (cur != size - 1) go(size - 1);
        for (int i = k - 1; i >= 0; i--) go(r[i]);
    } else {
        for (int i = k - 1; i >= 0; i--) go(r[i]);
        if (cur != 0) go(0);
        for (int i = k; i < n; i++) go(r[i]);
    }
    printf("\nTotal seek time = %d cylinders\n", total);
    return 0;
}
