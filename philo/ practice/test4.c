#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *thread_ex(void *arg);
int main(){
	int sts;
	pthread_t thread_id;
	void *t_return;
	void** re;

	sts=pthread_create(&thread_id, NULL, thread_ex, NULL);
	sleep(10000000);
	printf("thread_id : %p\n",thread_id);
	printf("%d\n", 123);
	pthread_join(thread_id,(void**)re);
	printf("%123p\n", *re);
	return 0;
}
void *thread_ex(void *arg)
{
	int i = 0;
	while(i<10){
		printf("threading %d\n",i);
		i++;
		if(i==10)
			exit(1);
	}
	return (NULL);
}