/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 05:52:02 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/28 23:45:12 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	command;
	t_utils	utilz;
	t_stack	a_stk;
	t_stack	b_stk;

	if (argc == 1)
		return (0);
	if (init_list(&command, argc) == FALSE)
		return (1);
	init_utils(&utilz, argc, argv);
	init_stack(&a_stk, &b_stk);
	if (push_swap(a_stk, b_stk, utilz, command) == FALSE)
	{
		free_all(&a_stk, &b_stk, command);
		write(2, "ERROR\n", 6);
		return (1);
	}
	return (0);
}

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
	command->cmd = (t_cmd *)malloc(sizeof(t_cmd) * (command->max + 1));
	if (command->cmd == NULL)
		return (FALSE);
	if (init_cmd(command->cmd, command->max) == FALSE)
	{
		free(command->cmd);
		command->cmd = 0;
		return (FALSE);
	}
	command->order = order;
	return (TRUE);
}

int	init_cmd(t_cmd *list, int max)
{
	list->cmd = (char **)malloc(sizeof(char *) * (max + 1));
	if (list->cmd == NULL)
		return (FALSE);
	list->cmd[max] = 0;
	list->max = max;
	list->top = -1;
	list->next = NULL;
	return (TRUE);
}

void	init_utils(t_utils *utilz, int argc, char **argv)
{
	utilz->argc = argc;
	utilz->argv = argv;
}

void	init_stack(t_stack *a_stk, t_stack *b_stk)
{
	a_stk->bottom = NULL;
	a_stk->top = NULL;
	a_stk->idx = -1;
	b_stk->bottom = NULL;
	b_stk->top = NULL;
	b_stk->idx = -1;
}
