#include "so_long.h"

void	get_xy_size(char **argv, t_map *map)
{
	int		fd;
	char	*line;
	int		y;
	char	**split;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error();
	printf("dfg-> %d\n", fd);
	line = get_next_line(fd);
	if (line == NULL)
		print_error();
	split = ft_split(line, ' ');
	map->size_x = split_len(split);
	y = 0;
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	map->size_y = y;
	free(line);
	ft_free_double(split);
	close(fd);
}