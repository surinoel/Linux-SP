#define _GNU_SOURCE

#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void print_cpuset(cpu_set_t *mask) {
    for(int i=0; i<4; i++) {
        if(CPU_ISSET(i, mask)) {
            printf("CPU%d ", i);
        }
    }
    printf("\n");
}

int main(void) {
    cpu_set_t mask;
    int cur_cpu;

    if(sched_getaffinity(getpid(), sizeof(cpu_set_t), &mask) == -1) {
        perror("sched_getaffinity error\n");
        return -1;
    }
    print_cpuset(&mask);

    printf("run on CPU%d\n", sched_getcpu());
    cur_cpu = sched_getcpu();
    if(++cur_cpu == 4) {
        cur_cpu = 0;
    }
    CPU_ZERO(&mask);
    CPU_ISSET(cur_cpu, &mask);
    sched_setaffinity(getpid(), sizeof(cpu_set_t), &mask);
    
    sleep(1);
    
    cur_cpu = sched_getcpu();    
    printf("run on CPU%d\n", cur_cpu);
    
    return 0;
}
