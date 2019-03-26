#include <stdio.h>
#include <string.h>

int find_offset(void) {
    FILE *fp;
    if(!(fp = fopen("datafile", "r"))) {
        perror("File open Error\n");
        return -1;
    }

    char buf[1024];
    memset(buf, 0, sizeof(buf));

    printf("before fgets offset : %ld\n", ftell(fp));
    fgets(buf, sizeof(buf), fp);
    printf("after fgets offset : %ld\n", ftell(fp));

    fclose(fp);
    return 0;
}

int main(void) {
    if(find_offset()){
        perror("File open Error\n");
        return -1;
    }
    return 0;
}






