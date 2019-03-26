#include <stdio.h>
#include <string.h>

int read_data(void) {
    char buf[1024];
    FILE *fp;
    fp = fopen("data", "r");
       
    memset(buf, 0, sizeof(buf));

    if(fp == NULL) {
        perror("File open error\n");
        return -1;
    }

    fgets(buf, sizeof(buf), fp);
    printf("%s\n", buf);

    return 0;   
}

int main(void) {
    if(read_data()) {
        perror("read data error\n");
        return -1;
    }
    return 0;
}
