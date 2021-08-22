CC = gcc

NAME	=	so_long

HEADERS =	so_long.h	get_next_line.h

FLAGS	= 	-Wall -Wextra -Werror

SRC		=	check.c		graphics.c		init.c		utilits_1.c\
			main.c		parser.c		utilits_2.c\
			get_next_line.c			get_next_line_utils.c					

OBJ		=	$(patsubst %.c, %.o, $(SRC))

all		:	$(NAME)

$(NAME)	:	$(SRC)
	gcc $(CFLAGS)  -c $(SRC)
	gcc $(FLAGS) $(OBJ) -o -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -lmx

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

.PHONY	:	all clean fclean re