#include "../minishell.h"
#include "../libft/libft.h"

int	export(char **exp_str, t_refer_env *refer_env);
t_envp_list	*make_exp(char **exp_str);
t_envp_list	*check_exp_str(char *str);
t_envp_list	*is_exp_null(void);
t_envp_list	*not_exp_null(char *str);
t_envp_list	*is_pair(char *str, int	i);
t_envp_list	*is_single(char	*str);
void	out_export(t_refer_env *refer_env);

int main()
{
	char **str;

	str = malloc(sizeof(char *) * 4);
	str[0] = "a=b";
	str[1] = "a=";
	str[2] = "adf";
	str[3] = NULL;
	export(str, NULL);

	return (0);
}

int	export(char **exp_str, t_refer_env *refer_env)
{
	t_envp_list *exp;

	if (exp_str == NULL)
	{
		out_export(refer_env);
		return (0);
	}
	exp = make_exp(exp_str);
	if (exp == NULL)
		return (1);
	output_exp(exp);
	while (exp != NULL)
	{
		printf("key %s\n", exp->key);
		printf("value %s\n", exp->value);
		exp = exp->next;
	}
	return (0);
}

t_envp_list	*make_exp(char **exp_str)
{
	int	i;
	t_envp_list	*exp;
	t_envp_list	*memo;

	i = 1;
	memo = check_exp_str(exp_str[0]);
	if (memo == NULL)
		return (NULL);
	exp = memo;
	while (exp_str[i] != 0)
	{
		memo->next = check_exp_str(exp_str[i]);
		if (memo->next == NULL)
		{
			write(2, "Error, export malloc fail..\n", 26);
			free_exp(exp);
			return (NULL);
		}
		memo = memo->next;
		i++;
	}
	return (exp);
}

t_envp_list	*check_exp_str(char *str)
{
	t_envp_list	*exp;

	if (str[0] == 0)
		exp = is_exp_null();
	else
		exp = not_exp_null(str);
	if (exp == NULL)
		return (NULL);
	return (exp);
}

t_envp_list	*is_exp_null(void)
{
	t_envp_list	*exp;

	exp = malloc(sizeof(t_envp_list) * 1);
	if (exp == NULL)
		return (NULL);
	exp->key = NULL;
	exp->value = NULL;
	exp->next = NULL;
	return (exp);
}

t_envp_list	*not_exp_null(char *str)
{
	int			i;
	t_envp_list	*exp;

	i = 0;
	while (str[i] != '=' && str[i] != 0)
		i++;
	if (str[i] == '=')
		exp = is_pair(str, i);
	else
		exp = is_single(str);
	if (exp == NULL)
		return (NULL);
	return (exp);
}

t_envp_list	*is_pair(char *str, int	i)
{
	t_envp_list	*exp;

	exp = (t_envp_list *)malloc(sizeof(t_envp_list) * 1);
	if (exp == NULL)
		return (NULL);
	exp->key = ft_substr(str, 0, i);
	if (exp->key == NULL)
		return (NULL);
	if (strlen(str + i + 1) == 0)
	{
		exp->value = malloc(sizeof(char) * 1);
		exp->value[0] = 0;
	}
	else
		exp->value = ft_substr(str, i + 1, strlen(str + i + 1));
	if (exp->value == NULL)
		return (NULL);
	exp->next = NULL;
	return (exp);
}

t_envp_list	*is_single(char	*str)
{
	t_envp_list	*exp;

	exp = (t_envp_list *)malloc(sizeof(t_envp_list) * 1);
	if (exp == NULL)
		return (NULL);
	exp->key = ft_substr(str, 0, strlen(str));
	if (exp->key == NULL)
		return (NULL);
	exp->value = NULL;
	exp->next = NULL;
	return (exp);
}

void	out_export(t_refer_env *refer_env)
{
	t_envp_list *memo;

	memo = refer_env->envp;
	while (memo != NULL)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(memo->key, 1);
		if (memo->value != NULL)
		{
			ft_putstr_fd("=", 1);
			ft_putendl_fd(memo->value, 1);
		}
		memo = memo->next;
	}
}

void	free_exp(t_envp_list *exp)
{
	t_envp_list	*memo;	

	while (exp != NULL)
	{
		if (exp->key != NULL)
			free(exp->key);
		if (exp->value != NULL)
			free(exp->value);
		memo = exp;
		exp = exp->next;
		free(memo);
	}
}