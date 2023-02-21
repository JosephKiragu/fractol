#include "../includes/fractol.h"

void ft_print_pixel(t_fractal *fractal, int depth)
{
    int pos;
    pos = (fractal->fractal.height + (fractal->fractal.width * WIDTH)) * 4;
    if (fractal->fractal.height < WIDTH && \
        fractal->fractal.width < HEIGHT && \
        depth == fractal->fractal.iteration)
    {
        fractal->mlx.addr[pos] = 0x00;
        fractal->mlx.addr[pos + 1] = 0x00;
        fractal->mlx.addr[pos + 2] = 0x00;
    }
    else if (fractal->fractal.width < HEIGHT && fractal->fractal.height < WIDTH)
    {
        fractal->mlx.addr[pos] = fractal->colour.red + (depth * 2.42);
        fractal->mlx.addr[pos + 1] = fractal->colour.green + (depth * 3.52);
        fractal-> mlx.addr[pos + 2] = fractal->colour.blue + (depth * 4.65);
    }
}