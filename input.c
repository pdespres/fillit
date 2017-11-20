/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:33:44 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/20 10:09:49 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**check_tetri(char *str)
{
	int 	i;
	int		j;
	char	**str_places;
	int		piece_number;
	int		first_place;
	int		refresh;
	int		x;

	x = 0;
	i = 0;
	j = 1;
	while(str[i])
		i++;
	piece_number = i / 20;
	i = 0;
	if(!(str_places = (char**)malloc(sizeof(*str_places) * (piece_number + 2))))
		return (NULL);
	while (piece_number + 2 != i)
	{
		if(!(str_places[i] = (char*)malloc(sizeof(**str_places) * 5)))
			return (NULL);
		i++;
	}
	str_places[i - 1] = 0;
	i = 1;
	refresh = 0;
	while(str[x])
	{
		if (x > (((piece_number) * 21) - 20))
			break ;
		while (str[x] != '#')
		{
			x++;
			refresh++;
		}
		if (refresh < 5)
		{
			str_places[i][j] = refresh;
			first_place = 0;
		}
		else if(refresh >= 5 && refresh <= 8)
		{
			first_place = -5;
			str_places[i][j] = refresh - first_place;
		}
		else if (refresh >= 10 && refresh <= 13)
		{
			first_place = -10;
			str_places[i][j] = refresh - first_place;
		}
		else if (refresh >= 15 && refresh <= 18)
		{
			first_place = -15;
			str_places[i][j] = refresh - first_place;
			
		}
		j++;
		while(refresh != 20 && str[x])
		{
			x++;
			refresh++;
			if (str[x] == '#')
			{
				str_places[i][j] = refresh - first_place;
				j++;
			}
		}
		x++;
		i++;
		j = 1;
		refresh = 0;
	}
	return (str_places);
}
