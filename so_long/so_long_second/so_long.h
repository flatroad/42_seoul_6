#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

typedef struct s_game_object
{
	int		fd;
	char	**map;
	int		way_in;
	int		way_out;
	int		collection;
	int		wall;
	int		player;
	int		foe;
	int		free_zone;
	int		x_max;
	int		y_max;
} t_gm_obj;

typedef struct s_node
{
	struct s_node	*next;
	int				x_y[2];
} t_node;

typedef struct s_queue
{
	t_node	*first;
	t_node	*last;
	int		count;
} t_queue;

typedef struct s_object_position
{
	int	row;
	int	col;
	int	way_in[2];
	int	way_out[2];
	t_queue *col_list;
} t_obj_p;

typedef struct s_error_file
{
	char	*error0;
	int		erint0;
	char	*error1;
	int		erint1;
	char	*error2;
	int		erint2;
	char	*error3;
	int		erint3;
	char	*error4;
	int		erint4;
	char	*error5;
	int		erint5;
	char	*error6;
	int		erint6;
	char	*error7;
	int		erint7;
	char	*error8;
	int		erint8;
} t_err_f;

typedef struct s_error_content
{
	char	*error1;
	int		erint1;
	char	*error2;
	int		erint2;
	char	*error3;
	int		erint3;
	char	*error4;
	int		erint4;
	char	*error5;
	int		erint5;
	char	*error6;
	int		erint6;

} t_err_c;

typedef struct s_error_que
{
	char	*error1;
	int		erint1;
	char	*error2;
	int		erint2;
	char	*error3;
	int		erint3;
	char	*error4;
	int		erint4;
} t_err_q;

// so_long
void	so_long(int argc, char **argv);

// init error
void	init_error_file(t_err_f *err_f);
void	init_error_content(t_err_c *err_c);
void	init_error_queue(t_err_q *err_q);

// init
void	init_object(t_gm_obj *obj);
t_queue	*init_queue(t_err_q err_q);
t_obj_p	*init_obj_position(t_err_q err_q);

//check_map
t_gm_obj	check_map(int argc, char **argv, t_gm_obj obj);

//check_file
void	check_file(int argc, char *str, t_err_f err_f, t_gm_obj *obj);
void	read_file(t_gm_obj *obj, t_err_f err_f, int i, int idx);
void	check_line(t_gm_obj *obj, t_err_f err_f);

//check__content
void	check_content(t_gm_obj *obj, t_err_c err_c);
void	check_wall(t_gm_obj *obj, t_err_c err_c);
void	check_obj_num(t_gm_obj *obj, t_err_c err_c);
void	calc_num(t_gm_obj *obj, char c);
void	check_content_error(t_gm_obj *obj, t_err_c err_c);

//check_possible;
void	check_possible(t_gm_obj *obj, t_err_q err_q);
void	check_position(t_gm_obj *obj, t_obj_p *obj_p, t_err_q err_q);
void	calc_position(char c, t_obj_p *obj_p, t_err_q err_q);

// error_handle
void	error_handle_file(int i, t_err_f err_f);
void	error_handle_content(int i, t_err_c err_c);
void	error_handle_queue(int i, t_err_q err_q);
void	error_write(char *str, int num);

// queue_box
void push_queue(t_queue *que, t_err_q err_q, int i, int j);

# endif