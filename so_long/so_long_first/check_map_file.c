#include "so_long.h"

t_gm_obj	check_map(int argc, char **argv, t_gm_obj obj)
{
	t_error	errors;

	init_error_messege(&errors);
	if (argc == 1)
		error_handle(1, errors);
	if (argc > 2)
		error_handle(2, errors);
	check_file(argv[1], errors, &obj.fd);
	read_file(&obj, errors, 0, 0);
	check_line(&obj, errors);
	check_content(&obj);
	return (obj);
}

void	check_file(char *str, t_error errors, int *fd)
{
	const char	*memo;

	memo = ft_strchr(str, '.');
	if (memo == NULL)
		error_handle(3, errors);
	if (ft_strncmp(memo, ".ber", 7) != 0)
		error_handle(3, errors);
	*fd = open(str, O_RDONLY);
	if (*fd == -1)
		error_handle(4, errors);
}

void	read_file(t_gm_obj *obj, t_error errors, int i, int idx)
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
			error_handle(5, errors);
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

void	check_line(t_gm_obj *obj, t_error errors)
{
	obj->x_max = ft_strlen(obj->map[obj->y_max]);
	while (obj->map[obj->y_max + 1] != NULL)
	{
		if(obj->x_max != ft_strlen(obj->map[obj->y_max]))
			error_handle(6, errors);
		obj->y_max++;
	}
	if (obj->x_max != ft_strlen(obj->map[obj->y_max]) + 1)
			error_handle(6, errors);
	if (obj->y_max < 2)
		error_handle(7, errors);
}
