/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 05:52:02 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/28 06:17:17 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*command;
	t_utils	utilz;
	t_stack	a_stk;
	t_stack	b_stk;

	command = (t_list *)malloc(sizeof(t_list) * 1);
	if (command == NULL)
		return (1);
	if (init_list(command, argc) == FALSE)
	{
		free(command);
		command = 0;
		return (1);
	}
	init_utils(&utilz, argc, argv);
	init_stack(&a_stk);
	init_stack(&b_stk);
	if (push_swap(a_stk, b_stk, utilz, command) == FALSE)
	{
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
	command->cmd = (char **)malloc(sizeof(char *) * command->max + 1);
	if (command->cmd == NULL)
		return (FALSE);
	command->cmd[command->max] = 0;
	command->start = command->cmd;
	command->next = NULL;
	command->order = order;
	command->top = -1;
	return (TRUE);
}

void	init_utils(t_utils *utilz, int argc, char **argv)
{
	utilz->argc = argc;
	utilz->argv = argv;
}

void	init_stack(t_stack *stk)
{
	stk->bottom = NULL;
	stk->top = NULL;
	stk->idx = -1;
}
