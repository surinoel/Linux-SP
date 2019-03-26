#include <stdio.h>

int find_offset(void) {
    FILE *fp;
    if(!(fp = fopen("datafile", "w"))) {
        perror("File open Error\n");
        return -1;
    }

    printf("after create file offset : %ld\n", ftell(fp));
    fputs("hello world!\n", fp);
    fputs("hello world!!\n", fp);
    fputs("hello world!!!\n", fp);
    fputs("hello world!!!!\n", fp);
    printf("before fclose file offset : %ld\n", ftell(fp));

    fclose(fp);
    return 0;
}

int main(int argc, char **argv) {
    if(find_offset()) {
        perror("File Error\n");
        return -1;
    }
    return 0;
}
