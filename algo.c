/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:18:51 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/16 18:59:26 by pdespres         ###   ########.fr       */
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
	if (x < 0 || x > maxsize || y < 0 || y > maxsize)
		return (0);
	if (map[x][y] == EMPTY)
	{	
		if (piece == 3 || (piece < 3 && check_block(map, tetri, maxsize, piece + 1)))
		{
			map[x][y] = (tetri->num + 'A');
			return (1)
		}
	}
	return (0);
}

int		put_tetri(char **map, t_list *tetri, int maxsize, int decalage)
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
				if (decalage == 0)
					tetri->p[0][0] = x;
				tetri->p[0][1] = y;
				if (check_block(map, tetri, maxsize, 0))
				{
					map[x][y] = (tetri->num + 'A');
					return (1);
				}
				else
					decalage--;
			}
		}
	}
	return (0);
}

int		resolve(char **map, t_list *tetri, int maxsize)
{
	t_list	*temp;
	int		decalage;

	temp = tetri;
	decalage = 0;
	if (put_tetri(map, temp, maxsize))
	{
		if (temp->next = NULL)
			return (1);
		while (!resolve(map, temp->next, maxsize))
		{
			clear_tetri();
			decalage++;
		}
	}
	else
		return (0);
}
