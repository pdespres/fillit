/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:18:51 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/16 16:30:44 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_block(char **map, t_list tetri, int maxsize, int piece)
{
	static char	x;
	static char	y;

	if (piece == 0)
	{
		x = tetri->p[0][0];
		y = tetri->p[0][1};
	}
	x += (piece > 0 ? tetri->p[piece][0] : 0);
	y += (piece > 0 ? tetri->p[piece][1] : 0);
	if (map[x][y] == EMPTY)
	{
		if (piece == 3 || (piece < 3 && check_block(map, tetri, maxsize, piece + 1)))
		{
			map[x][y] = (tetri->num - 1 + 'A');
			return (1)
		}
	}
	return (0);
}

int		put_tetri(char **map, t_list *tetri, int maxsize)
{
	char	x;
	char	y;

	x = 0;
	y = 0;
	while (y++ <= (maxsize - tetri->hmax))
	{
		while (x++ <= (maxsize - tetri->lmax))
		{
			if (map[x][y] == EMPTY)
			{
				tetri->p[0][0] = x;
				tetri->p[0][1] = y;
				if (check_block(map, tetri, maxsize, 0))
				{
					map[x][y] = (tetri->num - 1 + 'A');
					return (1);
				}
			}
		}
	}
	return (0);
}

int		resolve(char **map, t_list *tetri, int maxsize)
{
	t_list	*temp;

	temp = tetri;
	if (put_tetri(map, temp, maxsize))
	{
		temp = temp->next;
		if (temp = NULL)
			return (1);
		if (!resolve(map, temp, maxsize))
		{
			clear_tetri();
		}
	}
	else
		return (0);
}
