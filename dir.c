/*
 디렉토리의 파일 다루기
 DIR *opendir(const char *name);

 파라미터
 - name : 파일 경로

 반환값
 - 성공 시 열린 디렉토리 스트림 포인터
 - 실패 시 NULL 포인터

struct dirent *readdir(DIR *dirp);

파라미터 
- dirp : 디렉토리 스트림 포인터

반환값
- 성공 시 디렉토리 엔트리 포인터
- 실패 시 NULL 포인터

struct dirent {
    ino_t           d_ino;      // inode number
    off_t           d_off;

    unsigned short  d_reclen;   // record length
    unsigned char   d_type;     // 예제에서 다룰 것
    char            d_name[256];
};   
 
int closedir(DIR *dirp);

파라미터
- dirp : 디렉토리 스트림 포인터

반환값
- 성공 시 0
- 실패 시 -1
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

#define TYPE2STR(X) \
   (((X)) == DT_BLK ? "block device" : \
    ((X)) == DT_CHR ? "char device" : \
    ((X)) == DT_DIR ? "directory" : \
    ((X)) == DT_FIFO ? "fifo" : \
    ((X)) == DT_LNK ? "symlink" : \
    ((X)) == DT_REG ? "regular file" : \
    ((X)) == DT_SOCK ? "socket" : \
    "unknown")

int main(int argc, char **argv) {
    DIR *dp;
    struct dirent *entry;

    dp = opendir("."); // 현재 디렉토리
    if(dp == NULL) {
        printf("opendir() fail\n");
        return -1;
    }
    
    while((entry = readdir(dp))) {
       printf("%s = %s\n",
                entry->d_name,
                TYPE2STR(entry->d_type));
    }
    
    closedir(dp);
    return 0;
}







