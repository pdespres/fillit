/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:46:18 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/13 09:23:15 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overlap(void *dst, const void *src, size_t len)
{
	if (dst + len >= src && dst <= src)
		return (1);
	else if (src + len >= dst && src <= dst)
		return (2);
	else
		return (0);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		j;
	char	*cdst;
	char	*csrc;

	if (len == 0)
		return (dst);
	j = ft_overlap(dst, src, len);
	if (j == 0 || j == 1)
		ft_memcpy(dst, src, len);
	else if (j == 2)
	{
		cdst = (char*)dst;
		csrc = (char*)src;
		i = len - 1;
		while (1 == 1)
		{
			cdst[i] = csrc[i];
			if (i == 0)
				break ;
			i--;
		}
	}
	return (dst);
}
