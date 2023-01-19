#include "minishell.h"

void	minishell(char **envp);
char	**mk_path(char **envp);
void	set_mini(t_tool tool);
void	mk_cmd(char *str, t_tool tool);
char	**ft_split(char const *s, char c);

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1)
	{
		write(2, "ERROR\nAn incorrect execution\n", 30);
		return (1);
	}
	minishell(envp);
	return (0);
}

void	minishell(char **envp)
{
	t_tool tool;

	tool.envp = envp;
	tool.path = mk_path(envp);

	set_mini(tool);
}

char	**mk_path(char **envp)
{
	char	**path;

	while (strncmp("PATH=", *envp, 5) != 0)
		envp++;
	*envp = *envp + 5;
	path = ft_split(*envp, ':');
	if (path == NULL)
	{
		perror("envp_path error1 ");
		exit(1);
	}
	return (path);
}

void	set_mini(t_tool tool)
{
	char	*str;

	while (1)
	{
		str = readline("prompt > ");
		add_history(str);
		mk_cmd(str, tool);
		free(str);
		
	}
}

void	mk_cmd(char *str, t_tool tool)
{
	t_token	*token;
	char	*sv_str;

	sv_str = str;
	while (*str != 0)
	{
		mk_token(*str, token, &str, tool);
	}
}

void	mk_token(char c, t_token *token, char **str, t_tool tool)
{
	if (!(c == '<' || c == '>' || c == '|' || c == '&' ||\
	c == ' ' || c == '*' || c == '$' || c == '\'' || c == '\"'))
		is_uncmd(c, token, str, tool);
	else
		is_cmd(c, token, str, tool);
}


void	is_cmd(char c, t_token *token, char **str, t_tool tool)
{
	char	*sv;
	int 	i;

	i = 0;
	while (1)
	{
		while (*str[i] != '<' || *str[i] != '>' || *str[i] = '|' || *str[i] = '&' ||\
		c == ' ' || c == )
			i++;

	}

	
}

void	is_uncmd(char c, t_token *token, char **str, t_tool tool)
{
	if (c == '<' || c == '>')
		is_redi(c, token, str, tool);
	else
		is_unredi(c, token, str, tool);
}

void	is_redi(char c, t_token *token, char **str, t_tool tool)
{
	if (c == '<')
		is_rredi(c, token, str, tool);
	else
		is_lredi(c, token, str, tool);
}

void	unredi(char c, t_token *token, char **str, t_tool tool)
{
	if (c == '|')
		is_pipe(c, token, str, tool);
	else
		is_unpipe(c, token, str, tool);
}

void	is_pipe(c, token, str, tool);
{
	if (*str + 1 == '|')
		add_token('||');
	else
	{
		str++;
		add_token('|');
	}	
}

void	is_unpipe(char c, t_token *token, char **str, t_tool tool)
{
	if (*str == '&')
		is_and(c, token, str, tool);
	else
		is_unand(c, token, str, tool);
}

void	is_and(char c, t_token *token, char **str, t_tool tool)
{
	if (*str + 1 == '&')
		add_token('&&');
	else
		is_cmd

}

void	is_unand


void	mk_token(void)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token) * 1);
	token->next = 0;
	token->order = 0;
	token->type_num = 0;
	token->value = 0;
}
