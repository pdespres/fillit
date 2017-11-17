/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:01:27 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/17 16:19:22 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*create_map(char size)
{
	t_char	*map;

	map = (t_char*)malloc(sizeof(*map) * (size * size + 1));
	error(map == NULL);
	map[size] = '\0';
	ft_memset(map, EMPTY, size);
	return (map);
}

void	print_map(t_char *map, char size)
{
	int		i;

	i = 0;
	while(i < size * size)
	{
		write(1, map + i, size);
		i += size;
		if (i < size * size))
			ft_putchar('\n');
	}
}
