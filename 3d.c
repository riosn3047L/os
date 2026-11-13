#include <stdio.h>

struct proc { int pid, bt, pri; };

int main() {
    struct proc p[20], t;
    int n, wt = 0, tat, twt = 0, ttat = 0;

    printf("Number of processes: ");
    scanf("%d", &n);
    printf("(lower number = higher priority)\n");
    for (int i = 0; i < n; i++) {
        printf("PID, burst time, priority of P%d: ", i + 1);
        scanf("%d %d %d", &p[i].pid, &p[i].bt, &p[i].pri);
    }

    for (int i = 0; i < n - 1; i++)     /* sort by priority */
        for (int j = i + 1; j < n; j++)
            if (p[j].pri < p[i].pri) { t = p[i]; p[i] = p[j]; p[j] = t; }

    printf("\nPID\tBT\tPri\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        tat = wt + p[i].bt;
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].pri, wt, tat);
        twt += wt;
        ttat += tat;
        wt = tat;
    }
    printf("Average WT  = %.2f\n", (float)twt / n);
    printf("Average TAT = %.2f\n", (float)ttat / n);
    return 0;
}
