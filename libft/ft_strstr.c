/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:54:29 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/13 09:45:34 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *tofind)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (tofind[0] == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == tofind[j])
		{
			j++;
			if (tofind[j] == '\0')
			{
				return ((char*)str + i);
			}
		}
		i++;
	}
	return (NULL);
}
