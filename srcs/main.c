#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	data;

	data.nb = 0;
	data.size = 0;
	if (argc != 2)
		return (0);
	data.name = argv[1];
	vars.move = 0;
	vars.dir = 0;
	vars.count = 0;
	if (checkall(data.name, &data) == 0)
		return (0);
	if (checking(&data) == 0)
		return (0);
	vars_init(&vars, &data);
	show_map(vars);
	mlx_key_hook(vars.win, getkey, &vars);
	mlx_hook(vars.win, 17, 0L, close_esc, &vars);
	mlx_loop(vars.mlx);
}
