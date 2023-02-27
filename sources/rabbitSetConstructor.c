#include "../includes/fractol.h"

int ft_rabbit(t_fractal *fractal)
{
    double  zr;
    double  zi;
    double  cr;
    double  ci;
    double  tmp_zr;

    fractal->fractal.depth = 0;
	zi = fractal->fractal.width / fractal->fractal.scale + fractal->fractal.zComplex.imaginery;
	zr = fractal->fractal.height / fractal->fractal.scale + fractal->fractal.zComplex.real;
	cr = -0.0123;
	ci = 0.745;
	if (fractal->fractal.constantC.imaginery != 0)
	{
		cr = fractal->fractal.constantC.real;
		ci = fractal->fractal.constantC.imaginery;
	}
	while ((zr * zr) + (zi * zi) < 4 && fractal->fractal.depth \
	 < fractal->fractal.iteration)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fractal->fractal.depth += 1;
	}
	return (fractal->fractal.depth);
}