#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <linux/unistd.h>

int main(int argc, char **argv) {
    pid_t pid;
    
    pid = fork();
    if(pid == 0) { 
        printf("TGID(%d), PID(%lu)\n",
                getpid(), syscall(__NR_gettid));
        exit(0);
    } else if(pid > 0) {
        wait(NULL);
        printf("TGID(%d), PID(%lu)\n",
                getpid(), syscall(__NR_gettid));

    } else {
        perror("fork()\n");
        return -1;
    }

    return 0;
}
