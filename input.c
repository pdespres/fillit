/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:33:44 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/20 16:06:42 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_alloc(char *str_base, int *piece_number)
{
	int i;
	char **str;

	i = 0;
	while(str_base[i])
		i++;
	*piece_number = i / 20;
	i = 0;
	if(!(str = (char**)malloc(sizeof(*str) * (*piece_number + 2))))
		return (0);
	while (*piece_number + 2 != i)
		if(!(str[i++] = (char*)malloc(sizeof(**str) * 5)))
			return (0);
	str[i - 1] = 0;
	return (str);
}

void		ft_refresh(int *refresh, int *first_place)
{
	if (*refresh < 5)
		*first_place = 0;
	else if(*refresh >= 5 && *refresh <= 9)
		*first_place = 5;
	else if (*refresh >= 10 && *refresh <= 14)
		*first_place = 10;
	else if (*refresh >= 15 && *refresh <= 19)
		*first_place = 15;
}

void	ft_init(int *j, int *refresh)
{
	*j = 1;
	*refresh = 0;
}

void	ft_find_hash(char *str, int *x, int *refresh)
{
	while (str[*x] != '#')
	{
		*x += 1;
		*refresh += 1;
	}
}
char	**check_tetri(char *str)
{
	int 	i;
	int		j;
	char	**str_places;
	int		piece_number;
	int		first_place;
	int		refresh;
	int		x;

	x = -1;
	i = 1;
	str_places = ft_alloc(str, &piece_number);
	while(str[++x])
	{
		ft_init(&j, &refresh);
		if (x > (((piece_number) * 21) - 20))
			break ;
		ft_find_hash(str, &x, &refresh);
		ft_refresh(&refresh, &first_place);
		str_places[i][j] = refresh - first_place;
		j++;
		while(refresh++ != 20 && str[x++])
			if (str[x] == '#')
				str_places[i][j++] = refresh - first_place;
		i++;
	}
	return (str_places);
}
