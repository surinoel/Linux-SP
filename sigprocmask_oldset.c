#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char **argv) {
    sigset_t set, oldset;

    sigemptyset(&oldset);
    sigemptyset(&set);

    sigaddset(&set, SIGINT);
    printf("SIGINT BLOCKING........\n");
    sigprocmask(SIG_BLOCK, &set, &oldset);
    sleep(3);

    printf("SIGSETMASK......\n");
    sigprocmask(SIG_SETMASK, &oldset, NULL);
    while(1) {
        sleep(1);
    }
    return 0;
}
