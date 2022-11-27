
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int sum;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
void *sum1(void* num){
	int n=*((int *)num);
	for(int i=0;i<n;i++){
		pthread_mutex_lock(&mutex);
		sum++;
		printf("sum1:%d\n",sum);
		pthread_mutex_unlock(&mutex);
		sleep(0.3);
	}
}
void *sum2(void *num){
	int n=*((int*)num);
	for(int i=0;i<n;i++){
		
		pthread_mutex_lock(&mutex);
		sum++;
		printf("sum2:%d\n",sum);
		pthread_mutex_unlock(&mutex);
		sleep(0.3);
	}
}
int main(){
	int thread;
	pthread_t p_thread[2];
	int sts;
	int arg;
	sum=0;
	arg=5;
	thread=pthread_create(&p_thread[0],NULL,sum1,(void *)&arg);
	thread=pthread_create(&p_thread[1],NULL,sum2,(void *)&arg);
	pthread_join(p_thread[0],(void**)&sts);
	pthread_join(p_thread[1],(void**)&sts);
	sts=pthread_mutex_destroy(&mutex);
	
	return 0;
	
}