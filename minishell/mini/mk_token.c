#include "minishell.h"
#include "./libft/libft.h"


void	mk_cmd(char *str, t_tool tool)
{
	t_token	*token;
	char	*sv;
	char	*start_str;

	start_str = str;
	while (*str != 0)
	{
		sv = (char *)malloc(sizeof(char) * 1);
		sv[0] = 0;
		mk_token(sv, token, &str, tool);
	}
	free(start_str);
}

void	mk_token(char *sv, t_token *token, char **str, t_tool tool)
{
	while (**str != 0)
	{
		if (!(**str == '<' || **str == '>' || **str == '|'))
			is_cmd(sv, token, str, tool);
		else
			not_cmd(sv, token, str, tool);
	}
}

void	is_cmd(char *sv, t_token *token, char **str, t_tool tool)
{
	while (**str != 0)
	{
		if (**str == ' ')
			is_space(sv, token, str, tool);
		else
			not_space(sv, token, str, tool);
	}
}

void	is_space(char *sv, t_token *token, char **str, t_tool tool)
{
	check_add_token(sv, token, str, tool);
	*str++;
}

void	not_space(char *sv, t_token *token, char **str, t_tool tool)
{
	if (**str == '&' && (**str + 1) == '&')
		is_and(sv, token, str, tool);
	else
		not_and(sv, token, str, tool);
}

void	is_and(char *sv, t_token *token, char **str, t_tool tool)
{
	check_add_token(sv, token, str, tool);
	add_token('&&');
	*str = *str + 2;
}

void	not_and(char *sv, t_token *token, char **str, t_tool tool)
{
	if (**str == '$')
		is_env(sv, token, str, tool);
	else
		not_env(sv, token, str, tool);
}

void	is_env(char *sv, t_token *token, char **str, t_tool tool)
{
	char	*env_sv;
	int		i;

	i = 0;
	while (**str != ' ' || **str != 0 || **str != '\"' || **str != '\'')
		i++;
	if (i == 0)
	{
		if(*(*str + 1) == ' ' || *(*str + 1) == 0)
			
	}
	env_sv = ft_substr(*str, 0, i);
	check_env(&sv, env_sv, tool);
}

void	check_env(char **sv, char *env_sv, t_tool tool)
{
	int		i;
	int		len;
	char	*memo;

	i = 0;
	len = ft_strlen(env_sv);
	while (tool.envp[i] != NULL)
	{
		if (ft_strnstr(tool.envp[i], env_sv, len) == NULL)
			i++;
		else 
		{
			if (tool.envp[i] + len + 1 == '=')
			{
				memo = *sv;
				*sv = ft_strjoin(*sv, (tool.envp[i] + len + 2))
				free(memo);
				return ;
			}
			else
				 i++;
		}
	}
}

void	check_add_token(char *sv, t_token *token, char **str, t_tool tool)
{
	if (sv[0] != 0)
		add_token(sv);
	free(sv);
}
