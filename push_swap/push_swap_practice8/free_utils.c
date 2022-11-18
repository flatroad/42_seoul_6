/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choinagi <choinagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:47:29 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 13:47:31 by choinagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *s)
{
	t_node	*node;

	while (s->bot != NULL)
	{
		node = s->bot;
		s->bot = s->bot->prev;
		node->prev = NULL;
		if (s->bot != NULL)
			s->bot->next = NULL;
		free(node);
	}
	if (s->top != NULL)
		s->top = NULL;
	free(s);
}

void	free_info(t_a_b **info)
{
	free_stack((*info)->a_stack);
	free_stack((*info)->b_stack);
	free(*info);
	*info = NULL;
}

void	free_arr(int *arr)
{
	free(arr);
	arr = NULL;
}
