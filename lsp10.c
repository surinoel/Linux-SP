#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct person {
    char name[20];
    int age;
};

static int write_info(struct person *p) {
    int fd;
    ssize_t ret;

    fd = open("person_file", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if(fd == -1) {
        printf("file open error\n");
        return -1;
    }

    ret = write(fd, p, sizeof(struct person));
    if(ret == -1) {
        printf("file write error\n");
        close(fd);
        return -1;
    }
    else if(ret != sizeof(struct person)) {
        printf("partial write error\n");
        close(fd);
        return -1;
    }
    
    close(fd);
    return 0;
}

static int read_info(void) {
    int fd;
    ssize_t ret;
    struct person p;

    fd = open("person_file", O_RDONLY, 0644);
    if(fd == -1) {
        printf("file open error\n");
        return -1;
    }

    while(1) {
        ret = read(fd, &p, sizeof(struct person));
        if(ret == -1) {
            printf("file write error\n");
            close(fd);
            return -1;
        }
        else if(ret == 0) {
            // EOF
            break;
        }
        else if(ret != sizeof(struct person)) {
            printf("partial read error\n");
            close(fd);
            return -1;
        }

        printf("name = %s, age = %d\n", p.name, p.age);
    }
    

    close(fd);
    return 0;
}

int main(int argc, char **argv) {
    struct person persons[] = {
        {"유영재", 27}, {"김재혁", 26}
    };

    write_info(&persons[0]);
    write_info(&persons[1]);

    read_info();
    return 0;
}
