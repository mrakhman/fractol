/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:08:02 by mrakhman          #+#    #+#             */
/*   Updated: 2017/12/08 22:23:58 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((unsigned char)*s1 == (unsigned char)*s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	if ((unsigned char)*s1 != (unsigned char)*s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
