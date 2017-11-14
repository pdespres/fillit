/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:06:15 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/14 16:14:38 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* pos vont de 0 a 7 sur un byte */

byte	read_bit(byte pos, byte *map)
{
	return ((map[pos / 8] & (1 << (pos & 7))) ? 1 : 0);
}

void	mod_bit(byte pos, byte *map)
{
	if (pos)
		map[pos / 8] |= 1 << (pos & 7);
	else
		map[pos / 8] &= ~(1 << (pos & 7));
}
