/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:00:44 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/13 09:44:51 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i] != '\0' && i <= len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j + 1) <= len)
		{
			j++;
			if (to_find[j] == '\0')
			{
				return ((char*)str + i);
			}
		}
		i++;
	}
	return (NULL);
}
