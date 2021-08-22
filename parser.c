#include "so_long.h"

void	parcer(t_game *game, char **argv)
{
	char	*line;
	int		ret;
	int		i;

	ret = 42;
	i = 0;
	check_name_map(argv[1]);
	game->map_fd = check_open_file(argv[1]);
	while (ret > 0)
	{	
		ret = get_next_line(game->map_fd, &line);
		check_line_map(&game->parser, line);
		game->parser.line_count++;
		if (game->parser.line_count >= game->parser.line_map_max)
			error(9);
		i++;
		free(line);
	}
	close(game->map_fd);
	check_parameter(*game);
}

void	check_border(t_game game)
{
	int	i;
	int	last_line;

	i = 0;
	last_line = game.parser.column_count - 1;
	while (i < game.parser.line_count)
	{
		if (game.map[i][0] != '1')
			error(15);
		if (game.map[i][last_line] != '1')
			error(15);
		i++;
	}
	i = 0;
	last_line = game.parser.line_count - 1;
	while (i < game.parser.column_count)
	{
		if (game.map[0][i] != '1')
			error(15);
		if (game.map[last_line][i] != '1')
			error(15);
		i++;
	}
}
