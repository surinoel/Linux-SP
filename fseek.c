/*
int fseek(FILE *stream, long offset, int whence);

whence  is  set to SEEK_SET, SEEK_CUR, or SEEK_END, the offset  is  relative to the start of the file, the current position indicator, or end-of-file, respectively.
*/

#include <stdio.h>
#include <string.h>

int set_fseek(void) {
    FILE *fp;
    char buf[1024];

    if(!(fp = fopen("datafile", "r"))) {
        printf("fopen error\n");
        return -1;
    }

    if(fseek(fp, 9, SEEK_SET) == -1) {
        printf("fseek error\n");
        return -1;
    }

    if(fgets(buf, sizeof(buf), fp)) {
        printf("%s", buf);
    }

    if(fseek(fp, -9, SEEK_END) == -1) {
        printf("fseek error\n");
        return -1;
    }

    if(fgets(buf, sizeof(buf), fp)) {
        printf("%s", buf);
    }

    fclose(fp);
    return 0;
}

int main(int argc, char **argv) {
    if(set_fseek()) {
        printf("set_fseek error\n");
        return -1;
    }
    return 0;
}
