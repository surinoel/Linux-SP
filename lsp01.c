#include <stdio.h>

int write_data(void) {
    FILE *fp;
    fp = fopen("data", "w");
    
    if(fp == NULL) {
        perror("File not open\n");
        return -1;
    }

    fputs("hello world!\n", fp);
    return 0;
}

int main(int argc, char **argv) {
    write_data();
    return 0;
}
