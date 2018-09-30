/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:01:03 by mrakhman          #+#    #+#             */
/*   Updated: 2017/12/12 17:49:11 by mrakhman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (!alst || !*alst)
		return ;
	del((*alst)->content, (*alst)->content_size);
	ft_lstdel(&((*alst)->next), del);
	free(*alst);
	*alst = NULL;
}
