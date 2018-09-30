/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:34:49 by mrakhman          #+#    #+#             */
/*   Updated: 2017/12/09 18:46:23 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	tab_start_char(char const *s)
{
	size_t	i;
	size_t	start;

	i = 0;
	if (!s)
		return (0);
	if (s[0] != '\t' && s[0] != '\n' && s[0] != ' ')
		start = 0;
	while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ') && s[i])
	{
		i++;
		if (s[i] != '\t' && s[i] != '\n' && s[i] != ' ')
			start = i;
	}
	return (start);
}

static size_t	tab_end_char(char const *s)
{
	size_t	i;
	size_t	end;

	if (!s)
		return (0);
	i = ft_strlen(s) - 1;
	if (s[i] != '\t' && s[i] != '\n' && s[i] != ' ')
		end = 1 + i;
	while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ') && (i > 0))
	{
		i--;
		if (s[i] != '\t' && s[i] != '\n' && s[i] != ' ')
			end = 1 + i;
	}
	return (end);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*tab;
	size_t	start;
	size_t	end;

	if (!s)
		return (0);
	j = 0;
	start = tab_start_char(s);
	end = tab_end_char(s);
	tab = (char *)malloc(end - start + 1);
	if (!tab)
		return (NULL);
	i = start;
	while (i < end)
		tab[j++] = s[i++];
	tab[j] = '\0';
	return (tab);
}
