#include <stdio.h>

int main() {
    FILE *fp;
    char line[100], name[30];
    int roll, ch, nums[5] = {10, 20, 30, 40, 50}, back[5];

    /* write text file */
    if (!(fp = fopen("student.txt", "w"))) { perror("fopen"); return 1; }
    fputs("Student Record File\n", fp);
    fprintf(fp, "%d %s\n", 101, "Arun");
    fputs("Grade: ", fp);
    fputc('A', fp);
    fputc('\n', fp);
    fclose(fp);
    printf("Text file written (fputs, fprintf, fputc)\n\n");

    /* read text file */
    if (!(fp = fopen("student.txt", "r"))) { perror("fopen"); return 1; }
    fgets(line, sizeof line, fp);
    printf("Header (fgets) : %s", line);
    fscanf(fp, "%d %29s", &roll, name);
    printf("Roll (fscanf)  : %d\nName (fscanf)  : %s\n", roll, name);
    fgetc(fp);                          /* skip newline */
    printf("Rest (fgetc)   : ");
    while ((ch = fgetc(fp)) != EOF) putchar(ch);
    fclose(fp);

    /* write and read binary file */
    if (!(fp = fopen("numbers.bin", "wb"))) { perror("fopen"); return 1; }
    fwrite(nums, sizeof(int), 5, fp);
    fclose(fp);

    if (!(fp = fopen("numbers.bin", "rb"))) { perror("fopen"); return 1; }
    fread(back, sizeof(int), 5, fp);
    fclose(fp);

    printf("\nBinary read (fread): ");
    for (int i = 0; i < 5; i++) printf("%d ", back[i]);
    printf("\n");
    return 0;
}
