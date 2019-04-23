/*
int open(const char *pathname, int flags, mode_t mode);
flags must include one of the following access modes: O_RDONLY, O_WRONLY, or O_RDWR.  These request opening  the  file  read-only, write-only, or read/write, respectively.

system call
man 2 open
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    int fd;
    char name[50];
    
    memset(name, 0, sizeof(name));
    memcpy(name, "리눅스 시스템 프로그래밍", sizeof(name));

    fd = open("datafile", O_WRONLY | O_CREAT, 0664);
    if(fd < 0) {
        printf("open() error\n");
        return -1;
    }

    dprintf(fd, "Hello world\n");
    dprintf(fd, "It's %s\n", name);

    close(fd);

    return 0;
}
