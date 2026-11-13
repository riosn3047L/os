#include <stdio.h>

int main() {
    int n, pid[20], bt[20], wt = 0, tat, twt = 0, ttat = 0;

    printf("Number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("PID and burst time of P%d: ", i + 1);
        scanf("%d %d", &pid[i], &bt[i]);
    }

    printf("\nPID\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        tat = wt + bt[i];
        printf("%d\t%d\t%d\t%d\n", pid[i], bt[i], wt, tat);
        twt += wt;
        ttat += tat;
        wt = tat;                   /* next one waits till now */
    }
    printf("Average WT  = %.2f\n", (float)twt / n);
    printf("Average TAT = %.2f\n", (float)ttat / n);
    return 0;
}
