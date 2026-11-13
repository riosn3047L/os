#include <stdio.h>
#include <time.h>
#include <sys/stat.h>

int main() {
    char name[100];
    struct stat s;

    printf("Enter file name: ");
    if (scanf("%99s", name) != 1) return 1;
    if (stat(name, &s) == -1) { perror("stat"); return 1; }

    printf("Size        : %lld bytes\n", (long long)s.st_size);
    printf("Inode       : %llu\n", (unsigned long long)s.st_ino);
    printf("Mode        : %o\n", (unsigned)s.st_mode);
    printf("Links       : %lu\n", (unsigned long)s.st_nlink);
    printf("UID / GID   : %d / %d\n", (int)s.st_uid, (int)s.st_gid);
    printf("Last access : %s", ctime(&s.st_atime));
    printf("Last modify : %s", ctime(&s.st_mtime));
    return 0;
}
