#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>


void *countA(){
  long long int a;
  for(long long int i=1;i<4294967296;i++){
    continue;
  }
}

void *countB(){
  long long int a;
  for(long long int i=1;i<4294967296;i++){
    continue;
  }
}


void *countC(){
  long long int a;
  for(long long int i=1;i<4294967296;i++){
    continue;
  }
}


int main(){
  pthread_t thread_A,thread_B,thread_C;
  struct sched_param param;
  FILE *ptr=fopen("data.txt","w");
  clock_t secA,secB,secC;
  //A
  secA=clock();
//  printf("Before Thread A\n");
  pthread_create(&thread_A, NULL, countA, NULL);
  pthread_create(&thread_A, NULL, countB, NULL);
  pthread_create(&thread_A, NULL, countC, NULL);
  int rca=pthread_setschedparam(thread_A,SCHED_OTHER,&param);
  if(rca==0){
  //  printf("created A\n");
  }
  pthread_join(thread_A, NULL);
 // printf("After Thread A\n\n");
  secA=clock()-secA;
  double ans=((double)secA)/CLOCKS_PER_SEC;
  fprintf(ptr,"%f\n",ans);
  secA=clock();
  pthread_setschedprio(thread_A,1);
  pthread_join(thread_A, NULL);
  secA=clock()-secA;
  ans=((double)secA)/CLOCKS_PER_SEC;
  fprintf(ptr,"%f\n",ans);
  secA=clock();
  pthread_setschedprio(thread_A,2);
  pthread_join(thread_A, NULL);
  secA=clock()-secA;
  ans=((double)secA)/CLOCKS_PER_SEC;
  fprintf(ptr,"%f\n",ans);
  secA=clock();
  pthread_setschedprio(thread_A,3);
  pthread_join(thread_A, NULL);
  secA=clock()-secA;
  ans=((double)secA)/CLOCKS_PER_SEC;
  fprintf(ptr,"%f\n",ans);
  //B
  secB=clock();
  //printf("Before Thread B\n");
  pthread_create(&thread_B, NULL, countA, NULL);
  pthread_create(&thread_B, NULL, countB, NULL);
  pthread_create(&thread_B, NULL, countC, NULL);
  int rcb=pthread_setschedparam(thread_B,SCHED_FIFO,&param);
  if(rcb==0){
  //  printf("created B\n");
  }
  pthread_join(thread_B, NULL);
  //printf("After Thread B\n\n");
  secB=clock()-secB;
  ans=((double)secB)/CLOCKS_PER_SEC;
  fprintf(ptr,"%f\n",ans);
  secB=clock();
  pthread_setschedprio(thread_B,1);
  pthread_join(thread_B, NULL);
  secB=clock()-secB;
  ans=((double)secB)/CLOCKS_PER_SEC;
  fprintf(ptr,"%f\n",ans);
  secB=clock();
  pthread_setschedprio(thread_B,2);
  pthread_join(thread_B, NULL);
  secB=clock()-secB;
  ans=((double)secB)/CLOCKS_PER_SEC;
  fprintf(ptr,"%f\n",ans);
  secB=clock();
  pthread_setschedprio(thread_B,3);
  pthread_join(thread_B, NULL);
  secB=clock()-secB;
  ans=((double)secB)/CLOCKS_PER_SEC;
  fprintf(ptr,"%f\n",ans);
  //C
  secC=clock();
  //printf("Before Thread C\n");
  pthread_create(&thread_C, NULL, countA, NULL);
  pthread_create(&thread_C, NULL, countB, NULL);
  pthread_create(&thread_C, NULL, countC, NULL);
  int rcc=pthread_setschedparam(thread_C,SCHED_RR,&param);
  if(rcc==0){
  //  printf("created C\n");
  }
  pthread_join(thread_C, NULL);
  //printf("After Thread C\n\n");
  secC=clock()-secC;
  ans=((double)secC)/CLOCKS_PER_SEC;
  fprintf(ptr,"%f\n",ans);
  secC=clock();
  pthread_setschedprio(thread_C,1);
  pthread_join(thread_C, NULL);
  secC=clock()-secC;
  ans=((double)secC)/CLOCKS_PER_SEC;
  fprintf(ptr,"%f\n",ans);
  secC=clock();
  pthread_setschedprio(thread_C,2);
  pthread_join(thread_C, NULL);
  secC=clock()-secC;
  ans=((double)secC)/CLOCKS_PER_SEC;
  fprintf(ptr,"%f\n",ans);
  secC=clock();
  pthread_setschedprio(thread_C,3);
  pthread_join(thread_C, NULL);
  secC=clock()-secC;
  ans=((double)secC)/CLOCKS_PER_SEC;
  fprintf(ptr,"%f\n",ans);
  return 0;
}
