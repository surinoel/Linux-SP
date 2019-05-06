#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void test_func(void) {
    printf("It's test function(%d)\n", getpid());
}

int main(void) {
    pid_t child_pid;
    printf("origin pid = %d\n", getpid());

    child_pid = fork();
    if(child_pid == 0) {
        printf("child pid: %d, parent pid: %d\n", \
                getpid(), getppid());
    }
    else if(child_pid > 0) {
        printf("parent pid: %d, child pid: %d\n", \
                getpid(), child_pid);
    }
    else {
        perror("fork error\n");
        return -1;
    }

    return 0;
}
