#include <stdio.h>
#include <string.h>

struct person {
    char name[20];
    int age;
};

static int write_binary_file(void) {
    FILE *fp = NULL;
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
        goto err;
    }
    if(fwrite(&you, sizeof(struct person), 1, fp) != 1) {
        goto err;
    }

    fclose(fp);
    return 0;

err:
    if(fp) {
        fclose(fp);
    }
    return -1;
}

static int read_binary_file(void) {
    FILE *fp = NULL;
    int i;
    struct person persons[2];

    if(!(fp = fopen("datafile", "r"))) {
        return -1;
    }

    if(fread(persons, sizeof(struct person), 2, fp) != 2) {
        goto err;
    }

    for(int i=0; i<2; i++) {
        printf("name = %s, age = %d\n",
                persons[i].name, persons[i].age);
    }

    fclose(fp);

    return 0;
err: 
    if(fp) {
        fclose(fp);
    }
    return -1;
}

int main(int argc, char **argv) {
    if(write_binary_file()) {
        perror("write error\n");
        return -1;
    }
    
    if(read_binary_file()) {
        perror("read error\n");
        return -1;
    }
    return 0;
}
