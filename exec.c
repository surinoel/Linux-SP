#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid;
    int exit_status;

    printf("origin process id : %d\n", getpid());
    pid = fork();
    if(pid < 0) {
        perror("fork error\n");
    } else if(pid == 0) {
        printf("child process id : %d\n", getpid());
        if(execl("/bin/ls", "ls", "-al", NULL) == -1) {
            printf("execl() fail\n");
            return -1;
        }
    } else if(pid > 0) {
        printf("parent process pid : %d, child pid %d\n",
                    getpid(), pid);
    }
    
    pid = wait(&exit_status);
    if(WIFEXITED(exit_status)) {
        printf("child %d returns 0x%x\n",
                        pid, WEXITSTATUS(exit_status)); 
    } else {
        printf("child %d is not exited\n", pid);
    }

    return 0;
}
