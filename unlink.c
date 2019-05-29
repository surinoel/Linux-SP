#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int ret;

    ret = unlink("./test");
    if(ret) {
        printf("err num : %d, err str :%s\n",
                errno, strerror(errno));
        return -1;
    }
    return 0;
}
