/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:01:46 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/13 10:28:13 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char const *s1, char const *s2)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	c1 = s1[i];
	c2 = s2[i];
	while (c1 != '\0' && c2 != '\0' && c1 == c2)
	{
		i++;
		c1 = s1[i];
		c2 = s2[i];
	}
	return (c1 - c2);
}
