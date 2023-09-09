/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:07:48 by cfelix            #+#    #+#             */
/*   Updated: 2023/09/09 15:07:51 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_esc(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->floor);
	mlx_destroy_image(vars->mlx, vars->mario);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->key);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	ft_clear((void **)vars->map);
	free(vars->mlx);
	exit(0);
}

int	getkey(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_esc(vars);
	if (keycode == 100 || keycode == 119 || keycode == 115 || keycode == 97)
		walk(vars, keycode);
	return (0);
}

void	show_map(t_vars vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars.map[y] != NULL)
	{
		x = 0;
		while (vars.map[y][x] != '\0')
		{
			if (vars.map[y][x] == '0')
				put_floor(&vars, x, y);
			else if (vars.map[y][x] == '1')
				put_wall(&vars, x, y);
			else if (vars.map[y][x] == 'P')
				put_mario(&vars, x, y);
			else if (vars.map[y][x] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.key,
					x * 64, y * 64);
			else if (vars.map[y][x] == 'E')
				put_exit(&vars, x, y);
			x ++;
		}
		y ++;
	}
}
