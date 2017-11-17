/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:18:51 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/17 15:21:13 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* opti check larg & ht max en put_tetri								*/
/* opti check doublon en resolve										*/

static void	destroy_tetri()
{

}

static int	check_block(char *map, char **tetri, int ind, int block)
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

static int	put_tetri(char *map, char **tetri, int ind, char *offset)
{
	char	i;

	i = *offset;
	while (map[i] && i < tetri[0][0] * tetri[0][0])
	{
		if (map[i] == EMPTY)
		{
			if (check_block(map, tetri, side_sz, 1))
			{
				map[i] = ind - 1 + 'A';
				*offset = i;
				return (1);
			}
		}
		i++;
	}
	*offset = i;
	return (0);
}

int		resolve(char *map, char **tetri, int ind)
{
	char		offset;

	offset = 0;
	while (offset < tetri[0][0] * tetri[0][0])
	{
		if (put_tetri(map, tetri, ind, &offset))
		{
			if (tetri[ind + 1] = NULL)
				return (1);
			if (resolve(map, tetri, ind + 1))
				return (1);
			destroy_tetri();
		}
		offset++;	
	}
	return (0);
}
