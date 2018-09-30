/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:19:06 by mrakhman          #+#    #+#             */
/*   Updated: 2018/09/30 17:51:32 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_menu(void)
{
	ft_putendl("-------------------------");
	ft_putendl("Move: 	Arrows < ^ >  	 ");
	ft_putendl("Zoom: 	Scroll        	 ");
	ft_putendl("Reset: 	R          		 ");
	ft_putendl("-------------------------");
}

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
		print_usage();
	if (ft_strequ(argv[1], "mandelbrot"))
		env.fractal = mandelbrot;
	else if (ft_strequ(argv[1], "julia"))
		env.fractal = julia;
	else if (ft_strequ(argv[1], "burningship"))
		env.fractal = burningship;
	else
		print_usage();
	env_init(&env);
	print_menu();
	env.window = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "fract'ol");
	mlx_key_hook(env.window, key_hook, &env);
	mlx_hook(env.window, 6, 0, mouse_move, &env);
	mlx_hook(env.window, 17, 0, close_window, &env);
	mlx_mouse_hook(env.window, mouse_zoom, &env);
	env.fractal(&env);
	mlx_loop(env.mlx);
	return (0);
}
