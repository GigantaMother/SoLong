#include "so_long.h"

static void	key_move_step(t_game *game, int y, int x);
static void	print_map_graphics_block(t_game *game, int i, int j);

void	print_map_graphics(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < game->parser.column_count)
	{
		j = 0;
		while (j < game->parser.line_count)
		{
			print_map_graphics_block(game, i, j);
			j++;
		}
		i++;
	}
	print_counter_step(game);
}

void	key_move(t_game *game, int y, int x)
{
	if (game->map[game->player.y + y][game->player.x + x] == '0' || \
	game->map[game->player.y + y][game->player.x + x] == 'C')
		key_move_step(game, y, x);
	else if (game->map[game->player.y + y][game->player.x + x] == 'E')
	{
		if (game->parser.object_count == 0)
		{
			ft_putstr("Ура! Уровень пройден!\n");
			game->count_step++;
			print_counter_step(game);
			mlx_destroy_window(game->graphics.mlx, game->graphics.win);
			exit (0);
		}
		else
			ft_putstr("Не все сокровища собраны!\n");
	}
	else if (game->map[game->player.y + y][game->player.x + x] == '2')
	{
		ft_putstr("Вы умерли =(\n");
		mlx_destroy_window(game->graphics.mlx, game->graphics.win);
		exit (0);
	}
}

static void	print_map_graphics_block(t_game *game, int i, int j)
{
	if (game->map[j][i] == '1')
		mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, \
		game->sprites.wall, i * game->zoom, j * game->zoom);
	else if (game->map[j][i] != '1')
		mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, \
		game->sprites.floor, i * game->zoom, j * game->zoom);
	if (game->map[j][i] == 'E')
		mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, \
		game->sprites.door, i * game->zoom, j * game->zoom);
	else if (game->map[j][i] == 'C')
		mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, \
		game->sprites.coin, i * game->zoom, j * game->zoom);
	else if (game->map[j][i] == 'P')
		mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, \
		game->sprites.hero, i * game->zoom, j * game->zoom);
	else if (game->map[j][i] == '2')
		mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, \
		game->sprites.goblin, i * game->zoom, j * game->zoom);
}

static void	key_move_step(t_game *game, int y, int x)
{
	if (game->map[game->player.y + y][game->player.x + x] == 'C')
		game->parser.object_count--;
	mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, \
	game->sprites.floor, game->player.x * game->zoom, \
	game->player.y * game->zoom);
	game->map[game->player.y][game->player.x] = '0';
	game->player.y = game->player.y + y;
	game->player.x = game->player.x + x;
	mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, \
	game->sprites.hero, game->player.x * game->zoom, \
	game->player.y * game->zoom);
	game->map[game->player.y][game->player.x] = 'P';
	game->count_step++;
	print_counter_step(game);
}

void	print_counter_step(t_game *game)
{
	char	*line;

	print_map_graphics_block(game, 0, 0);
	print_map_graphics_block(game, 1, 0);
	print_map_graphics_block(game, 2, 0);
	ft_putstr("Шагов= ");
	ft_putnbr(game->count_step);
	ft_putstr("\n");
	mlx_string_put(game->graphics.mlx, game->graphics.win, \
	10, 10, 0, "step: \n");
	line = ft_itoa(game->count_step);
	mlx_string_put(game->graphics.mlx, game->graphics.win, 70, 10, 0, line);
	free(line);
}
