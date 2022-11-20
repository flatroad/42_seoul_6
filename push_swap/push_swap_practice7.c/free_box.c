/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:03:46 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/29 08:17:19 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

void	free_stack(t_stack *stk)
{
	t_node	*memo;

	while (stk->top != NULL)
	{
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

str = 0;
strlen(str) 길이 몇 
a가 2이상이고
*str == 0일 때 에러처리.