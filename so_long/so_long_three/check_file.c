/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:18:10 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/26 12:47:37 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(int argc, char *str, t_err_f err_f, t_gm_obj *obj)
{
	const char	*memo;

	if (argc == 1)
		error_handle_file(1, err_f);
	if (argc > 2)
		error_handle_file(2, err_f);
	memo = ft_strchr(str, '.');
	if (memo == NULL)
		error_handle_file(3, err_f);
	if (ft_strncmp(memo, ".ber", 7) != 0)
		error_handle_file(3, err_f);
	obj->fd = open(str, O_RDONLY);
	if (obj->fd == -1)
		error_handle_file(4, err_f);
	read_file(obj, err_f, 0, 0);
	check_line(obj, err_f);
	close(obj->fd);
}

void	read_file(t_gm_obj *obj, t_err_f err_f, int i, int idx)
{
	char	*read_line;
	char	**memo;

	i = 1;
	while (1)
	{
		idx = 0;
		read_line = get_next_line(obj->fd);
		if (read_line == NULL)
			break ;
		i++;
		memo = obj->map;
		obj->map = (char **)malloc(sizeof(char *) * i);
		if (obj->map == NULL)
			error_handle_file(5, err_f);
		while (i != 2 && idx < i - 2)
		{
			obj->map[idx] = memo[idx];
			idx++;
		}
		obj->map[idx] = read_line;
		obj->map[idx + 1] = NULL;
		free(memo);
		memo = 0;
	}
}

void	check_line(t_gm_obj *obj, t_err_f err_f)
{
	obj->row_max = ft_strlen(obj->map[obj->col_max]);
	while (obj->map[obj->col_max + 1] != NULL)
	{
		if (obj->row_max != ft_strlen(obj->map[obj->col_max]))
			error_handle_file(6, err_f);
		obj->col_max++;
	}
	if (obj->row_max != ft_strlen(obj->map[obj->col_max]) + 1)
		error_handle_file(6, err_f);
	if (obj->col_max < 2)
		error_handle_file(7, err_f);
	if (obj->row_max - 1 <= 2)
		error_handle_file(8, err_f);
}
