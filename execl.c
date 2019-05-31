#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int exit_status;
    int ret;
    pid_t pid;
    pid = fork();

    if(pid == 0) {
        ret = execl("/bin/ls", "ls", "-al", "/home/neol", NULL);
        if(ret == -1) {
            printf("strerror: %s\n", strerror(ret));
            return -1;
        }
    } else if(pid > 0) {
        wait(&exit_status);
        if (WIFEXITED(exit_status)) {
            printf("exited, status=%d\n", WEXITSTATUS(exit_status));
        }
        sleep(1);    
    } else {
        perror("fork()\n");
        return -1;
    }

    return 0;
}
