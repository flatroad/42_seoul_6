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
	int		x_max;
	int		y_max;
} t_gm_obj;

typedef struct s_object_coordinate
{
	int	way_in[2];
	int	way_out[2];
	t_queue *collection;
} t_coordinate;


typedef struct s_error_messege1
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
} t_error;

typedef struct s_error_messege2
{
	char	*error8;
	int		erint8;
	char	*error9;
	int		erint9;
	char	*error10;
	int		erint10;
	char	*error11;
	int		erint11;

} t_error_sb;

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
} t_error_que;

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



// so_long
void	so_long(int argc, char **argv);

// init
void	init_error_messege(t_error *errors);
void	init_object(t_gm_obj *obj);
void	init_error_messege_sb(t_error_sb *errors);

// error_handle
void	error_handle(int i, t_error errors);
void	error_handle_sb(int i, t_error_sb errors);
void	error_write(char *str, int num);

//check_map
t_gm_obj	check_map(int argc, char **argv, t_gm_obj obj);
void		check_file(char *str, t_error errors, int *fd);
void		read_file(t_gm_obj *obj, t_error errors, int i, int idx);
void		check_line(t_gm_obj *obj, t_error errors);

//check_map_content
void		check_content(t_gm_obj *obj);
void		check_wall(t_gm_obj *obj, t_error_sb errors_sb);
void		check_obj_num(t_gm_obj *obj, t_error_sb errors);

# endif
