/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 21:03:33 by mrakhman          #+#    #+#             */
/*   Updated: 2018/09/30 17:46:25 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_mandelbrot(t_fract *m)
{
	m->x1 = -2.1;
	m->x2 = 0.6;
	m->y1 = -1.2;
	m->y2 = 1.2;
	m->zr = 0;
	m->zi = 0;
	m->cr = 0;
	m->ci = 0;
	m->tmp = 0;
}

static void		init_julia(t_fract *j)
{
	j->x1 = -2.1;
	j->x2 = 0.6;
	j->y1 = -1.2;
	j->y2 = 1.2;
	j->zr = 0;
	j->zi = 0;
	j->cr = 0;
	j->ci = 0;
	j->tmp = 0;
}

void			env_init(t_env *env)
{
	env->x = 0;
	env->y = 0;
	env->z = 150;
	env->option_x = WIN_WIDTH / 2;
	env->option_y = WIN_HEIGHT / 2;
	env->color_max = 0x000000;
	env->i_max = 50;
	env->color_value = 1;
	env->mlx = mlx_init();
	env->image.img_ptr = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	env->image.data = mlx_get_data_addr(env->image.img_ptr,
		&(env->image.bpp), &(env->image.size_l), &(env->image.endian));
	init_mandelbrot(&env->mdb);
	init_julia(&env->jul);
}
