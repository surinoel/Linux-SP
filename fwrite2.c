#include <stdio.h>

struct person {
    char name[20];
    int age;
};

void write_struct_data(struct person *p, int size) {
    int i;
    for(i=0; i<size; i++) {
        scanf("%s %d", p[i].name, &p[i].age);
    }
}

int write_binary_data(void) {
    FILE *fp;
    if(!(fp = fopen("datafile", "w"))) {
        printf("fopen error\n");
        return -1;
    }

    struct person persons[3];
    write_struct_data(&persons, sizeof(persons)/sizeof(struct person));
    
    if(fwrite(&persons, sizeof(struct person), 3, fp) != 3) {
        printf("fwrite error\n");
        return -1;
    }
    
    return 0;
}

int main(int argc, char **argv) {
    if(write_binary_data()) {
        printf("write binaty data error\n");
        return -1;
    }
    return 0;
}
