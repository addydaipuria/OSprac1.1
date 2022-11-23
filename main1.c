#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

long long jesse;
struct timespec walter1;
struct timespec walter2;
struct timespec walter3;
struct timespec walter4;
struct timespec walter5;
struct timespec walter6;

void countmeth(){
  long long meth=1;
  for(int i=1;i<=32;i++){
    meth=meth*2;
  }
  jesse=meth;
}

void *countA(){
  int hank=0;
  clock_gettime(CLOCK_MONOTONIC,&walter1);
  while(hank<jesse){
    hank++;
  }
  clock_gettime(CLOCK_MONOTONIC,&walter2);
  printf("%ld sec, %ld nanosec",walter2.tv_sec-walter1.tv_sec,walter2.tv_nsec-walter1.tv_nsec);
}
void *countB(){
  int hank=0;
  clock_gettime(CLOCK_MONOTONIC,&walter3);
  while(hank<jesse){
    hank++;
  }
  clock_gettime(CLOCK_MONOTONIC,&walter4);
  printf("%ld sec, %ld nanosec",walter4.tv_sec-walter3.tv_sec,walter4.tv_nsec-walter3.tv_nsec);
}
void *countC(){
  int hank=0;
  clock_gettime(CLOCK_MONOTONIC,&walter5);
  while(hank<jesse){
    hank++;
  }
  clock_gettime(CLOCK_MONOTONIC,&walter6);
  printf("%ld sec, %ld nanosec",walter6.tv_sec-walter5.tv_sec,walter6.tv_nsec-walter5.tv_nsec);
}
int main (){
  countmeth();
  pthread_t realone;
  pthread_t realtwo;
  pthread_t realthree;
  pthread_attr_t talkone;
  pthread_attr_t talktwo;
  pthread_attr_t talkthree;

  sched_param schedparam;
 
  schedparam.sched_priority = 3;
  
  pthread_attr_init(&talkone);
  pthread_attr_setinheritsched(&talkone, PTHREAD_EXPLICIT_SCHED);
  pthread_attr_setschedpolicy(&talkone, SCHED_OTHER);
  pthread_attr_setschedparam(&talkone, &schedparam);
  pthread_create(&realone,NULL,countA,NULL);  

  pthread_attr_init(&talktwo);
  pthread_attr_setinheritsched(&talktwo, PTHREAD_EXPLICIT_SCHED);
  pthread_attr_setschedpolicy(&talktwo, SCHED_FIFO);
  pthread_attr_setschedparam(&talktwo, &schedparam);
  pthread_create(&realtwo,NULL,countB,NULL);

  pthread_attr_init(&talkthree);
  pthread_attr_setinheritsched(&talkthree, PTHREAD_EXPLICIT_SCHED);
  pthread_attr_setschedpolicy(&talkthree, SCHED_RR);
  pthread_attr_setschedparam(&talkthree, &schedparam);
  pthread_create(&realthree,NULL,countC,NULL);
  
  pthread_join(realone,NULL);
  pthread_join(realtwo,NULL);
  pthread_join(realthree,NULL);
}


