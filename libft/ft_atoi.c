/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:38:00 by mrakhman          #+#    #+#             */
/*   Updated: 2017/12/13 19:43:13 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_return(long long nb)
{
	if (nb < INT_MIN)
		return (0);
	if (nb > INT_MAX)
		return ((int)nb);
	return (nb);
}

int			ft_atoi(const char *str)
{
	int			negat;
	long long	nb;

	negat = 1;
	nb = 0;
	while ((*str >= 9 && *str <= 19) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		negat = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && (nb < 2147483648 ||
				(nb <= 2147483648 && negat == -1)))
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	nb *= negat;
	return (nb_return(nb));
}
