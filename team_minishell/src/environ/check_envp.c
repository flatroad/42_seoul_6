#include "../../includes/minishell.h"

char	**check_envp(char **envp)
{
	while (strncmp("PATH=", *envp, 5) != 0 && envp != NULL)
		envp++;
	if (envp == NULL)
		return (NULL);
	else
	{
		*envp = *envp + 5;
		return (envp);
	}
}
