# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

void *gettime(void *at);

int main()
{
	int i;

	i = 10;
	pthread_t pid;
	struct timeval *s_t;
	gettimeofday(s_t, NULL);
	while(i)
	{
		pthread_create(&pid, NULL, gettime, (void *)s_t);
		i--;
	}
	printf("%d\n", 123);
	sleep(10);
	return (0);
}

void *gettime(void *at)
{
	int i;

	i = 10;
	printf("%d\n", i);
	usleep(100);
	printf("%d\n", i);

	i = i + 10;
	sleep(1);
	printf("%d\n", i);
	return (0);
}
