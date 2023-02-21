#include "../includes/fractol.h"


void	ft_rgb_randomizer(t_fractal *fractal)
{
	fractal->colour.red += 50;
	fractal->colour.green += 41;
	fractal->colour.blue += 10;
}


int ft_julia(t_fractal *fractal)
{
    double  zr;
    double  zi;
    double  cr;
    double  ci;
    double  tmp_zr;

    fractal->fractal.depth = 0;
    //Confirm what axis corresponds to the y axis and x axis to properly assign zi & zr 
    zi = fractal->fractal.width / fractal->fractal.scale + fractal->fractal.zComplex.imaginery; 
    zr = fractal->fractal.height / fractal->fractal.scale + fractal->fractal.zComplex.real;
    cr = -0.8;
    ci = 0.156;
    if (fractal->fractal.constantC.imaginery != 0)
    {
        cr = fractal->fractal.constantC.imaginery;
        ci = fractal->fractal.constantC.real;
    }
    while ((zr * zr) + (zi *zi) < 4 && fractal->fractal.depth < fractal->fractal.iteration)
    {
        tmp_zr = zr;
        zr = (zr * zr) - (zi * zi) + cr;
        zi = (2 * zi) * tmp_zr + ci;
        fractal->fractal.depth += 1;
    }
    return (fractal->fractal.depth);
}