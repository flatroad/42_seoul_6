/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:16:39 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/25 05:14:06 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handle_file(int i, t_err_f err_f)
{
	if (i == 0)
		error_write(err_f.error0, err_f.erint0);
	if (i == 1)
		error_write(err_f.error1, err_f.erint1);
	if (i == 2)
		error_write(err_f.error2, err_f.erint2);
	if (i == 3)
		error_write(err_f.error3, err_f.erint3);
	if (i == 4)
		error_write(err_f.error4, err_f.erint4);
	if (i == 5)
		error_write(err_f.error5, err_f.erint5);
	if (i == 6)
		error_write(err_f.error6, err_f.erint6);
	if (i == 7)
		error_write(err_f.error7, err_f.erint7);
	if (i == 8)
		error_write(err_f.error8, err_f.erint8);
}

void	error_handle_content(int i, t_err_c err_c)
{
	if (i == 1)
		error_write(err_c.error1, err_c.erint1);
	if (i == 2)
		error_write(err_c.error2, err_c.erint2);
	if (i == 3)
		error_write(err_c.error3, err_c.erint3);
	if (i == 4)
		error_write(err_c.error4, err_c.erint4);
	if (i == 5)
		error_write(err_c.error5, err_c.erint5);
	if (i == 6)
		error_write(err_c.error6, err_c.erint6);
	if (i == 7)
		error_write(err_c.error7, err_c.erint7);
}

void	error_handle_queue(int i, t_err_q err_q)
{
	if (i == 1)
		error_write(err_q.error1, err_q.erint1);
	if (i == 2)
		error_write(err_q.error2, err_q.erint2);
	if (i == 3)
		error_write(err_q.error3, err_q.erint3);
	if (i == 4)
		error_write(err_q.error4, err_q.erint4);
	if (i == 5)
		error_write(err_q.error5, err_q.erint5);
}

void	error_handle_mlx(int i, t_err_m err_m)
{
	if (i == 1)
		error_write(err_m.error1, err_m.erint1);
	if (i == 2)
		error_write(err_m.error2, err_m.erint2);
	if (i == 3)
		error_write(err_m.error3, err_m.erint3);
	if (i == 4)
		error_write(err_m.error4, err_m.erint4);
	if (i == 5)
		error_write(err_m.error5, err_m.erint5);
}

void	error_write(char *str, int num)
{
	write(2, str, num);
	exit(1);
}
