#include "so_long.h"

int	key_hook_press(int keycode, t_game *game);
int	key_hook_close(int keycode, t_game *game);

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error(1);
	init_game(&game);
	parcer(&game, argv);
	init_map(&game, argv[1]);
	check_border(game);
	print_map(game);
	init_graphics(&game);
	print_map_graphics(&game);
	mlx_hook(game.graphics.win, 2, 1L << 2, key_hook_press, &game);
	mlx_hook(game.graphics.win, 17, 1L << 2, key_hook_close, &game);
	mlx_loop(game.graphics.mlx);
	return (0);
}

void	print_map(t_game game)
{
	int	i;
	int	j;

	i = 0;
	ft_putstr("Строк   = ");
	ft_putnbr(game.parser.line_count);
	ft_putstr("\nСтолбцов= ");
	ft_putnbr(game.parser.column_count);
	ft_putstr("\n");
	while (i < game.parser.line_count)
	{
		j = 0;
		while (j < game.parser.column_count)
		{
			write(1, &game.map[i][j], 1);
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

int	key_hook_press(int keycode, t_game *game)
{
	if (keycode == Esc)
	{
		ft_putstr("Выход через esc\n");
		mlx_destroy_window(game->graphics.mlx, game->graphics.win);
		exit (0);
	}
	else if (keycode == Up)
		key_move(game, -1, 0);
	else if (keycode == Down)
		key_move(game, 1, 0);
	else if (keycode == Right)
		key_move(game, 0, 1);
	else if (keycode == Left)
		key_move(game, 0, -1);
	return (1);
}

int	key_hook_close(int keycode, t_game *game)
{
	ft_putstr("Выход через крестик\n");
	exit (0);
}
