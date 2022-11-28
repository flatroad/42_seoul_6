#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void *add(void *arg);
int i = 0;

int main()
{
	pthread_t p_1, p_2;
	void *a;

	pthread_create(&p_1, NULL, (add), (void *)"p_1");
	// sleep(1);
	usleep(50000);
	pthread_create(&p_1, NULL, (add), (void *)"p_2");

	pthread_join(p_1, a);
	pthread_join(p_2, a);
	return (0);
}

void *add(void *arg)
{
	printf("%d", i);
	while(i < 100)
	{
		usleep(100000);
		printf("%s %d\n", (char *)arg, i);
		i++;
	}
	return (NULL);
}
