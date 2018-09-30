/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 21:05:55 by mrakhman          #+#    #+#             */
/*   Updated: 2018/05/01 17:06:01 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*move_line(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	while (j < BUFF_SIZE)
		str[j++] = 0;
	return (str);
}

char	*ft_str_join(char *s1, char *s2, size_t p)
{
	char	*tab;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	if (p == 0)
		return (s1);
	if ((tab = (char *)malloc(ft_strlen(s1) + p + 1)) == 0)
		return (NULL);
	while (s1 && s1[i])
		tab[k++] = s1[i++];
	while (s2[j] && s2[j] != '\n')
		tab[k++] = s2[j++];
	tab[k] = '\0';
	if (s1)
		free(s1);
	return (tab);
}

int		get_next_line_loop(const int fd, char *buf, char **line)
{
	int	i;
	int	read_ret;

	while (1)
	{
		if ((read_ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		i = 0;
		while (i < read_ret && buf[i] && (buf[i] != '\n'))
			i++;
		*line = ft_str_join(*line, buf, i);
		if (buf[i] == '\n' || read_ret < BUFF_SIZE)
		{
			move_line(buf);
			if (read_ret < BUFF_SIZE && !**line)
				return (0);
			return (1);
		}
		ft_bzero(buf, BUFF_SIZE);
	}
	return (-1);
}

int		ft_get_next_line(const int fd, char **line)
{
	int				i;
	static char		buf[BUFF_SIZE];

	if (fd < 0 || line == NULL)
		return (-1);
	i = 0;
	*line = malloc(1);
	**line = 0;
	if (buf[0])
	{
		while (buf[i] && buf[i] != '\n')
			i++;
		*line = ft_str_join(*line, buf, i);
		if (buf[i] == '\n')
		{
			move_line(buf);
			return (1);
		}
		move_line(buf);
	}
	return (get_next_line_loop(fd, buf, line));
}
