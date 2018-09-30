/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:38:51 by mrakhman          #+#    #+#             */
/*   Updated: 2017/12/09 18:30:05 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n, int *sign)
{
	unsigned int	nb;
	size_t			len;

	nb = n;
	len = 1;
	*sign = 0;
	if (n < 0)
	{
		nb = nb * -1;
		*sign = 1;
		len++;
	}
	while (nb / 10 > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	unsigned int	nb;
	char			*str;
	long			k;
	size_t			len;
	int				sign;

	len = count_len(n, &sign);
	nb = n;
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (sign == 1)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	k = len - 1;
	while (k >= sign)
	{
		str[k] = nb % 10 + '0';
		nb = nb / 10;
		k--;
	}
	str[len] = '\0';
	return (str);
}
