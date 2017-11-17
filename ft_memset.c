/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:03:25 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/17 17:52:55 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*temp;
	unsigned char	uc;

	temp = (char*)b;
	uc = (unsigned char)c;
	while (len > 0)
	{
		temp[len - 1] = uc;
		len--;
	}
	return (b);
}
