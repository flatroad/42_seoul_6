#include "minimap.h"

int	main()
{
	t_map	map_data;

	map_data.map = (char **)malloc(sizeof(char *) * 12);
	for (int i = 0; i < 12; i++)
	{
		map_data.map[i] = (char *)malloc(sizeof(char) * 13);
		map_data.map[i] = "01234567899s";
	}
	map_data.map[10] = "ssssssssssssss";
	map_data.ysize = 12;
	map_data.xsize = 13;
	
	minimap(&map_data);
}

01234567899s
01234567899s
01234567899s
01234567899s
01234567899s
01234567899s
01234567899s
01234567899s
ssssssssssssss