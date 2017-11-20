/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:18:51 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/20 14:03:55 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* opti check larg & ht max en put_tetri								*/
/* opti check doublon en resolve										*/

static void	destroy_tetri(t_char *map, char **tetri, int ind, char pos)
{
	int		temp;
	int		block;

	block = 4;
	while (block > 0)
	{
		temp = pos;
		temp = pos % SIDE - tetri[ind][1] + tetri[ind][block] % 5;
		temp += (tetri[ind][block] / 5) * SIDE + pos / 5 * SIDE;
		map[temp] = EMPTY;
		block--;
	}
}

static int	check_block(t_char *map, char **tetri, int ind, char pos)
{
	static int	block = 1;
	int			temp;

	block++;
	temp = pos;

	if (tetri[ind][1] - tetri[ind][block] % 5 > pos % SIDE 
			|| tetri[ind][block] % 5 - tetri[ind][1] >= SIDE - pos % SIDE
			|| tetri[ind][block] / 5 > SIDE - pos / SIDE
	   )
	{
		block = 1;
		return (0);
	}
	temp = pos % SIDE - tetri[ind][1] + tetri[ind][block] % 5;
//	if (ind == 4)
//		printf("start %d block %d  calcul: 1 %d, 2 %d result %d", pos, block, tetri[ind][1], tetri[ind][block], temp);
	temp += (tetri[ind][block] / 5) * SIDE + pos / SIDE * SIDE;
//	if (ind == 4)
//		printf(" -> %d\n", temp);
	if (map[temp] == EMPTY)
	{
//		if (ind == 4)
//			printf("ok empty block %d en %d\n", block, temp);
		if (block == 4 || (block < 4 && check_block(map, tetri, ind, pos)))
		{
			map[temp] = ind - 1 + 'A';
			block = 1;
			return (1);
		}
	}
	block = 1;
	return (0);
}

static int	put_tetri(t_char *map, char **tetri, int ind, char *offset)
{
	int			i;

	i = *offset;
	while (map[i] && i < SIDE * SIDE)
	{
		if (map[i] == EMPTY)
		{
			if (check_block(map, tetri, ind, i))
			{
				map[i] = ind - 1 + 'A';
				*offset = i + 1;
				return (1);
			}
		}
		i++;
	}
	*offset = i;
	return (0);
}

int		resolve(t_char *map, char **tetri, int ind)
{
	char		offset;

	offset = 0;
	while (offset < SIDE * SIDE)
	{
		if (put_tetri(map, tetri, ind, &offset))
		{
//			printf("tetri n%d offset %d\n", ind, offset );
//			print_map(map, tetri[0][0]);
			if (tetri[ind + 1] == NULL)
				return (1);
			if (resolve(map, tetri, ind + 1))
				return (1);
			destroy_tetri(map, tetri, ind, offset);
		}
		offset++;	
	}
	return (0);
}
