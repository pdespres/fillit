/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:01:27 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/16 09:59:47 by pdespres         ###   ########.fr       */
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
		map[i] = (char*)malloc(size + 1);
		error(map[i] == NULL);
		map[i][size] = '\0';
		ft_memset(map[i], EMPTY, size);
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
