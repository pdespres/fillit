/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:31:59 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/21 18:10:31 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i - 1);
}

char			sizemini(char **tetri)
{
	int		nbr;

	nbr = tablen(tetri);
	ft_error(nbr == 0);
	if (nbr <= 1)
		return (2);
	else if (nbr <= 4)
		return (3);
	else if (nbr <= 9)
		return (5);
	else if (nbr <= 16)
		return (7);
	else if (nbr <= 25)
		return (9);
	else
		return (11);
}

void			ft_init(int *j, int *refresh)
{
	*j = 1;
	*refresh = 0;
}

void			ft_find_hash(char *str, int *x, int *refresh)
{
	while (str[*x] != '#')
	{
		*x += 1;
		*refresh += 1;
	}
}
