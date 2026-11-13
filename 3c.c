#include <stdio.h>

int main() {
    int n, q, pid[20], bt[20], rt[20], time = 0, done = 0;
    float twt = 0, ttat = 0;

    printf("Number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("PID and burst time of P%d: ", i + 1);
        scanf("%d %d", &pid[i], &bt[i]);
        rt[i] = bt[i];
    }
    printf("Time quantum: ");
    scanf("%d", &q);

    printf("\nPID\tBT\tWT\tTAT\n");
    while (done < n)
        for (int i = 0; i < n; i++) {
            if (rt[i] == 0) continue;
            int run = rt[i] < q ? rt[i] : q;
            time += run;
            rt[i] -= run;
            if (rt[i] == 0) {           /* process finished */
                done++;
                printf("%d\t%d\t%d\t%d\n",
                       pid[i], bt[i], time - bt[i], time);
                twt += time - bt[i];
                ttat += time;
            }
        }
    printf("Average WT  = %.2f\n", twt / n);
    printf("Average TAT = %.2f\n", ttat / n);
    return 0;
}
