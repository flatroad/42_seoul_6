#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
 
// thread_function
// 1초를 기다린 이후
// 매개변수 * 매개변수를 return 한다.
void *thread_function(void *data){
        int num = *((int *) data);
        printf("Num : %d \n", num);
        sleep(1);
        num *= num;
        printf("thread function end\n");
        return (void *)(num);
}
 
int main(){
        pthread_t p_thread;
        int thr_id;
        int result;
        int a = 200;
        thr_id = pthread_create(&p_thread, NULL, thread_function, (void *) &a);
        if(thr_id < 0){
                perror("thread create error");
                exit(0);
        }
 
        // 쓰레드 식별자 p_thread가 종료되길 기다렸다가
        // 종료 후에 리턴 값을 받아온다.
        pthread_join(p_thread, (void *) &result);
        printf("thread join : %d\n", result);
 
        printf("Main() 종료 \n");
 
        return 0;
}