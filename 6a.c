#include <stdio.h>

int main() {
    int f, n, pg[50], fr[10], last[10], faults = 0;

    printf("Number of frames: ");
    scanf("%d", &f);
    printf("Number of pages: ");
    scanf("%d", &n);
    printf("Reference string: ");
    for (int i = 0; i < n; i++) scanf("%d", &pg[i]);
    for (int j = 0; j < f; j++) fr[j] = last[j] = -1;

    printf("\nPage\tFrames\tStatus\n");
    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = 0; j < f; j++)
            if (fr[j] == pg[i]) pos = j;
        int hit = pos != -1;

        if (!hit) {                     /* empty or least recently used */
            faults++;
            pos = 0;
            for (int j = 1; j < f; j++)
                if (last[j] < last[pos]) pos = j;
            fr[pos] = pg[i];
        }
        last[pos] = i;

        printf("%d\t", pg[i]);
        for (int j = 0; j < f; j++)
            if (fr[j] < 0) printf("- "); else printf("%d ", fr[j]);
        printf("\t%s\n", hit ? "Hit" : "Fault");
    }
    printf("\nPage faults = %d\nPage hits   = %d\n", faults, n - faults);
    return 0;
}
