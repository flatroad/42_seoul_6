#include "minimap.h"

int	main()
{
	t_map	map_data;

	map_data.map = (char **)malloc(sizeof(char *) * 12);
	for (int i = 0; i < 12; i++)
		map_data.map[i] = (char *)malloc(sizeof(char) * 13);
	map_data.map[0] = "            ";
	map_data.map[1] = "111111 11111";
	map_data.map[2] = "100001110001";
	map_data.map[3] = "110000001001";
	map_data.map[4] = "100000100001";
	map_data.map[5] = "100000000001";
	map_data.map[6] = "100000010001";
	map_data.map[7] = "111100001001";
	map_data.map[8] = "   100000001";
	map_data.map[9] = "111100001001";
	map_data.map[10] = "110000001001";
	map_data.map[11] = "110000001001";
	map_data.map[12] = NULL;
	map_data.xsize = 13;
	map_data.ysize = 12;

	minimap(&map_data);
}
