#include <stdio.h>

int main() {
    int n, pid[20], bt[20], t, wt = 0, tat, twt = 0, ttat = 0;

    printf("Number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("PID and burst time of P%d: ", i + 1);
        scanf("%d %d", &pid[i], &bt[i]);
    }

    for (int i = 0; i < n - 1; i++)     /* sort by burst time */
        for (int j = i + 1; j < n; j++)
            if (bt[j] < bt[i]) {
                t = bt[i];  bt[i] = bt[j];  bt[j] = t;
                t = pid[i]; pid[i] = pid[j]; pid[j] = t;
            }

    printf("\nPID\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        tat = wt + bt[i];
        printf("%d\t%d\t%d\t%d\n", pid[i], bt[i], wt, tat);
        twt += wt;
        ttat += tat;
        wt = tat;
    }
    printf("Average WT  = %.2f\n", (float)twt / n);
    printf("Average TAT = %.2f\n", (float)ttat / n);
    return 0;
}
