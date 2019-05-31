#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <linux/unistd.h>

void *print_pchild_pid(void *arg) {
    printf("child process pid: %d, task_num: %lu\n",
            getpid(), syscall(__NR_gettid));
    return NULL;
}

int main(int argc, char **argv) {
    pthread_t pthread_child;
    int ret;

    printf("main process pid: %d, task_num: %lu\n",
            getpid(), syscall(__NR_gettid));

    ret = pthread_create(&pthread_child, NULL, print_pchild_pid, NULL);
    if(ret) {
        perror("pthread_create\n");
        return -1;
    }       
    pthread_join(pthread_child, NULL);

    return 0;
}
