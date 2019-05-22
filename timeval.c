#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char **argv) {
    struct timeval tv;
   
    #if 0
    gettimeofday에서 두번째 인자인 struct timezone 변수는 내부적으로 사용되지 않는다
    
    struct timeval {
        time_t      tv_sec;     /* seconds */
        suseconds_t tv_usec;    /* microseconds */
    };
    #endif
        
    if(gettimeofday(&tv, NULL)) { 
        printf("gettimeofday Error\n");
        return -1;
    }

    printf("tv_sec %ld, tv_usec %ld\n", 
           tv.tv_sec, tv.tv_usec); 
    return 0;
}
