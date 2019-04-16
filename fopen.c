/*
FILE *fopen(const char *path, const char *mode); 
int fputs(const char *s, FILE *stream);
 */

#include <stdio.h>

int write_data(void) {
    FILE *fp;

    if(!(fp = fopen("datafile", "w"))){
        printf("open error\n");
        return -1;
    }

    fputs("hello world\n", fp);

    fclose(fp);
    
    return 0;
}


int main(int argc, char** argv) {
    if(write_data()) {
        printf("write data error\n");
        return -1;
    }
    return 0;
}
