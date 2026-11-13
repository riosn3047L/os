#include <stdio.h>

int main() {
    int f, n, pg[50], fr[10], faults = 0;

    printf("Number of frames: ");
    scanf("%d", &f);
    printf("Number of pages: ");
    scanf("%d", &n);
    printf("Reference string: ");
    for (int i = 0; i < n; i++) scanf("%d", &pg[i]);
    for (int j = 0; j < f; j++) fr[j] = -1;

    printf("\nPage\tFrames\tStatus\n");
    for (int i = 0; i < n; i++) {
        int hit = 0;
        for (int j = 0; j < f; j++)
            if (fr[j] == pg[i]) hit = 1;

        if (!hit) {         /* empty frame, else one used farthest ahead */
            int pos = 0, far = -1;
            faults++;
            for (int j = 0; j < f; j++) {
                if (fr[j] < 0) { pos = j; break; }
                int k = i + 1;
                while (k < n && pg[k] != fr[j]) k++;
                if (k > far) { far = k; pos = j; }
            }
            fr[pos] = pg[i];
        }

        printf("%d\t", pg[i]);
        for (int j = 0; j < f; j++)
            if (fr[j] < 0) printf("- "); else printf("%d ", fr[j]);
        printf("\t%s\n", hit ? "Hit" : "Fault");
    }
    printf("\nPage faults = %d\nPage hits   = %d\n", faults, n - faults);
    return 0;
}
