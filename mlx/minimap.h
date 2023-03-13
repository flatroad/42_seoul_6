#ifndef MINIMAP_H
# define MINIMAP_H

#include <stdio.h>
#include <stdlib.h>
#include "minilibx_mms_20210621/mlx.h"

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	int		xsize;
	int		ysize;
	char	**map;
}	t_map;

typedef struct s_mini_obj
{
	char	**map;
	t_data	img;
}	t_mini_obj;

typedef struct s_mini
{
	t_mini_obj	**mini_obj;
	int			parti_x;
	int			parti_y;
}	t_mini;


int		minimap(t_map *map_data);
void	mini_init(t_mini *mini);
int		mini_insert(t_map *map_data, t_mini *mini);
void	mini_insert_xy(t_map *map_data, t_mini *mini);
int		mini_obj_malloc(t_mini *mini);
void	mini_obj_free(t_mini *mini, int max);
int		mini_obj_insert(t_mini *mini, t_map *map_data);
int		mini_obj_init(t_mini *mini);
void	mini_obj_map_free(char **map, int max);
int		mini_obj_map_malloc(t_mini_obj *mini_obj);
void	mini_obj_map_insert(t_mini_obj **mini_obj, t_map *map_data);


#endif