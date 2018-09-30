/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 20:49:51 by mrakhman          #+#    #+#             */
/*   Updated: 2018/09/30 17:38:53 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH		 	600
# define WIN_HEIGHT			400
# define MENU_WIDTH			250

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_ZOOM_IN		4
# define MOUSE_ZOOM_OUT		5
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define NUM_PAD_PLUS		69
# define NUM_PAD_MINUS		78
# define ESC				53
# define KEY_RESET 			15

# include "libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

typedef struct		s_image
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			size_l;
	int			endian;
}					t_image;

typedef struct		s_fract
{
	long double			x1;
	long double			x2;
	long double			y1;
	long double			y2;
	long double			zr;
	long double			zi;
	long double			cr;
	long double			ci;
	long double			tmp;
}					t_fract;

typedef struct		s_env
{
	void			*mlx;
	void			*window;
	t_image			image;
	intmax_t		x;
	intmax_t		y;
	intmax_t		z;
	int				option_x;
	int				option_y;
	void			(*fractal)();
	unsigned int	color_max;
	int				color_value;
	int				i_max;
	t_fract			mdb;
	t_fract			jul;
}					t_env;

void				env_init(t_env *env);
int					get_color(int a, t_env *e);
void				put_pixel(t_env *e, int x, int y, int color);
int					key_hook(int key, t_env *e);
int					mouse_zoom(int k, int x, int y, t_env *e);
int					mouse_move(int x, int y, t_env *e);
int					close_window(void *param);
void				print_usage(void);

/*
** fractals:
*/
void				mandelbrot(t_env *e);
void				julia(t_env *e);
void				burningship(t_env *e);

#endif
