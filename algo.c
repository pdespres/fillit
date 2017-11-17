/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:18:51 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/17 12:59:57 by pdespres         ###   ########.fr       */
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

int		put_tetri(char *map, char *tetri, int side_sz, char offset)
{
	char	i;

	i = 0;
	while (i < side_sz * side_sz)
	{
		if (map[i] == EMPTY)
		{
			if (offset > 0)
		}
	}
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

int		resolve(char *map, char **tetri, int side_sz, int ind)
{
	char		offset;

	offset = 0;
	while (1)
	{
		if (put_tetri(map, tetri[ind], side_sz, offset))
		{
			if (tetri[ind + 1] = NULL)
				return (1);
			while (!resolve(map, tetri, side_sz, ind + 1))
			{
				clear_tetri();
			}
		}
		else
			offset++;	
	}
	return (0);
}
