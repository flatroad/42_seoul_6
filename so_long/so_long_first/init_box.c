#include "so_long.h"

void	init_error_messege(t_error *errors)
{
	errors->error1 = "Error\nThere is no map\n";
	errors->erint1 = 22;
	errors->error2 = "Error\nToo many files\n";
	errors->erint2 = 21;
	errors->error3 = "Error\nIs not .ber file\n";
	errors->erint3 = 23;
	errors->error4 = "Error\nThere is not .ber file\n";
	errors->erint4 = 29;
	errors->error5 = "Error\nMalloc fail\n";
	errors->erint5 = 18;
	errors->error6 = "Error\nDifferent row\n";
	errors->erint6 = 20;
	errors->error7 = "Error\nShort col\n";
	errors->erint7 = 16;
	
}

void	init_error_messege_sb(t_error_sb *errors)
{
	errors->error8 = "Error\nOutside blank space\n";
	errors->erint8 = 26;
	errors->error9 = "Error\nCollection wrong\n";
	errors->erint9 = 24;
	errors->error10 = "Error\nWay_in wrong\n";
	errors->erint10 = 21;
	errors->error11 = "Error\nWay_out wrong\n";
	errors->erint11 = 20;
}

void	init_error_que(t_error_que *errors)
{
	errors->error1 = "Error\nOutside blank space\n";
	errors->erint1 = 26;
	errors->error2 = "Error\nCollection wrong\n";
	errors->erint2 = 24;
	errors->error3 = "Error\nWay_in wrong\n";
	errors->erint3 = 21;
	errors->error4 = "Error\nWay_out wrong\n";
	errors->erint4 = 20;
}

void	init_object(t_gm_obj *obj)
{
	obj->fd = -1;
	obj->wall = 0;
	obj->map = NULL;
	obj->player = 0;
	obj->collection = 0;
	obj->way_in = 0;
	obj->way_out = 0;
	obj->x_max = 0;
	obj->y_max = 0;
}

void	init_queue(t_queue *que)
{
	que->first = NULL;
	que->count = 0;
	que->last = NULL;
}
