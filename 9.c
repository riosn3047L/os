#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

/* DAC: owner decides permissions; show rwx bits */
void dac(const char *file) {
    struct stat st;
    const char *who[] = {"Owner", "Group", "Others"};

    if (stat(file, &st) != 0) { printf("File not found\n"); return; }
    printf("[DAC] %s\n", file);
    for (int i = 0; i < 3; i++) {
        int m = st.st_mode >> (6 - 3 * i);
        printf("%-6s: %c%c%c\n", who[i], m & 4 ? 'r' : '-',
               m & 2 ? 'w' : '-', m & 1 ? 'x' : '-');
    }
}

/* RBAC: permissions come from the user's role */
struct role { char *name; int r, w, x; };

void rbac(const char *name, const char *op) {
    struct role roles[] = {
        {"admin", 1, 1, 1}, {"staff", 1, 1, 0}, {"guest", 1, 0, 0}
    };
    printf("\n[RBAC] Role: %s, Operation: %s\n", name, op);
    for (int i = 0; i < 3; i++) {
        if (strcmp(roles[i].name, name) != 0) continue;
        int ok = !strcmp(op, "read")  ? roles[i].r :
                 !strcmp(op, "write") ? roles[i].w : roles[i].x;
        printf("Access %s\n", ok ? "GRANTED" : "DENIED");
        return;
    }
    printf("Unknown role\n");
}

/* MAC (Bell-LaPadula): 1 public, 2 confidential, 3 secret */
void mac(int user, int file, const char *op) {
    int ok = !strcmp(op, "read") ? user >= file   /* no read up */
                                 : user <= file;  /* no write down */
    printf("\n[MAC] User %d, File %d, Operation: %s\n", user, file, op);
    printf("Access %s\n", ok ? "GRANTED" : "DENIED");
}

int main() {
    FILE *fp = fopen("testfile.txt", "w");
    if (fp) { fprintf(fp, "sample data\n"); fclose(fp); }
    chmod("testfile.txt", 0754);        /* rwx r-x r-- */
    dac("testfile.txt");

    rbac("admin", "write");
    rbac("guest", "write");
    rbac("staff", "execute");

    mac(3, 2, "read");                  /* granted */
    mac(1, 2, "read");                  /* denied  */
    mac(3, 1, "write");                 /* denied  */
    return 0;
}
