/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:18:51 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/16 10:02:05 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		pose_tetri(char **map, t_list *tetri, int maxsize, int piece)
{
	char	x;
	char	y;

	x = 0;
	y = 0;
	while (x++ <= (maxsize - tetri->lmax))
	{
		while (y++ <= (maxsize -tetri->hmax))
		{
			if (map[x][y] == EMPTY)
			{
				if (piece == 3)
				{
					map[x][y] = (tetri->num - 1 + 'A');
				}
				if (pose_tetri(map, tetri, maxsize, piece + 1))
			}
		}
	}
	return (1);
}

int		resolve(char **map, t_list *tetri, int maxsize)
{
	t_list	*temp;

	temp = tetri;
	if (pose_tetri(map, temp, maxsize, 0))
	{
		temp = temp->next;
		if (temp = NULL)
			return (1);
		if (!resolve(map, temp, maxsize))
		{

		}
	}
	else
		return (0);
}
