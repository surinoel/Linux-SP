#include <stdio.h>
#include <string.h>

int read_ftell(void) {
    FILE *fp;
    char buf[1024];

    if(!(fp = fopen("datafile", "r"))) {
        printf("fopen error\n");
        return -1;
    }
    
    printf("after open offset: %ld\n", ftell(fp));
    fgets(buf, sizeof(buf), fp);
    printf("after read one line, offset: %ld\n", ftell(fp));
    fgets(buf, sizeof(buf), fp);
    printf("after read one line, offset: %ld\n", ftell(fp));

    fclose(fp);
    return 0;
}

int main(int argc, char **argv) {
    if(read_ftell()) {
        printf("read ftell error\n");
        return -1;
    }
    return 0;
}
