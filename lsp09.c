#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static int write_file(void) {
    int fd;
    char name[20];
    memset(name, 0, sizeof(name));
    memcpy(name, "유영재", sizeof(name));

    fd = open("datafile", O_WRONLY | O_CREAT, 0644);
    if(fd < 0) {
        printf("open() error\n");
        return -1;
    }
    
    dprintf(fd, "Hello world\n");
    dprintf(fd, "My name is %s\n", name);

    close(fd);
    return 0;
}

static int trunc_file(void) {
    int fd;
    
    fd = open("datafile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd < 0) {
        printf("open() error\n");
        return -1;
    }
    
    dprintf(fd, "renew file\n");

    close(fd);
    return 0;
}

static int append_file(void) {
    int fd;
    
    fd = open("datafile", O_WRONLY | O_APPEND, 0644);
    if(fd < 0) {
        printf("open() error\n");
        return -1;
    }
    
    dprintf(fd, "append content\n");

    close(fd);
    return 0;
}


int main(int argc, char **argv) {
    if(write_file()) {
        perror("write error\n");
        return -1;
    }
    if(trunc_file()) {
        perror("trunc error\n");
        return -1;
    }
    if(append_file()) {
        perror("append error\n");
        return -1;
    }
    return 0;
}
