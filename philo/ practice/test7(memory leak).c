#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
 
void *thread_test(void * data){
 
 
    char * str = (char*)malloc(sizeof(1024));
    printf("ThreadStart\n");
 
    sleep(5);
 
    printf("TrheadEnd\n");
    return NULL;
 
}
 
int main(void){
 
    pthread_t pid;
 
     pthread_create(&pid, NULL, thread_test, NULL);
 
    
    if(pid<0){
 
        perror("pthread_create error");
 
        exit(0);
 
    }
    system("leaks a.out");
    sleep(10);
 
    return 0;
 
}