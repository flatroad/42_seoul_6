#include "minishell.h"
#include "./libft/libft.h"

t_redirect	*redirect(t_token *token, t_redirect *redirect)
{
	int			fd;
	t_redirect	*redi;

	fd = -1;
	if (token->type == 13)
		fd = open(token->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (token->type == 14)
		fd = open(token->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
	redi->infile = fd;
	if (token->type == 15)
		fd = open(token->content, O_RDONLY, 0644);
	redi->outfile = fd;
	if (token->type == 16)
		fd
}

t_exec	*exec_mini(t_cmd *cmd, t_exec_mini)
{
	
}

t_cmd	*exec_cmd(t_token *token, t_redirect *redi)
{
	
}