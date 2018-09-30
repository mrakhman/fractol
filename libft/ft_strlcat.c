/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:23:49 by mrakhman          #+#    #+#             */
/*   Updated: 2017/12/13 18:24:15 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s1_fin;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size && dst[i])
		i++;
	s1_fin = i;
	while (src[i - s1_fin] && i < size - 1)
	{
		dst[i] = src[i - s1_fin];
		i++;
	}
	if (s1_fin < size)
		dst[i] = '\0';
	return (s1_fin + ft_strlen(src));
}
