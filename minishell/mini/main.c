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
		
	}
}

void	mk_cmd(char *str, t_tool tool)
{
	t_token	*token;
	int	i;

	i = 0;
	while (*str == 0)
	{
		is_str(str[i], token, str);
	}

}

char	*is_str(char c, t_token *token, char *str)
{
	char *s;
	int i;
	
	i = 0;
	if (!(c == '<' || c == '>' || c == '|' || c == '&' ||\
	c == ' ' || c == '*' || c == '$' || c == '\'' || c == '\"'))
		is_redi(c, token, str);
	while (str[i] != (c == '<' || c == '>' || c == '|' || c == '&' ||\
	c == ' ' || c == '*' || c == '$' || c == '\'' || c == '\"'))
		i++;
	s = ft_substr(str, 0, i);

	
}

void	mk_token(void)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token) * 1);
	token->next = 0;
	token->order = 0;
	token->type_num = 0;
	token->value = 0;
}
