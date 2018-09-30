/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:35:43 by mrakhman          #+#    #+#             */
/*   Updated: 2017/12/08 22:51:49 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		nb = nb * -1;
		ft_putchar_fd('-', fd);
	}
	if (nb / 10 > 0)
	{
		ft_putnbr_fd((nb / 10), fd);
	}
	ft_putchar_fd((nb % 10 + '0'), fd);
}
