/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:35:27 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/10 09:45:11 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cdst;
	unsigned char	*csrc;
	unsigned char	uc;

	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	uc = (unsigned char)c;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i <= n - 1)
	{
		cdst[i] = csrc[i];
		if (csrc[i] == uc)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
