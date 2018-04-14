#include "inc/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int			main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_cat(fd);
		close(fd);
	}
	return (0);
}
