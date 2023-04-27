/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <jkiragu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:37:40 by jkiragu           #+#    #+#             */
/*   Updated: 2023/03/03 16:10:25 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_quit(int pid)
{
	kill(pid, SIGPIPE);
}

int	lol(void)
{
	exit (0);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0x0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_rgb_randomizer(t_fractal *fract)
{
	fract->colour.red += 50;
	fract->colour.green += 41;
	fract->colour.blue += 10;
}
