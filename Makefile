NAME = fractol

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

HEADER = ./includes/fractol.h

SRC =	./sources/main.c \
		./sources/pixel.c \
		./sources/juliaSetConstructor.c \
		./sources/mandelbrotSetConstructor.c \
		./sources/rabbitSetConstructor.c \
		./sources/draw.c \
		./sources/utils.c \
		./sources/hooks.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

%.o : %.c Makefile $(HEADER)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) fractol $(OBJ)


re : fclean all

.PHONY : all clean fclean re