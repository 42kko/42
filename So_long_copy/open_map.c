#include "so_long.h"

char	*open_map(char *a);
{
	int	fd;
	int	i;
	char tmp[100];

	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		ft_exit("fd value error");
	while (1)
	{
		i = read(fd, tmp, 100);
		if (i == 0)
			break;
		if (i < 0)
			exit(1);
	}
	
}