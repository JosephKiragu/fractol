/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <jkiragu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:39:09 by jkiragu           #+#    #+#             */
/*   Updated: 2023/03/03 18:06:23 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_print_pixel(t_fractal *fract, int dp)
{
	int	pos;

	pos = (fract->fract.height + (fract->fract.width * WIDTH)) * 4;
	if (fract->fract.height < WIDTH && \
		fract->fract.width < HEIGHT && \
		dp == fract->fract.iter)
	{
		fract->mlx.addr[pos] = 0x00;
		fract->mlx.addr[pos + 1] = 0x00;
		fract->mlx.addr[pos + 2] = 0x00;
	}
	else if (fract->fract.width < HEIGHT && fract->fract.height < WIDTH)
	{
		fract->mlx.addr[pos] = fract->colour.red + (dp * 2.42);
		fract->mlx.addr[pos + 1] = fract->colour.green + (dp * 3.52);
		fract-> mlx.addr[pos + 2] = fract->colour.blue + (dp * 4.65);
	}
}
