/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:39:23 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/13 10:37:32 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	while ((*alst)->next)
	{
		ptr = (*alst)->next;
		ft_lstdelone(&(*alst), del);
		(*alst) = ptr;
	}
	ft_lstdelone(&(*alst), del);
	*alst = NULL;
}
