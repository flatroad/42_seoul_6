/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:04:29 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/29 02:13:40 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_list(t_list *command, int argc)
{
	static char	*order[] = {"sa", "sb", "ss", "pa", "pb", \
	"ra", "rb", "rr", "rra", "rrb", "rrr"};

	if (argc <= 10)
		command->max = 100;
	else if (argc <= 100)
		command->max = 1000;
	else
		command->max = 10000;
	if (init_cmd(command, command->max) == FALSE)
		return (FALSE);
	command->start = command->cmd_ad;
	command->order = order;
	return (TRUE);
}

int	init_cmd(t_list *command, int max)
{
	t_cmd	*cmd_ad;

	cmd_ad = (t_cmd *)malloc(sizeof(cmd_ad) * 1);
	if (cmd_ad == NULL)
		return (FALSE);
	cmd_ad->cmd = (char **)malloc(sizeof(char *) * (max + 1));
	if (cmd_ad->cmd == NULL)
	{
		free(cmd_ad);
		cmd_ad = 0;
		return (FALSE);
	}
	cmd_ad->cmd[max] = 0;
	cmd_ad->cmd[0] = "ㅇㅕ기까지";
	cmd_ad->max = max;
	cmd_ad->next = NULL;
	cmd_ad->top = -1;
	command->cmd_ad = cmd_ad;
	return (TRUE);
}

void	init_parse(int *argc, char ***argv)
{
	*argc = *argc - 1;
	(*argv)++;
}

void	init_stack(t_stack *a_stk, t_stack *b_stk)
{
	a_stk->bottom = NULL;
	a_stk->top = NULL;
	a_stk->idx = 0;
	b_stk->bottom = NULL;
	b_stk->top = NULL;
	b_stk->idx = 0;
}