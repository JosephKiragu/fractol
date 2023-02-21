#include "../includes/fractol.h"

int ft_draw(t_fractal *fractal)
{
    int depth;
    double temp_width;

    temp_width = fractal->fractal.width;
    while (fractal->fractal.height < WIDTH)
    {
        fractal->fractal.width = temp_width;
        while(fractal->fractal.width < WIDTH)
        {
            if (fractal->fractal.type == 1)
                depth = ft_julia(fractal);
            ft_print_pixel(fractal, depth);
            fractal->fractal.width += 1;
        }
        fractal->fractal.height += 1;
    }
    mlx_put_image_to_window(fractal->mlx.mlx, fractal->mlx.win, fractal->mlx.img, 0, 0);
    return (EXIT_SUCCESS);
}