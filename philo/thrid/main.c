/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:53:05 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/11 19:34:57 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (philo(argc, argv) != 0)
	{
		printf("%d\n", 123);
		system("leaks philo");
		return (1);
	}
	system("leaks philo");
	return (0);
}
