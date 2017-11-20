/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:33:44 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/20 09:33:24 by pdespres         ###   ########.fr       */
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
/*
int		check_file(char *str)
{
	int		i;
	int		bump;
	int		nfull;

	i = 0;
	bump = 0;
	nfull = 0;
	while (1)
	{
		bump = (i + 1) / 21;
		if ((i + 1 + bump) % 5 == 1)
			error((str[i] != '\n' && str[i] != '\0'));
		else if ((i + 1 + bump) % 21 == 0)
		{
			error((str[i] != '\n' || nfull != 4));
			nfull = 0;
		}
		else
			error((str[i] != EMPTY && str[i] != FULL));
		nfull += (str[i] == FULL ? 1 : 0);
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (!(i > 0 && str[i - 1] == '\n'));
}

t_tetri	*open_file(char *file)
{
	int		fd;
	char	*str;

	error((file == NULL));
	fd = open(*file, O_RDONLY);
	error((fd < 0));
	str = ft_read(fd);
	error((str == NULL));
	error((check_file(str) == 0));
	return (check_tetri(str));
}*/
