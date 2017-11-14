/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:01:27 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/14 20:57:57 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

byte	*create_map(int size)
{
	byte	*map;
	int		nbr;

	nbr = (size + 7) / 8;
	nbr *= nbr;
	map = (byte*)malloc(sizeof(*map) * nbr);
	if (map == NULL)
		return (NULL);
}
