/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 22:32:24 by mrakhman          #+#    #+#             */
/*   Updated: 2018/09/30 17:48:12 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_zoom(int key, t_env *e)
{
	if (key == NUM_PAD_PLUS)
	{
		e->x += WIN_WIDTH / 12;
		e->y += WIN_HEIGHT / 12;
		e->z = e->z * 1.2;
		e->x = e->x * 1.2;
		e->y = e->y * 1.2;
	}
	else if (key == NUM_PAD_MINUS)
	{
		if (e->z / 1.2 < 10)
			return ;
		e->x -= WIN_WIDTH / 12;
		e->y -= WIN_HEIGHT / 12;
		e->z = e->z / 1.2;
		e->x = e->x / 1.2;
		e->y = e->y / 1.2;
	}
}

static void	key_reset(int key, t_env *e)
{
	if (key == KEY_RESET)
	{
		e->x = 0;
		e->y = 0;
		e->z = 150;
		e->option_x = WIN_WIDTH / 2;
		e->option_y = WIN_HEIGHT / 2;
		e->color_max = 0x000000;
		e->i_max = 50;
		e->color_value = 1;
	}
}

static void	key_move(int key, t_env *e)
{
	if (key == ARROW_LEFT)
		e->x -= 100;
	else if (key == ARROW_RIGHT)
		e->x += 100;
	else if (key == ARROW_UP)
		e->y -= 100;
	else
		e->y += 100;
}

int			key_hook(int key, t_env *e)
{
	key_zoom(key, e);
	key_move(key, e);
	key_reset(key, e);
	if (key == ESC)
	{
		mlx_destroy_window(e->mlx, e->window);
		exit(0);
	}
	e->fractal(e);
	return (0);
}
