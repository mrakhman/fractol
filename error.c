/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 21:25:02 by mrakhman          #+#    #+#             */
/*   Updated: 2018/09/30 17:38:40 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	ft_putendl("Usage: ./fractol name");
	ft_putendl("			  -> mandelbrot");
	ft_putendl("			  -> julia");
	ft_putendl("			  -> burningship");
	exit(1);
}
