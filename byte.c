/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:06:15 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/15 15:08:51 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* pos vont de 0 a 7 sur un byte */

t_byte	read_bit(t_byte pos, t_byte *map)
{
	return ((map[pos / 8] & (1 << (pos & 7))) ? 1 : 0);
}

void	mod_bit(t_byte pos, t_byte *map)
{
	if (pos)
		map[pos / 8] |= 1 << (pos & 7);
	else
		map[pos / 8] &= ~(1 << (pos & 7));
}
