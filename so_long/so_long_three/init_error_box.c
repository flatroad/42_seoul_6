/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_error_box.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:15:22 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/25 07:18:27 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_error_file(t_err_f *err_f)
{
	err_f->error1 = "Error\nThere is no map\n";
	err_f->erint1 = 22;
	err_f->error2 = "Error\nToo many files\n";
	err_f->erint2 = 21;
	err_f->error3 = "Error\nIs not .ber file\n";
	err_f->erint3 = 23;
	err_f->error4 = "Error\nThere is not .ber file\n";
	err_f->erint4 = 29;
	err_f->error5 = "Error\nMalloc fail\n";
	err_f->erint5 = 18;
	err_f->error6 = "Error\nDifferent row\n";
	err_f->erint6 = 20;
	err_f->error7 = "Error\nShort col\n";
	err_f->erint7 = 16;
	err_f->error8 = "Error\nShort row\n";
	err_f->erint8 = 16;
}

void	init_error_content(t_err_c *err_c)
{
	err_c->error1 = "Error\nOutside blank space\n";
	err_c->erint1 = 26;
	err_c->error2 = "Error\nCollection wrong\n";
	err_c->erint2 = 24;
	err_c->error3 = "Error\nHave no way_in\n";
	err_c->erint3 = 22;
	err_c->error4 = "Error\nHave many way_in\n";
	err_c->erint4 = 24;
	err_c->error5 = "Error\nHave no way_out\n";
	err_c->erint5 = 22;
	err_c->error6 = "Error\nHave many way_out\n";
	err_c->erint6 = 24;
	err_c->error7 = "Error\nHave wrong obj\n";
	err_c->erint7 = 22;
}

void	init_error_queue(t_err_q *err_q)
{
	err_q->error1 = "Error\nObj_p malloc fail\n";
	err_q->erint1 = 25;
	err_q->error2 = "Error\nVisit malloc fail\n";
	err_q->erint2 = 25;
	err_q->error3 = "Error\nImpossibility game clear\n";
	err_q->erint3 = 32;
	err_q->error4 = "Error\nImpossibility game clear\n";
	err_q->erint4 = 32;
	err_q->error5 = "Error\nPush que fail\n";
	err_q->erint5 = 21;
}

void	init_error_mlx(t_err_m *err_m)
{
	err_m->error1 = "Error\nInit mlx fail\n";
	err_m->erint1 = 25;
	err_m->error2 = "Error\nInit mlx win fail\n";
	err_m->erint2 = 25;
	err_m->error3 = "Error\nImages not upload\n";
	err_m->erint3 = 32;
	err_m->error4 = "Error\nInitial_map Fail";
	err_m->erint4 = 32;
	err_m->error5 = "Error\nPush que fail\n";
	err_m->erint5 = 21;
}
