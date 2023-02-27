#include "../includes/fractol.h"

int ft_mandelbrot(t_fractal *fractal)
{
    double  zr;
    double  zi;
    double  cr;
    double  ci;
    double  tmp_zr;

    fractal->fractal.depth = 0x0;
    zr = 0x0;
    zi = 0x0;
    ci = fractal->fractal.width / fractal->fractal.scale + fractal->fractal.zComplex.imaginery;
    cr = fractal->fractal.height / fractal->fractal.scale + fractal->fractal.zComplex.real;

    while(((zr * zr) + (zi * zi) < 4) && (fractal->fractal.depth < fractal->fractal.iteration))
    {
        tmp_zr = zr;
        zr = (zr *zr) - (zi * zi) + cr;
        zi = (2 * zi) * tmp_zr + ci;
        fractal->fractal.depth += 1;
    }
    return (fractal->fractal.depth);
}