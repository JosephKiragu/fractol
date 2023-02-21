#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_opengl_20191021/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <signal.h>
# include <unistd.h>

# define WIDTH 1200
# define HEIGHT 720
# define MSG "PROJECT FRACTOL"





# define ESC 53
# define SPACE 49
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SCROLL_UP 0x04
# define SCROLL_DOWN 0x05

# define DESTROY 17

# define SCALE_LIMIT 800000
# define SCALE_PERC 1.3
# define SCALE_ITER 3


// struct for storing colours
typedef struct s_rgb
{
    int red;
    int green;
    int blue;
} t_rgb;

//  struct for storing complex numbers
typedef struct s_complex 
{
    double imaginery;
    double real;
} t_complex;

//  struct for storing parameters for manipulating the fractal sets
typedef struct s_setParameters
{
    int depth;
    int type;
    int iteration;
    double height;
    double width;
    t_complex zComplex;
    t_complex constantC;
    double scale;
} t_setParameters;


// struct for storing minilibx graphics parameters
typedef struct s_mlx
{
    void    *mlx;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    void     *win;
    int     *colour;
    void    *param;
}   t_mlx;


 // struct for storing fractals 
 typedef struct s_fractal
 {
     t_setParameters    fractal;
     t_rgb              colour;
     t_mlx              mlx;
     int                pid;
 } t_fractal;


 int    ft_strcmp(char *s1, char *s2);

 int    ft_draw(t_fractal *fractal);
 int    ft_julia(t_fractal *fractal);
 void   ft_print_pixel(t_fractal *fractal, int depth);
 void   ft_quit(int pid);
 int	lol(void);
 int	key_hook(int hook, t_fractal *fractal);
 void	ft_zoom_in(int x, int y, t_fractal *fractal);
 void	ft_zoom_out(int x, int y, t_fractal *fractal);
 int	mouse_hook(int hook, int x, int y, t_fractal *fractal);
 void	ft_rgb_randomizer(t_fractal *fractal);

 #endif
