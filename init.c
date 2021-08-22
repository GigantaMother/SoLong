#include "so_long.h"

void	init_game(t_game *game)
{
	game->resolution.x = 1500;
	game->resolution.y = 1000;
	game->count_step = 0;
	game->map_fd = -1;
	game->parser.player_count = 0;
	game->parser.object_count = 0;
	game->parser.exit_count = 0;
	game->parser.line_count = 0;
	game->parser.column_count = 0;
	game->parser.line_map_max = 30;
	game->parser.column_map_max = 30;
	game->parser.line_map_min = 2;
	game->parser.column_map_min = 2;
}

void	init_map(t_game *game, char *name)
{
	char	*line;
	int		ret;
	int		i;

	ret = 42;
	i = 0;
	game->map = malloc(sizeof(char *) * game->parser.line_count);
	if (game->map == NULL)
		error (13);
	while (i < game->parser.line_count)
	{
		game->map[i] = malloc(sizeof(char) * (game->parser.column_count) + 1);
		if (game->map[i] == NULL)
			error (13);
		i++;
	}
	i = 0;
	game->map_fd = check_open_file(name);
	while (ret > 0)
	{	
		ret = get_next_line(game->map_fd, &line);
		line_transfer(line, game->map[i++]);
		free(line);
	}
	close(game->map_fd);
}

void	init_sprites(t_game *game)
{
	game->sprites.wall = mlx_xpm_file_to_image(game->graphics.mlx, \
	"textures/wall.xpm", &game->sprites.width, &game->sprites.height);
	if (game->sprites.wall == NULL)
		error(17);
	game->sprites.floor = mlx_xpm_file_to_image(game->graphics.mlx, \
	"textures/floor.xpm", &game->sprites.width, &game->sprites.height);
	if (game->sprites.floor == NULL)
		error(17);
	game->sprites.door = mlx_xpm_file_to_image(game->graphics.mlx, \
	"textures/door.xpm", &game->sprites.width, &game->sprites.height);
	if (game->sprites.door == NULL)
		error(17);
	game->sprites.hero = mlx_xpm_file_to_image(game->graphics.mlx, \
	"textures/hero.xpm", &game->sprites.width, &game->sprites.height);
	if (game->sprites.hero == NULL)
		error(17);
	game->sprites.goblin = mlx_xpm_file_to_image(game->graphics.mlx, \
	"textures/goblin.xpm", &game->sprites.width, &game->sprites.height);
	if (game->sprites.goblin == NULL)
		error(17);
	game->sprites.coin = mlx_xpm_file_to_image(game->graphics.mlx, \
	"textures/coin.xpm", &game->sprites.width, &game->sprites.height);
	if (game->sprites.goblin == NULL)
		error(17);
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->parser.line_count)
	{
		j = 0;
		while (j < game->parser.column_count)
		{
			if (game->map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	init_graphics(t_game *game)
{
	init_player(game);
	game->zoom = 49;
	game->resolution.x = game->parser.column_count * game->zoom;
	game->resolution.y = game->parser.line_count * game->zoom;
	game->graphics.mlx = mlx_init();
	if (game->graphics.mlx == NULL)
		return (error(16));
	game->graphics.win = mlx_new_window(game->graphics.mlx, \
	game->resolution.x, game->resolution.y, "so_long");
	if (game->graphics.win == NULL)
		return (error(16));
	init_sprites(game);
}
