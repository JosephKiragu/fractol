/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <jkiragu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:32:45 by jkiragu           #+#    #+#             */
/*   Updated: 2023/03/03 18:06:12 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_hook(int hook, t_fractal *fract)
{
	if (hook == ESC || hook == DESTROY)
	{
		printf("GOOD");
		ft_quit(fract->pid);
		exit (EXIT_SUCCESS);
	}
	else if (hook == SPACE)
		ft_rgb_randomizer(fract);
	else if (hook == UP)
		fract->fract.z_comp.imgn -= 10 / fract->fract.scale;
	else if (hook == DOWN)
		fract->fract.z_comp.imgn += 10 / fract->fract.scale;
	else if (hook == LEFT)
		fract->fract.z_comp.real -= 10 / fract->fract.scale;
	else if (hook == RIGHT)
		fract->fract.z_comp.real += 10 / fract->fract.scale;
	fract->fract.height = 0;
	fract->fract.width = 0;
	ft_draw(fract);
	return (EXIT_SUCCESS);
}

void	ft_zoom_in(int x, int y, t_fractal *fract)
{
	double	scalar;

	if (fract->fract.scale >= SCALE_LIMIT)
		return ;
	else
	{
		scalar = fract->fract.scale * SCALE_PERC;
		fract->fract.z_comp.real = ((double) x / fract->fract.scale \
				+ fract->fract.z_comp.real - (scalar / 2));
		fract->fract.z_comp.real += (scalar / 2) - ((double)x / scalar);
		fract->fract.z_comp.imgn = ((double) y / \
				fract->fract.scale + fract->fract.z_comp.imgn) \
				- (scalar / 2);
		fract->fract.z_comp.imgn \
				+= (scalar / 2) - ((double) y / scalar);
		fract->fract.scale *= SCALE_PERC;
		fract->fract.iter += SCALE_ITER;
		ft_rgb_randomizer(fract);
	}
}

void	ft_zoom_out(int x, int y, t_fractal *fract)
{
	double	scalar;

	scalar = fract->fract.scale / SCALE_PERC;
	fract->fract.z_comp.real = ((double) x / fract->fract.scale + \
			fract->fract.z_comp.real) - (scalar / 2);
	fract->fract.z_comp.real += (scalar / 2) - ((double) x / scalar);
	fract->fract.z_comp.imgn = ((double) y / fract->fract.scale \
			+ fract->fract.z_comp.imgn) - (scalar / 2);
	fract->fract.z_comp.imgn += (scalar / 2) - ((double)y / scalar);
	fract->fract.scale /= SCALE_PERC;
	fract->fract.iter -= SCALE_ITER;
	ft_rgb_randomizer(fract);
}

int	mouse_hook(int hook, int x, int y, t_fractal *fract)
{
	if (hook == SCROLL_DOWN)
		ft_zoom_in(x, y, fract);
	if (hook == SCROLL_UP)
		ft_zoom_out(x, y, fract);
	fract->fract.height = 0x0;
	fract->fract.width = 0x0;
	ft_draw(fract);
	return (EXIT_SUCCESS);
}
