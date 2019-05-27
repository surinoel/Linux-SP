#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int N = 5;
    int exit_status;
    pid_t pid[N];
    
    printf("[%d] parent\n", getpid());
    for(int i=0; i < N; i++) {
        pid[i] = fork();
        if(pid[i] == 0) {
            printf("[%d] child fork()\n", getpid());
            exit(EXIT_SUCCESS);
        }
    } 

    for(int i=0; i < N; i++) {
        pid_t child = wait(&exit_status);
        
        if(WIFEXITED(exit_status)) {
            printf("[%d] child is terminated... %d\n", child, WEXITSTATUS(exit_status));
        }
    }

    return 0;
}

#if 0

[27676] parent
[27677] child fork()
[27678] child fork()
[27679] child fork()
[27677] child is terminated... 0
[27678] child is terminated... 0
[27681] child fork()
[27679] child is terminated... 0
[27680] child fork()
[27680] child is terminated... 0
[27681] child is terminated... 0

#endif
