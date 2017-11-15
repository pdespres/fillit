/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:44:08 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/10 12:23:59 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			size;
	unsigned int	ltrim;
	size_t			rtrim;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	ltrim = 0;
	while ((s[ltrim] == ' ' || s[ltrim] == '\n' || s[ltrim] == '\t')
			&& s[ltrim])
		ltrim++;
	rtrim = 0;
	if (ltrim < size && size > 1)
	{
		while ((s[size - rtrim - 1] == ' '
					|| s[size - rtrim - 1] == '\n'
					|| s[size - rtrim - 1] == '\t')
				&& (size - rtrim - 1) != 0)
			rtrim++;
	}
	return (ft_strsub(s, ltrim, (size - ltrim - rtrim)));
}
