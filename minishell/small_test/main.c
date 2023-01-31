#include "minishell.h"
#include "./libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
	t_refer_env *refer_env;
	t_wc_list	*list;
	t_token	*token;

	token = malloc(sizeof(t_token) * 1);
	token->content = "A";
	token->type = 13;
	token->next = malloc(sizeof(t_token) * 1);
	token->next->content = "AAAAA";
	token->next->type = 13;
	token->next->next = NULL;
	if (argc != 1)
	{
		write(2, "ERROR\nAn incorrect execution\n", 30);
		return (1); 
	}
	refer_env = make_refer_env(envp);
	if (refer_env == NULL)
		return (1);

	list = wildcard("*", token);
	while (list != NULL)
	{
		printf("%s\n", list->str);
		list = list->next;
	}
	cd("/Applications", refer_env);
	while (refer_env->envp != NULL)
	{
		printf("%s = %s\n", refer_env->envp->key, refer_env->envp->value);
		refer_env->envp = refer_env->envp->next;
	}
	return (0);
}
