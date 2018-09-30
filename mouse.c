/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 22:32:57 by mrakhman          #+#    #+#             */
/*   Updated: 2018/09/30 17:34:21 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_zoom(int k, int x, int y, t_env *e)
{
	if (k == MOUSE_ZOOM_IN)
	{
		e->x += x / 5;
		e->y += y / 5;
		e->z = e->z * 1.2;
		e->y = e->y * 1.2;
		e->x = e->x * 1.2;
	}
	if (k == MOUSE_ZOOM_OUT)
	{
		e->x -= x / 5;
		e->y -= y / 5;
		e->z = e->z / 1.2;
		e->y = e->y / 1.2;
		e->x = e->x / 1.2;
	}
	e->fractal(e);
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return (0);
	e->option_x = x;
	e->option_y = y;
	e->fractal(e);
	return (0);
}

int		close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
