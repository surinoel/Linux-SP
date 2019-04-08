#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
#define PATHNAME "hello_world"
    
    if(link(PATHNAME, "hardlink") == -1) {
        printf("make link error\n");
        return -1;
    }

    if(symlink(PATHNAME, "softlink") == -1) {
        printf("make symbolic link error\n");
        return -1;
    }
   
    return 0;
}
