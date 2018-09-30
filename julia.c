/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 21:54:16 by mrakhman          #+#    #+#             */
/*   Updated: 2018/09/30 17:27:43 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		julia_iter(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->i_max)
	{
		e->jul.tmp = e->jul.zr;
		e->jul.zr = e->jul.zr * e->jul.zr - e->jul.zi * e->jul.zi - 0.8 +
			(0.6 / ((double)e->option_x / (double)WIN_WIDTH));
		e->jul.zi = 2 * e->jul.zi * e->jul.tmp + 0.27015 /
			((double)e->option_y / (double)WIN_HEIGHT);
		if (e->jul.zr * e->jul.zr + e->jul.zi * e->jul.zi >= 4)
			return (i);
	}
	return (i);
}

void			julia(t_env *e)
{
	intmax_t	x;
	intmax_t	y;

	x = e->x;
	while (++x < WIN_WIDTH + e->x)
	{
		y = e->y;
		while (++y < WIN_HEIGHT + e->y)
		{
			e->jul.zr = (long double)x / e->z + e->jul.x1;
			e->jul.zi = (long double)y / e->z + e->jul.y1;
			put_pixel(e, x - e->x, y - e->y, get_color(julia_iter(e), e));
		}
	}
	mlx_put_image_to_window(e->mlx, e->window, e->image.img_ptr, 0, 0);
}
