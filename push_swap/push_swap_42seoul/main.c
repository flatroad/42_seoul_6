/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:47:59 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 17:54:20 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	int		*arr;
	t_a_b	*info;

	if (ac < 2)
		return (0);
	info = new_info();
	data_parsing(info, ac, av);
	if (info->a_stack->size == 1)
		return (0);
	arr = data_arr(info);
	push_swap(info, arr);
	free_info(&info);
	free_arr(arr);
	return (0);
}
