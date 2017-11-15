/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:01:27 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/15 21:23:54 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(int size)
{
	char	**map;
	int		i;

	map = (char**)malloc(sizeof(*map) * (size + 1));
	error(map == NULL);
	map[size] = 0;
	i = 0;
	while(i++ < size)
	{
		map[i] = ft_strnew(size);
		error(map[i] == NULL);
	}
	return (map);
}

void	print_map(char **map)
{
	int		i;

	while(map[i] != 0)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}
