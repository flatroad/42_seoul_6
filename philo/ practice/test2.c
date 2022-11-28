#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void *thread_A(void* arg)
{
	while (1)
	{
		printf("A");
		sleep(1000);
	}
	return (NULL);
}

int main(void)
{
	pthread_t	*thread;

	pthread_create(thread, NULL, thread_A, NULL);

	while (1)
	{
		printf("B");
		sleep(2000);

		
	}
	return 0;
}
