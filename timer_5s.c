#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void print_current_time(void) {
    time_t now;
    struct tm *now_tm;

    now = time(NULL);
    printf("current : %ld ", now);
    
    now_tm = localtime(&now);
    
    printf("%d-%d-%d %d:%d:%d ", 
                1900 + now_tm->tm_year,
                now_tm->tm_mon + 1,
                now_tm->tm_mday,
                now_tm->tm_hour,
                now_tm->tm_min,
                now_tm->tm_sec);
    
    switch(now_tm->tm_wday) {
        case 0:
            printf("sun\n");
            break;
        case 1:
            printf("mon\n");
            break;
        case 2:
            printf("tue\n");
            break;
        case 3:
            printf("wed\n");
            break;
        case 4:
            printf("thu\n");
            break;
        case 5:
            printf("fri\n");
            break;
        case 6:
            printf("sat\n");
            break;
    }
}

static void sigalarm_hanlder(int signum) {
    printf("got SIGALRM signal\n");
    print_current_time();
}

int main(int argc, char **argv) {
    print_current_time();
    signal(SIGALRM, sigalarm_hanlder);

    alarm(5);
    
    while(1) {
        sleep(1);
    }

    return 0;
}
