/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:02:09 by cfelix            #+#    #+#             */
/*   Updated: 2023/09/09 15:02:46 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vars_init(t_vars *vars, t_map *data)
{
	int	l;
	int	h;

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx,
			64 * (data->size - 1), 64 * data->nb, "so_long");
	vars->floor = mlx_xpm_file_to_image(vars->mlx, "xpm/floor.xpm", &l, &h);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "xpm/wall.xpm", &l, &h);
	vars->mario = mlx_xpm_file_to_image(vars->mlx, "xpm/mario.xpm", &l, &h);
	vars->key = mlx_xpm_file_to_image(vars->mlx, "xpm/key.xpm", &l, &h);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "xpm/exit.xpm", &l, &h);
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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->floor, x * 64, y * 64);
}

void	put_wall(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, x * 64, y * 64);
}

void	put_mario(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->mario, x * 64, y * 64);
}

void	put_exit(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, x * 64, y * 64);
}
