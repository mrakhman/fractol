/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 18:36:04 by mrakhman          #+#    #+#             */
/*   Updated: 2018/09/27 14:38:15 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_word_nb(char const *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	if (s[0] != ' ' && s[0] != '\t')
		len++;
	while (s[i])
	{
		if ((s[i] == ' ' || s[i] == '\t') && \
			(s[i + 1] != ' ' && s[i + 1] != '\t' && s[i + 1] != '\0'))
			len++;
		i++;
	}
	return (len);
}

static size_t	word_len(char const *s)
{
	size_t	len_w;
	int		i;

	i = 0;
	len_w = 0;
	if (!s)
		return (0);
	while (s[i] && (s[i] != ' ' && s[i] != '\t'))
	{
		len_w++;
		i++;
	}
	return (len_w);
}

static void		*noleaks(char **tab, size_t i)
{
	while (i > 0)
	{
		i--;
		ft_strdel(&tab[i]);
	}
	ft_strdel(tab);
	return (0);
}

char			**ft_split(char const *s)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	if (!s)
		return (0);
	if (!(tab = (char **)malloc(sizeof(char*) * ft_word_nb(s) + 1)))
		return (0);
	while (*s)
	{
		while (*s && (*s == ' ' || *s == '\t'))
			s++;
		if (!*s)
			break ;
		if (!((tab[i] = malloc(sizeof(char) * word_len(s) + 1))))
			return (noleaks(tab, i));
		j = 0;
		while (*s && (*s != ' ' && *s != '\t'))
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
