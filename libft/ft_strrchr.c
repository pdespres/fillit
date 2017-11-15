/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:46:25 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/13 09:44:06 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (c < 0 || c > 255)
		return (NULL);
	i = ft_strlen(s);
	while (1 == 1)
	{
		if (s[i] == c)
			return ((char*)s + i);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
