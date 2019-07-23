#if 0

SYNOPSIS
       #include <unistd.h>
       unsigned int alarm(unsigned int seconds);

DESCRIPTION
       alarm() arranges for a SIGALRM signal to be delivered to the calling process in seconds seconds.
       If seconds is zero, any pending alarm is canceled.
       In any event any previously set alarm() is canceled.

RETURN VALUE
       alarm()  returns the number of seconds remaining until any previously scheduled alarm was due to be delivered, or zero if there was no previously scheduled
       alarm.
       
alarm의 반환값은 전 알람 정보가 있는지 알려준다. 만일 있다면 남아있는 시간을 출력하고, 이전 알람이 없다면 0을 반환하다
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int ret;
  printf("trying to make alarm timer ..... \n");
  ret = alarm(5);
  
  if(ret) {
    printf("old timer exits\n remaining time : %d\n", ret);
  }
  else {
    printf("old timer not exist\n");
  }
  
  sleep(2);
  
  printf("trying to make alarm timer ..... \n");
  ret = alarm(5);
  
  if(ret) {
    printf("old timer exits\n remaining time : %d\n", ret);
  }
  else {
    printf("old timer not exist\n");
  }
  
  while(1) {
    sleep(1);
  }
  
  return 0;
}
