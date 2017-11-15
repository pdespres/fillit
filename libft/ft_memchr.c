/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:35:20 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/13 09:32:51 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	size_t			i;
	unsigned char	*cs;

	if (n == 0)
		return (NULL);
	uc = (unsigned char)c;
	cs = (unsigned char*)s;
	i = 0;
	while (i <= n - 1)
	{
		if (cs[i] == uc)
			return (cs + i);
		i++;
	}
	return (NULL);
}
