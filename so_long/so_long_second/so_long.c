/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:14:19 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/25 02:57:35 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(int argc, char **argv)
{
	t_gm_obj	obj;

	init_object(&obj);
	obj = check_map(argc, argv, obj);
	system("leaks so_long");
}
