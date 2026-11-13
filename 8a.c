#include <stdio.h>
#include <stdlib.h>

int cur, total;

void go(int to) {                       /* move head, add seek */
    total += abs(to - cur);
    cur = to;
    printf(" -> %d", to);
}

int main() {
    int n, r[100];

    printf("Number of requests: ");
    scanf("%d", &n);
    printf("Request queue: ");
    for (int i = 0; i < n; i++) scanf("%d", &r[i]);
    printf("Initial head position: ");
    scanf("%d", &cur);

    printf("\nSeek sequence: %d", cur);
    for (int i = 0; i < n; i++) go(r[i]);
    printf("\nTotal seek time = %d cylinders\n", total);
    return 0;
}
