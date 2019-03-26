#include <stdio.h>

int write_append(void) {
    FILE *fp;
    fp = fopen("data", "a");
    
    if(fp == NULL) {
        perror("File open Error\n");
        return -1;
    }

    fputs("append data line\n", fp);
    fclose(fp);

    return 0;
}

int main(void) {
    write_append();
    return 0;
}
