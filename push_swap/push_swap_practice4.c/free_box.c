/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:03:46 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/29 05:08:11 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *a, t_stack *b, t_list *command)
{
	free_stack(a);
	free_stack(b);
	free_command(command);
}

void	free_stack(t_stack *stk)
{
	t_node	*memo;

	while (stk->top != NULL)
	{
		printf("%d\n", stk->top->data);
		memo = stk->top;
		stk->top = stk->top->prev;
		memo->prev = NULL;
		if (stk->top != NULL)
			stk->top->next = NULL;
		free(memo);
	}
	if (stk->bottom != NULL)
		stk->bottom = NULL;
}

void	free_command(t_list *command)
{
	t_cmd	*memo;
	int		i;

	i = 0;
	printf("%p\n", command->start);
	printf("%p\n", command->start->next);
	printf("%p\n", command->cmd_ad);
	printf("%p\n", command->cmd_ad->cmd[0]);
	while (command->start != NULL)
	{
		printf("%s\n", command->start->cmd[i]);
		while (command->start->cmd[i] != 0)
		{
			printf("%d\n", 123);
			printf("%s\n", command->start->cmd[i]);
			i++;
		}
		printf("%d\n", 123);
		memo = command->start;
		command->start = command->start->next;
		memo->next = NULL;
		free(memo->cmd);
		memo->cmd = 0;
		free(memo);
		memo = 0;
	}
	command->cmd_ad = NULL;
}
