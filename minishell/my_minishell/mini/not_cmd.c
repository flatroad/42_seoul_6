#include "minishell.h"
#include "./libft/libft.h"

void	not_cmd(char *sv, t_token *token, char **str, t_tool tool)
{
	if (**str == '<' || **str == '>')
		is_redi(sv, token, str, tool);
	else
		not_redi(sv, token, str, tool);
}

void	is_redi(char *sv, t_token *token, char **str, t_tool tool)
{
	if (**str == '<')
	{
		*str++;
		is_leb(sv, token, str, tool);
	}
	else
	{
		*str++;
		is_reb(sv, token, str, tool);
	}
}

void	is_leb(char *sv, t_token *token, char **str, t_tool tool)
{
	if (*str + 1 == '<')
	{
		*str++;
		add_token('<<');
		is_heredoc(sv, token, str, tool);
	}
	else
	{
		add_token('<');
		is_infile(sv, token, str, tool);
	}
}

void	is_heredoc(char *sv, t_token *token, char **str, t_tool tool)
{
	while (**str != ' ' || **str != 0)
		*str++;
	if (**str == 0)
		add_token(NULL);
	while (1)
	{
		if (!(**str == '|' || **str == '&' || **str == '<' || **str == '>' ||\ 
		**str == ' ' || **str == 0))
			add_token(sv);
			return ;
		
	}
}

void	not_redi(char *sv, t_token *token, char **str, t_tool tool)
{
	if (**str == '|')
		is_pipe(sv, token, str, tool);
	else
		not_pipe(sv, token, str, tool);
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
