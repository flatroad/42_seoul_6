#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "get_next_line/get_next_line.h"

typedef	struct s_game
{
	char	**map;
}	t_game;


void	argc_error_handle(int cas);

#endif