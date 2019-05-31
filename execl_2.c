#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    pid_t pid;
    int ret;

    pid = fork();
    if(pid > 0) {
        wait(NULL);
    } else if(pid == 0) {
        printf("before execl()\n");
        ret = execl("/bin/ls", "ls", "-al", NULL);
        if(ret == -1) {
            perror("execl\n");
            return -1;
        }    
        printf("after execl()\n");        
    } else {
        perror("fork()");
        return -1;
    }
    
    return 0;
}
