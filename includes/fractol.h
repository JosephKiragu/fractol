/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <jkiragu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:32:58 by jkiragu           #+#    #+#             */
/*   Updated: 2023/03/03 18:06:13 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//struct for storing colours
typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

//struct for storing real and imgn numbers
typedef struct s_complex
{
	double	imgn;
	double	real;
}	t_complex;

//struct for storing fract parameters
typedef struct s_setParameters
{
	t_complex	z_comp;
	t_complex	c_constant;
	int			dp;
	int			type;
	int			iter;
	double		height;
	double		width;
	double		scale;
}	t_setParameters;

// struct for storing minilibx graphics parameters
typedef struct s_mlx
{
	void	*mlx;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*win;
	int		*colour;
	void	*param;
}	t_mlx;

typedef struct s_fractal
{
	t_setParameters	fract;
	t_rgb			colour;
	t_mlx			mlx;
	int				pid;
}	t_fractal;

int		ft_strcmp(char *s1, char *s2);
int		ft_draw(t_fractal *fract);
int		ft_julia(t_fractal *fract);
int		ft_mandelbrot(t_fractal *fract);
int		ft_rabbit(t_fractal *fract);
void	ft_print_pixel(t_fractal *fract, int dp);
void	ft_quit(int pid);
int		lol(void);
int		key_hook(int hook, t_fractal *fract);
void	ft_zoom_in(int x, int y, t_fractal *fract);
void	ft_zoom_out(int x, int y, t_fractal *fract);
int		mouse_hook(int hook, int x, int y, t_fractal *fract);
void	ft_rgb_randomizer(t_fractal *fract);
#endif