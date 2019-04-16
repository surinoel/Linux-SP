/*
long ftell(FILE *stream);
*/

#include <stdio.h>

int find_offset(void) {
    FILE *fp;
    int line = 1;
    if(!(fp = fopen("datafile", "w"))) {  
        printf("fopen error\n");
        return -1;
    }

    printf("after open offset: %ld\n", ftell(fp));
    fprintf(fp, "line : %d\n", line++); 
    fprintf(fp, "line : %d\n", line++); 
    fprintf(fp, "line : %d\n", line++); 
    fprintf(fp, "line : %d\n", line++); 
    fprintf(fp, "line : %d\n", line++);
    printf("before close offset: %ld\n", ftell(fp));

    fclose(fp);
    return 0;
}

int main(void) {
    if(find_offset()) {
        printf("find offset error\n");
        return -1;
    }
    return 0;
}
