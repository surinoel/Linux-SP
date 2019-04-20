/*
binary stream output
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

On success, fread() and fwrite() return the number of items read or written.  This number equals the number of bytes transferred
only when size is 1.  If an error occurs, or the end of the file is reached, the return value is a short item count (or zero)
*/

#include <stdio.h>

struct person {
    char name[20];
    int age;
};

static int write_binary_file(void) {
    FILE *fp;
    if(!(fp = fopen("datafile", "w"))) {
        return -1;
    }  

    struct person kim = {
        .name = "kim",
        .age = 20
    };

    struct person you = {
        .name = "you",
        .age = 30
    };
    
    if(fwrite(&kim, sizeof(struct person), 1, fp) != 1) {
        printf("fwrite error1\n");
        return -1;
    }    

    if(fwrite(&you, sizeof(struct person), 1, fp) != 1) {
        printf("fwrite error2\n");
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    if(write_binary_file()) {
        printf("write binaty file error\n");
        return -1;
    }
    return 0;
}
