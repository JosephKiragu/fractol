/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rabbitSetConstructor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <jkiragu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:39:21 by jkiragu           #+#    #+#             */
/*   Updated: 2023/03/03 18:16:39 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_rabbit(t_fractal *fract)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fract->fract.dp = 0;
	zi = fract->fract.width / fract->fract.scale + fract->fract.z_comp.imgn;
	zr = fract->fract.height / fract->fract.scale + fract->fract.z_comp.real;
	cr = -0.0123;
	ci = 0.745;
	if (fract->fract.c_constant.imgn != 0)
	{
		cr = fract->fract.c_constant.real;
		ci = fract->fract.c_constant.imgn;
	}
	while ((zr * zr) + (zi * zi) < 4 && fract->fract.dp < fract->fract.iter)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fract->fract.dp += 1;
	}
	return (fract->fract.dp);
}
