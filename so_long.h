#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "get_next_line.h"

enum e_button {
	Esc = 53,
	Up = 13,
	Down = 1,
	Right = 2,
	Left = 0,
};

typedef struct s_coord {
	int	x;
	int	y;
}				t_coord;

typedef struct s_parser {
	int	player_count;
	int	object_count;
	int	exit_count;
	int	line_count;
	int	column_count;
	int	line_map_max;
	int	column_map_max;
	int	line_map_min;
	int	column_map_min;
}				t_parser;

typedef struct s_graphics
{
	void	*mlx;
	void	*win;
	void	*img;
}					t_graphics;

typedef struct s_sprites
{
	int		width;
	int		height;
	void	*wall;
	void	*floor;
	void	*door;
	void	*hero;
	void	*goblin;
	void	*coin;
}					t_sprites;

typedef struct s_game {
	int			zoom;
	t_sprites	sprites;
	t_graphics	graphics;
	t_parser	parser;
	t_coord		player;
	t_coord		resolution;
	int			count_step;
	int			map_fd;
	char		**map;
}				t_game;

//main.c(4)
void	print_map(t_game game);

//graphics.c(5)
void	print_map_graphics(t_game *game);
void	key_move(t_game *game, int y, int x);
void	print_counter_step(t_game *game);

//parcer.c(3)
void	parcer(t_game *game, char **argv);
void	check_border(t_game game);

//init.c(4)
void	init_game(t_game *game);
void	init_map(t_game *game, char *name);
void	init_graphics(t_game *game);

//check.c(5)
int		check_open_file(char *name);
void	check_parameter(t_game game);
void	check_name_map(char *name);
void	check_line_map(t_parser *parcer, char *line);
int		check_symbol_map(char symbol);

//utilits_2.c(5)
void	error(int e);
char	*ft_itoa(int n);

//utilits_1.c (5)
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(long n);
void	line_transfer(char *original, char *copy);

#endif