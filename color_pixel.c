/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:03:49 by mrakhman          #+#    #+#             */
/*   Updated: 2018/09/30 17:28:42 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(int a, t_env *e)
{
	unsigned int	c;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (a == e->i_max)
		return (e->color_max);
	r = (a * 5) * e->color_value;
	g = (255 - (a * 10)) * e->color_value;
	b = (255 - (a * 2)) * e->color_value;
	c = (r << 16) + (g << 8) + b;
	return (c);
}

void	put_pixel(t_env *e, int x, int y, int color)
{
	int		i;

	i = (x * 4) + (y * e->image.size_l);
	e->image.data[i] = color;
	e->image.data[++i] = color >> 8;
	e->image.data[++i] = color >> 16;
}
