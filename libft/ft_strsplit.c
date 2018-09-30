/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 19:08:44 by mrakhman          #+#    #+#             */
/*   Updated: 2017/12/13 18:36:10 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_nb(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	if (s[0] != c)
		len++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			len++;
		i++;
	}
	return (len);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len_w;
	int		i;

	i = 0;
	len_w = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
	{
		len_w++;
		i++;
	}
	return (len_w);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	if (!s)
		return (0);
	if (!(tab = (char **)malloc(sizeof(char*) * word_nb(s, c) + 1)))
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		if (!((tab[i] = malloc(sizeof(char) * word_len(s, c) + 1))))
			return (0);
		j = 0;
		while (*s && *s != c)
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
