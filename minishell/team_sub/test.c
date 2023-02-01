# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdio.h>
# include <string.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <errno.h>
# include <dirent.h>

int	main()
{
	char **a;

	a = (char **)malloc(sizeof(char *) * 2);
	a[0] = "zzzz";
	a[1] = NULL;

	execve(a[0], a, NULL);
	printf("%s\n", "error");
}
