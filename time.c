#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){
    time_t cur_second;
    time(&cur_second);

    printf("%ld\n", cur_second);
    return 0;
}

#if 0

int main(int argc, char **argv){
    time_t cur_second;
    cur_second = time(NULL);

    printf("%ld\n", cur_second);
    return 0;
}

#endif
