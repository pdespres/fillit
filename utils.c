/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:31:59 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/15 21:24:43 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(int i)
{
	if (i == 1)
	{
		ft_putstr_fd("error\n", 2);
		exit(42);
	}
}

int		ft_lstlen(t_list *lst)
{
	int		i;

	i = 0;
	while(lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int		sizemini(t_list *tetri)
{
	int		nbr;

	nbr = ft_lstlen(tetri);
	error(nbr == 0);
	if (nbr <= 1)
		return (2);
	else if (nbr <= 4)
		return (4);
	else if (nbr <= 9)
		return (6);
	else if (nbr <= 16)
		return (8);
	else if (nbr <= 25)
		return (10);
	else
		return (12);
}
