#include "pipex.h"

void	cmd_path(t_obj *pipex, char **argv)
{
	make_cmp_path1(pipex);
	make_cmp_path2(pipex, argv);
	make_cmp_path3(pipex);

}

void	make_cmp_path1(t_obj *pipex)
{
	pipex->cmd_path = (char ***)malloc(sizeof(char **) * pipex->cmd_count + 1);
	if (pipex->cmd_path == NULL)
	{
		perror("error_check6 ");
		free_envp(pipex);
		free(pipex);
		pipex = NULL;
		exit(1);
	}
	pipex->cmd_path[pipex->cmd_count] = 0;
}

void	make_cmp_path2(t_obj *pipex, char **argv)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		pipex->cmd_path[i] = ft_split(argv[pipex->cmd_start + i], ' ');
		if (pipex->cmd_path[i] == 0)
		{
			perror("error_check7 ");
			free_cmd(pipex);
			free_envp(pipex);
			free(pipex);
			pipex = NULL;
			exit(1);
		}
		i++;
	}
}

void	make_cmp_path3(t_obj *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		char	*str;

		str = pipex->cmd_path[i][0];
		pipex->cmd_path[i][0] = ft_strjoin("/", pipex->cmd_path[i][0]);
		free(str);
		if (pipex->cmd_path[i][0] == 0)
		{
			perror("error_check8 ");
			free_cmd_all(pipex);
			free_envp(pipex);
			free(pipex);
			pipex = NULL;
			exit(1);
		}
		i++;
	}
}
