#include "so_long.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	ft_free_double(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
