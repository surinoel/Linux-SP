#include <stdio.h>
#include <string.h>

int read_file(void) {
    FILE *fp;
    char buf[1024];

    fp = fopen("datafile", "r+");
    if(fp == NULL) {
        perror("File open error\n");
        return -1;
    }
    
    memset(buf, 0, sizeof(buf));
    printf("after foepn offset = %ld\n", ftell(fp));
    fgets(buf, sizeof(buf), fp);
    printf("after fgets offset = %ld\n", ftell(fp));

    fseek(fp, 0, SEEK_END);
    printf("after fseek offset = %ld\n", ftell(fp));
    
    fputs("final\n", fp);
    printf("after fputs offset = %ld\n", ftell(fp));

    fclose(fp);
    return 0;
}

int main(int argc, char **argv) {
    if(read_file()) {
        perror("File read error\n");
        return -1;
    }
    return 0;
}


