#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv) {
    int ret, pipe_fds[2];
    pid_t pid;
    char buf[1024];
    int exit_status;
    
    printf("[%d] start of function\n", getpid());
    memset(buf, 0, sizeof(buf));
    ret = pipe(pipe_fds);
    if(ret) {
        perror("pipe\n");
        goto err;
    }

    pid = fork();
    if(pid == 0) {
        close(pipe_fds[1]);
        read(pipe_fds[0], buf, sizeof(buf));
        
        printf("[%d] parent said... %s\n", getpid(), buf);
        close(pipe_fds[0]);

    } else if(pid > 0) {
        close(pipe_fds[0]);
        strncpy(buf, "hello child....", sizeof(buf) - 1); 
        write(pipe_fds[1], buf, strlen(buf));

        wait(&exit_status);
        if (WIFEXITED(exit_status)) {
            printf("exited, status=%d\n", WEXITSTATUS(exit_status));
        }
        
       close(pipe_fds[1]);

    } else {
        perror("fork\n");
        goto err;
    }
   
    return 0;
err:
    close(pipe_fds[0]);
    close(pipe_fds[1]);
}

#if 0

[5607] start of function
[5608] parent said... hello child....
exited, status=0

#endif
