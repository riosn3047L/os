#include <stdio.h>
#include <stdlib.h>

int cur, total;

void go(int to) {                       /* move head, add seek */
    total += abs(to - cur);
    cur = to;
    printf(" -> %d", to);
}

int main() {
    int n, r[100], done[100] = {0};

    printf("Number of requests: ");
    scanf("%d", &n);
    printf("Request queue: ");
    for (int i = 0; i < n; i++) scanf("%d", &r[i]);
    printf("Initial head position: ");
    scanf("%d", &cur);

    printf("\nSeek sequence: %d", cur);
    for (int c = 0; c < n; c++) {
        int k = -1;                     /* nearest pending request */
        for (int i = 0; i < n; i++)
            if (!done[i] && (k < 0 || abs(r[i] - cur) < abs(r[k] - cur)))
                k = i;
        done[k] = 1;
        go(r[k]);
    }
    printf("\nTotal seek time = %d cylinders\n", total);
    return 0;
}
