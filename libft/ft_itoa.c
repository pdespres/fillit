/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:04:42 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/13 10:24:01 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cal_rec(long int a, char *str, int *i)
{
	long int	div;
	int			mod;

	div = a / 10;
	mod = a % 10;
	if (div > 0)
		cal_rec(div, str, i);
	str[*i] = mod + '0';
	*i += 1;
}

char		*ft_itoa(int n)
{
	long int	a;
	char		*str;
	int			ind;

	str = (char*)malloc(12 * sizeof(char));
	if (str == NULL)
		return (NULL);
	a = (long int)n;
	ind = 0;
	if (a < 0)
	{
		str[0] = '-';
		ind = 1;
		a = -a;
	}
	cal_rec(a, str, &ind);
	str[ind] = '\0';
	return (ft_strdup(str));
}
