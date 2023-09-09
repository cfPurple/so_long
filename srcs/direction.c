#include "so_long.h"

void	gps(t_map *data, int *x, int *y, char c)
{
	int	i;
	int	p;

	i = 0;
	while (data->map[i] != NULL)
	{
		p = ft_index(data->map[i], c);
		if (p != -1)
		{
			*y = i;
			*x = p;
		}
		i++;
	}
}

void ft_clear(void **data)
{
    if (data == NULL)
        return ;
    free(*data);
    *data = NULL;
}
