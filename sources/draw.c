/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <jkiragu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:35:29 by jkiragu           #+#    #+#             */
/*   Updated: 2023/03/03 18:11:00 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_draw(t_fractal *fract)
{
	int		dp;
	double	temp_wid;

	temp_wid = fract->fract.width;
	while (fract->fract.height < WIDTH)
	{
		fract->fract.width = temp_wid;
		while (fract->fract.width < WIDTH)
		{
			if (fract->fract.type == 1)
				dp = ft_julia(fract);
			if (fract->fract.type == 2)
				dp = ft_mandelbrot(fract);
			if (fract->fract.type == 3)
				dp = ft_rabbit(fract);
			ft_print_pixel(fract, dp);
			fract->fract.width += 1;
		}
		fract->fract.height += 1;
	}
	mlx_put_image_to_window(fract->mlx.mlx, fract->mlx.win, \
			fract->mlx.img, 0, 0);
	return (EXIT_SUCCESS);
}
