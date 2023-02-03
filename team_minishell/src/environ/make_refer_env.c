#include "../../includes/minishell.h"

t_ref_env	*make_refer_env(char **envp)
{
	t_ref_env	*refer_env;

	refer_env = (t_ref_env *)malloc(sizeof(t_ref_env) * 1);
	if (refer_env == NULL)
		return (free_refer_env(0, refer_env));
	if (envp == NULL || envp[0] == NULL)
		return (refer_env);
	refer_env->envp = make_envp(envp);
	if (refer_env->envp == NULL)
		return (free_refer_env(1, refer_env));
	envp = check_envp(envp);
	if (envp == NULL)
		return (refer_env);
	refer_env->path = make_path(envp);
	if (refer_env->path == NULL)
	{	
		free_envp(1, refer_env->envp);
		return (free_refer_env(1, refer_env));
	}
	return (refer_env);
}
