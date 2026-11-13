#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char msg[] = "Operating Systems Lab", buf[50];

    int fd = creat("sample.txt", 0644);
    if (fd < 0) { perror("creat"); return 1; }
    write(fd, msg, strlen(msg));
    close(fd);

    fd = open("sample.txt", O_RDONLY);
    if (fd < 0) { perror("open"); return 1; }
    int n = read(fd, buf, sizeof buf - 1);
    close(fd);

    buf[n > 0 ? n : 0] = '\0';
    printf("File contents: %s\n", buf);
    return 0;
}
