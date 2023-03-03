/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotSetConstructor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <jkiragu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:38:12 by jkiragu           #+#    #+#             */
/*   Updated: 2023/03/03 18:13:23 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_mandelbrot(t_fractal *fract)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fract->fract.dp = 0x0;
	zr = 0x0;
	zi = 0x0;
	ci = fract->fract.width / fract->fract.scale + \
			fract->fract.z_comp.imgn;
	cr = fract->fract.height / fract->fract.scale + \
			fract->fract.z_comp.real;
	while (((zr * zr) + (zi * zi) < 4) && (fract->fract.dp \
		< fract->fract.iter))
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fract->fract.dp += 1;
	}
	return (fract->fract.dp);
}
