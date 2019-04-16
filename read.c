/*
char *fgets(char *s, int size, FILE *stream);
*/

#include <stdio.h>
#include <string.h>

int read_data(void) {
    FILE *fp;
    char buf[1024];

    if(!(fp = fopen("datafile", "r"))) {
        printf("fopen error\n");        
        return -1;
    }

    while(fgets(buf, sizeof(buf), fp)) {
        printf("%s", buf);
    } 
    
    return 0;
}

int main(void) {
    if(read_data()) {
        printf("read data error\n");
        return -1;
    }   

    return 0;
}
