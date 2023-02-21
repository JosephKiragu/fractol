#include "../includes/fractol.h"

void fractal_selector(t_fractal *fractal, char **argv)
{
	if (!ft_strcmp(argv[1], "-julia"))
		fractal->fractal.type = 1;
	else
	{
		printf("\nError : type -julia");
		exit(EXIT_SUCCESS);
	}
}


void ft_initialize(t_fractal *fractal, char **argv)
{
	// initializing the fractal initial points both real and imaginery 
	fractal->fractal.zComplex.imaginery = -2.0;
	fractal->fractal.zComplex.real = -1.2;
	fractal->fractal.constantC.imaginery = 0x0;
	fractal->fractal.constantC.real = 0x0;
	if(argv[2])
		fractal->fractal.iteration = atoi(argv[2]);
	if(argv[3] && argv[4])
	{
		fractal->fractal.constantC.imaginery = atof(argv[3]);
		fractal->fractal.constantC.real = atof(argv[4]);
	}
	fractal->fractal.iteration = 50;
	fractal->fractal.scale = 300.00;
	fractal->colour.red = 0x42;
	fractal->colour.green = 0x32;
	fractal->colour.blue = 0x22;
	fractal->fractal.height = 0x0;
	fractal->fractal.width = 0x0;
}




int main (int argc, char **argv)
{
	t_fractal	fract;

	if (argc >=2)
	{
		fractal_selector(&fract, argv);
		fract.mlx.mlx = mlx_init();
		fract.mlx.win = mlx_new_window(fract.mlx.mlx, WIDTH, HEIGHT, MSG);
		fract.mlx.img = mlx_new_image(fract.mlx.mlx, WIDTH, HEIGHT);
		fract.mlx.addr = mlx_get_data_addr(fract.mlx.img, &fract.mlx.bits_per_pixel, 
						&fract.mlx.line_length, &fract.mlx.endian);
		ft_initialize(&fract, argv);
		ft_draw(&fract);
		mlx_key_hook(fract.mlx.win, key_hook, &fract);
		mlx_mouse_hook(fract.mlx.win, mouse_hook, &fract);
		// mlx_hook(fract.mlx.win, DESTROY, 0, close_afplay, &fract);
		mlx_loop(fract.mlx.mlx);
	}
	else
	{
		printf("\n ERROR : Missing argument\n\n");
	}
	return (EXIT_SUCCESS);
}		