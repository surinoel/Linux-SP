#include <stdio.h>
#include <errno.h>
#include <string.h>

int read_data(void) {
    FILE *fp;
    if(!(fp = fopen("data", "r"))) {
        printf("err num : %d, err str : %s\n", 
                errno, strerror(errno));
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    if(read_data()) {
        return -1;
    }
    return 0;
}
