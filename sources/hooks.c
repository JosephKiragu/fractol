
#include "../includes/fractol.h"

void	ft_quit(int pid)
{
	kill(pid, SIGPIPE);
}

int	lol(void)
{
	exit (0);
	return (0);
}

int	key_hook(int hook, t_fractal *fractal)
{
	if (hook == ESC || hook == DESTROY)
	{
		printf("GOOD");
		ft_quit(fractal->pid);
		exit (EXIT_SUCCESS);
	}
	else if (hook == SPACE)
		ft_rgb_randomizer(fractal);
	else if (hook == UP)
		fractal->fractal.zComplex.imaginery -= 10 / fractal->fractal.scale;
	else if (hook == DOWN)
		fractal->fractal.zComplex.imaginery += 10 / fractal->fractal.scale;
	else if (hook == LEFT)
		fractal->fractal.zComplex.real -= 10 / fractal->fractal.scale;
	else if (hook == RIGHT)
		fractal->fractal.zComplex.real += 10 / fractal->fractal.scale;
	fractal->fractal.height = 0;
	fractal->fractal.width = 0;
	ft_draw(fractal);
	return (EXIT_SUCCESS);
}

void	ft_zoom_in(int x, int y, t_fractal *fractal)
{
	double	scalar;

	if (fractal->fractal.scale >= SCALE_LIMIT)
		return ;
	else
	{
		scalar = fractal->fractal.scale * SCALE_PERC;
		fractal->fractal.zComplex.real = ((double) x / fractal->fractal.scale \
				+ fractal->fractal.zComplex.real - (scalar / 2));
		fractal->fractal.zComplex.real += (scalar / 2) - ((double)x / scalar);
		fractal->fractal.zComplex.imaginery = ((double) y / fractal->fractal.scale + \
				fractal->fractal.zComplex.imaginery) - (scalar / 2);
		fractal->fractal.zComplex.imaginery += (scalar / 2) - ((double) y / scalar);
		fractal->fractal.scale *= SCALE_PERC;
		fractal->fractal.iteration += SCALE_ITER;
		ft_rgb_randomizer(fractal);
	}
}

void	ft_zoom_out(int x, int y, t_fractal *fractal)
{
	double	scalar;

	scalar = fractal->fractal.scale / SCALE_PERC;
	fractal->fractal.zComplex.real = ((double) x / fractal->fractal.scale + \
			fractal->fractal.zComplex.real) - (scalar / 2);
	fractal->fractal.zComplex.real += (scalar / 2) - ((double) x / scalar);
	fractal->fractal.zComplex.imaginery = ((double) y / fractal->fractal.scale + \
			fractal->fractal.zComplex.imaginery) - (scalar / 2);
	fractal->fractal.zComplex.imaginery += (scalar / 2) - ((double)y / scalar);
	fractal->fractal.scale /= SCALE_PERC;
	fractal->fractal.iteration -= SCALE_ITER;
	ft_rgb_randomizer(fractal);
}

int	mouse_hook(int hook, int x, int y, t_fractal *fractal)
{
	if (hook == SCROLL_DOWN)
		ft_zoom_in(x, y, fractal);
	if (hook == SCROLL_UP)
		ft_zoom_out(x, y, fractal);
	fractal->fractal.height = 0x0;
	fractal->fractal.width = 0x0;
	ft_draw(fractal);
	return (EXIT_SUCCESS);
}
