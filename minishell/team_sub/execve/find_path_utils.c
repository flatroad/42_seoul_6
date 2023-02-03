#include "../minishell.h"
#include "../libft/libft.h"

void	free_find_path(t_fork *fork)
{
	t_fork	*memo;

	while (fork != NULL)
	{
		if (fork->full_path != NULL)
			free(fork->full_path);
		memo = fork;
		fork = fork->next;
		free(memo);
	}
}

char	*ft_strjoin_three(char *str_f, char *str_s, char *str_t)
{
	char	*str;
	char	*str_final;

	str = ft_strjoin(str_f, str_s);
	if (str == NULL)
		return (NULL);
	str_final = ft_strjoin(str, str_t);
	if (str_final == NULL)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (str_final);
}
