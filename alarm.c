#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int ret;
    printf("trying to make alarm timer....\n");
    ret = alarm(5);
    if(ret) {
        printf("old timers exist\n");
        printf("remaining time: %d\n", ret);
    }
    else {
        printf("old timers not exist\n");
    }
    
    sleep(1);
    sleep(1);

    printf("trying to make alarm timer....\n");
    ret = alarm(5);
    if(ret) {
        printf("old timers exist\n");
        printf("remaining time: %d\n", ret);
    }
    else {
        printf("old timers not exist\n");
    }

    while(1) {
        sleep(1);
    }

    return 0;
}
