#include "data.h"

void	draw_other(t_image game_img, t_data *data)
{
	int				x;
	t_detail_info	info;
	t_other_draw	draw_info;

	x = 0;
	while (x < G_W)
	{
		init_info(&info);
		init_draw_info(&draw_info);
		input_need_for_raycating(data->player, &info, x);
		input_ray_step(data->player, &info);
		ray_casting(data->map, data);
		select_img(data->player, &info);
		calc_dist_valti(&info);
		draw_pixel_st_en(&draw_info, &info);
		calc_draw_img_others(&draw_info, data->player, &info);
		drawing_game_img(&draw_info, game_img, \
		data->texture->img_box[info.four_dir], x);
		x++;
	}
}