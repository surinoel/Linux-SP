#include <stdio.h>

int append_data(void) {
    FILE *fp;
    
    if(!(fp = fopen("datafile", "a"))) {
        printf("fopen error\n");
        return -1;
    }

    fputs("it's ubuntu environment\n", fp);
    
    fclose(fp);
    return 0;
}

int main(int argc, char **argv) {
    if(append_data()) {
        printf("append data error\n");
        return -1;
    }
    return 0;
}
