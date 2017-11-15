/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:23:06 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/13 12:24:39 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *str, char sep)
{
	int		words;
	int		i;
	int		bnext;

	words = 0;
	i = 0;
	bnext = 1;
	while (str[i])
	{
		if (!(str[i] == sep))
		{
			if (bnext)
			{
				bnext = 0;
				words++;
			}
		}
		else
			bnext = 1;
		i++;
	}
	return (words);
}
