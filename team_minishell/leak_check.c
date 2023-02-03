#include <stdlib.h>
#include <unistd.h>

int main()
{
	int i;

	i = 0;
	while (i < 100)
	{
		sleep(10);
		system("leaks minishell");
		i++;
	}
}
