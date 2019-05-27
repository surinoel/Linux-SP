#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    pid_t pid;
    int exit_status;

    pid = fork();
    if(pid == 0) {
        printf("It is child process\n");
        exit(EXIT_SUCCESS);
    }
    else if(pid > 0) {
        printf("It is parent process\n");
        wait(&exit_status);
        if(WIFEXITED(exit_status)) {
            printf("child process exited normally\n");
        }
    }
    
    printf("fork end...\n");
    return 0;
}


#if 0

It is parent process
It is child process
child process exited normally
fork end...
    
#endif
