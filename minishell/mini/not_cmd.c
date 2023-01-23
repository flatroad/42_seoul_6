#include "minishell.h"
#include "./libft/libft.h"

void	not_cmd(char *sv, t_token *token, char **str, t_tool tool)
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