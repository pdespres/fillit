/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:59:02 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/13 09:43:10 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (c < 0 || c > 255)
		return (NULL);
	while (1 == 1)
	{
		if (s[i] == c)
			return ((char*)s + i);
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (NULL);
}
