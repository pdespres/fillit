/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:01:27 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/20 17:14:11 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_char	*create_map(char size)
{
	t_char	*map;

	map = (t_char*)malloc(sizeof(*map) * (size * size + 1));
	ft_error(map == NULL);
	map[(int)size] = '\0';
	ft_memset(map, EMPTY, size * size);
	return (map);
}

void	print_map(t_char *map, char size)
{
	int		i;

	i = 0;
	while (i < size * size)
	{
		write(1, map + i, size);
		i += size;
		if (i < size * size)
			write(1, &"\n", 1);
	}
	write(1, &"\n", 1);
}
