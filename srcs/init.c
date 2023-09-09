#include "so_long.h"

void	vars_init(t_vars *vars, t_map *data)
{
	int	l;
	int	h;

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx,
			64 * (data->size - 1), 64 * data->nb, "so_long");
	vars->img = mlx_xpm_file_to_image(vars->mlx, "xpm/floor.xpm", &l, &h);
	vars->bg = mlx_xpm_file_to_image(vars->mlx, "xpm/wall.xpm", &l, &h);
	vars->mc = mlx_xpm_file_to_image(vars->mlx, "xpm/mario.xpm", &l, &h);
	vars->c = mlx_xpm_file_to_image(vars->mlx, "xpm/key.xpm", &l, &h);
	vars->e = mlx_xpm_file_to_image(vars->mlx, "xpm/exit.xpm", &l, &h);
	vars->map = ft_split(data->buffer, '\n');
	vars->x = data->x;
	vars->y = data->y;
	vars->topx = data->topx;
	vars->topy = data->topy;
	vars->items = data->items - 1;
	free(data->buffer);
	ft_clear((void **)data->map);
}

void	put_floor(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x * 64, y * 64);
}

void	put_wall(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 64, y * 64);
}

void	put_mario(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->mc, x * 64, y * 64);
}

void	put_exit(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->e, x * 64, y * 64);
}