/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:17:45 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/25 03:32:56 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gm_obj	check_map(int argc, char **argv, t_gm_obj obj)
{
	t_err_f	err_f;
	t_err_c	err_c;
	t_err_q	err_q;

	init_error_file(&err_f);
	init_error_content(&err_c);
	init_error_queue(&err_q);
	check_file(argc, argv[1], err_f, &obj);
	check_content(&obj, err_c);
	check_possible(&obj, err_q);
	return (obj);
}
