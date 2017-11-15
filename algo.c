/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:18:51 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/15 21:42:14 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		pose_tetri(char **map, int x, int y, t_list *tetri)
{

	return (1);
}

int		resolve(char **map, t_list *tetri, int maxsize)
{
	char 	x;
	char 	y;
	t_list	*temp;

	x = 0;
	y = 0;
	temp = tetri;
	if (pose_tetri(map, x, y, temp))
	{
		temp = temp->next;
		resolve(map, temp, maxsize);
	}

}
