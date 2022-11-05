/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:40:17 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/29 08:47:30 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a_stk;
	t_stack	b_stk;

	if (argc == 1)
		return (0);
	init_parse(&argc, &argv);
	init_stack(&a_stk, &b_stk);
	if (pull_a_stack(&a_stk, argc, argv) == FALSE || \
	push_swap(&a_stk, &b_stk, argc) == FALSE)
	{
		free_all(&a_stk, &b_stk);
		write(2, "ERROR\n", 6);
		return (1);
	}
	free_all(&a_stk, &b_stk);
	system("leaks push_swap");
	return (0);
}
