#include "so_long.h"

void	so_long(int argc, char **argv)
{
	t_gm_obj	obj;

	init_object(&obj);
	obj = check_map (argc, argv, obj);
}
