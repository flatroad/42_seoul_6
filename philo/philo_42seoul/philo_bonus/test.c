#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

typedef struct philo
{
	pid_t pid;
	int	num;
	int j;
	int *k;
} philo;

sem_t *sem;
sem_t *test;

void routine(philo a)
{
	printf("%p\n", a.k);
	while (a.j < 3)
	{
		// 모니터링 쉘;
		sem_wait(sem); // 세마포어 lock
		sem_wait(sem);
		printf("%d uses semaphore %d %d\n", a.num, a.j, *a.k);
		a.j++;
		sem_wait(test);
		(*a.k)++;
		sem_post(test);
		sem_post(sem); // 세마포어 unlock
		sem_post(sem);
	}
	exit(0);
}

int main(void)
{
	int i = 0;
	philo *a;
	int *m = malloc(sizeof(int));

	a = (philo *)malloc(sizeof(philo) * 20);
	if (a == NULL)
	{
		printf("fail\n");
		return (0);
	}
	while (i < 20)
	{
		a[i].k = m;
		printf("%d\n", *(a[i].k));
		i++;
	}
	sleep(1);
	sem = sem_open("test_a", O_CREAT, 0644, 20); // value(counter)가 3인 세마포어 생성
	sem = sem_open("test_sem", O_CREAT, 0644, 1); // value(counter)가 3인 세마포어 생성

	sem_unlink ("test_a");
	sem_unlink ("test_sem");
	if (sem == SEM_FAILED) // 세마포어 생성 실패시
	{
		fprintf(stderr, "sem errro\n");
		return (-1);
	}
	i = 0;
	while (i < 20)
	{
		a[i].pid = fork();
		if (a[i].pid == -1)
		{
			printf("fork fail\n");
			return (0);
		}
		else if(a[i].pid == 0)
		{
			a[i].num = i;
			a[i].j = 0;
			routine(a[i]);
		}
		else
			i++;
	}

	i = 0;
	while (i < 20)
	{
		waitpid(a[i].pid, 0, 0);
		i++;
	}
	exit(0);
}