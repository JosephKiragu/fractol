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
		./sources/libft_utils.c \
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


# SRC = ./sources/main.c \
# 	  ./sources/draw.c \
# 	  ./sources/hooks.c \
# 	  ./sources/ft_mandelbrot_constructor.c \
# 	  ./sources/libft_utils.c \
# 	  ./sources/pixilization.c \
# 	  ./sources/ft_afplay.c \
# 	  ./sources/julia_set_constructor.c \
# 	  ./sources/shut_down_afplay.c \
# 	  ./sources/rabbit_set_constructor.c