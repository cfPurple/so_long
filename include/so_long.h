/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:08:46 by cfelix            #+#    #+#             */
/*   Updated: 2023/09/09 15:09:29 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <sys/stat.h>

typedef struct s_map
{
	unsigned int	nb;
	unsigned int	size;
	char			*name;
	char			**map;
	char			*buffer;
	int				x;
	int				y;
	int				topx;
	int				topy;
	int				items;
	int				count;
}				t_map;


typedef struct s_vars
{
	void			*mlx;
	void			*win;
	void			*floor;
	void			*wall;
	void			*mario;
	void			*key;
	void			*exit;
	unsigned int	x;
	unsigned int	y;
	unsigned int	topx;
	unsigned int	topy;
	unsigned int	move;
	unsigned int	count;
	unsigned int	items;
	char			**map;
	int				contain;	
}				t_vars;

void	walk_right(t_vars *vars);
void	walk_left(t_vars *vars);
void	walk_up(t_vars *vars);
void	walk_down(t_vars *vars);
void	walk(t_vars *vars, int keycode);
void	walkwin(t_vars *vars, int keycode);
int		get_data(t_map *data);
int		checkchar(char *map);
int		get_map(t_map *data);
void	ft_clear(void **data);
void	gps(t_map *data, int *x, int *y, char c);
int		checkwalls(t_map *data);
int		checkformat(char *name, char *format);
int		checkelem(char c, char *s);
int		countelem(t_map *data);
int		testmap(unsigned int x, unsigned int y, t_map *data);
int		checking(t_map *data);
int		close_esc(t_vars *vars);
int		getkey(int keycode, t_vars *vars);
void	show_map(t_vars vars);
void	vars_init(t_vars *vars, t_map *data);
void	put_floor(t_vars *vars, int x, int y);
void	put_wall(t_vars *vars, int x, int y);
void	put_mario(t_vars *vars, int x, int y);
void	put_exit(t_vars *vars, int x, int y);
int		ft_index(const char *str, char c);
int		checkall(char *name, t_map *data);


#endif
