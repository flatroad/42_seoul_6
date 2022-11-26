/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:14:43 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/26 14:25:27 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	push_queue(t_queue *que, t_err_q err_q, int col, int row)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node) * 1);
	node->next = NULL;
	if (node == NULL)
		error_handle_queue(5, err_q);
	node->x_y[0] = col;
	node->x_y[1] = row;
	node->next = NULL;
	que->count++;
	if (que->first == NULL)
	{
		que->first = node;
		que->last = node;
	}
	else
	{
		que->last->next = node;
		que->last = node;
	}
}

void	pop_queue(t_queue *que)
{
	t_node	*memo;

	que->count--;
	memo = que->first;
	que->first = que->first->next;
	memo->next = NULL;
	free(memo);
	memo = 0;
}
