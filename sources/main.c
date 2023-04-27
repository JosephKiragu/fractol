/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <jkiragu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:27:57 by jkiragu           #+#    #+#             */
/*   Updated: 2023/03/03 18:17:30 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractal_selector(t_fractal *fract, char **argv)
{
	if (!ft_strcmp(argv[1], "julia"))
		fract->fract.type = 1;
	else if (!ft_strcmp(argv[1], "mandelbrot"))
		fract->fract.type = 2;
	else if (!ft_strcmp(argv[1], "rabbit"))
		fract->fract.type = 3;
	else
	{
		printf("\nInput Error : type julia or mandelbrot or rabbit");
		exit(EXIT_SUCCESS);
	}
}

void	ft_initialize(t_fractal *fract, char **argv)
{
	fract->fract.z_comp.imgn = -2.0;
	fract->fract.z_comp.real = -1.2;
	fract->fract.c_constant.imgn = 0x0;
	fract->fract.c_constant.real = 0x0;
	if (argv[2])
		fract->fract.iter = atoi(argv[2]);
	if (argv[3] && argv[4])
	{
		fract->fract.c_constant.imgn = atof(argv[3]);
		fract->fract.c_constant.real = atof(argv[4]);
	}
	fract->fract.iter = 50;
	fract->fract.scale = 300.00;
	fract->colour.red = 0x42;
	fract->colour.green = 0x32;
	fract->colour.blue = 0x22;
	fract->fract.height = 0x0;
	fract->fract.width = 0x0;
}

int	main(int argc, char **argv)
{
	t_fractal	fract;

	if (argc >= 2)
	{
		fractal_selector(&fract, argv);
		fract.mlx.mlx = mlx_init();
		fract.mlx.win = mlx_new_window(fract.mlx.mlx, WIDTH, HEIGHT, MSG);
		fract.mlx.img = mlx_new_image(fract.mlx.mlx, WIDTH, HEIGHT);
		fract.mlx.addr = mlx_get_data_addr(fract.mlx.img, \
						&fract.mlx.bits_per_pixel, \
						&fract.mlx.line_length, &fract.mlx.endian);
		ft_initialize(&fract, argv);
		ft_draw(&fract);
		mlx_key_hook(fract.mlx.win, key_hook, &fract);
		mlx_mouse_hook(fract.mlx.win, mouse_hook, &fract);
		mlx_loop(fract.mlx.mlx);
	}
	else
	{
		printf("\n ERROR : Missing argument\n\n");
	}
	return (EXIT_SUCCESS);
}
