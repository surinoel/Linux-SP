#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    time_t now;
    struct tm *now_tm;

    now = time(NULL);
    printf("current : %ld\n", now);
    
    now_tm = localtime(&now);

#if 0    
  struct tm {
       int tm_sec;    /* Seconds (0-60) */
       int tm_min;    /* Minutes (0-59) */
       int tm_hour;   /* Hours (0-23) */
       int tm_mday;   /* Day of the month (1-31) */
       int tm_mon;    /* Month (0-11) */
       int tm_year;   /* Year - 1900 */
       int tm_wday;   /* Day of the week (0-6, Sunday = 0) */
       int tm_yday;   /* Day in the year (0-365, 1 Jan = 0) */
       int tm_isdst;  /* Daylight saving time */
   };
#endif
    
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
    return 0;
}
