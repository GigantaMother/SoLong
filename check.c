#include "so_long.h"

int	check_open_file(char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		error(2);
	return (fd);
}

void	check_parameter(t_game game)
{
	if (game.parser.player_count != 1)
		error (10);
	if (game.parser.object_count < 1)
		error (11);
	if (game.parser.exit_count < 1)
		error (12);
	if (game.parser.column_count <= game.parser.column_map_min)
		error (14);
	if (game.parser.line_count <= game.parser.line_map_min)
		error (14);
}

void	check_name_map(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 4)
		error (3);
	if (name[len - 4] != '.' || name[len - 3] != 'b' || \
	name[len - 2] != 'e' || name[len - 1] != 'r')
		error (4);
}

void	check_line_map(t_parser *parcer, char *line)
{
	int	i;
	int	line_size;

	i = 0;
	line_size = ft_strlen(line);
	if (line_size == 0)
		error (7);
	if (line_size >= parcer->column_map_max)
		error (8);
	while (line[i])
	{
		if (check_symbol_map(line[i]) == 0)
			error (5);
		if (parcer->column_count == 0)
			parcer->column_count = line_size;
		else if (parcer->column_count != line_size)
			error (6);
		if (line[i] == 'P')
			parcer->player_count++;
		else if (line[i] == 'C')
			parcer->object_count++;
		else if (line[i] == 'E')
			parcer->exit_count++;
		i++;
	}
}

int	check_symbol_map(char symbol)
{
	if (symbol == '2')
		return (3);
	else if (symbol == 'P' || symbol == 'E' || symbol == 'C' || symbol == '0')
		return (2);
	else if (symbol == '1')
		return (1);
	else
		return (0);
}
