/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 22:37:47 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/13 12:31:25 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_test_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != '\0')
	{
		if (!(base[i] >= 32))
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 1;
		while (base[i + j] != '\0')
		{
			if (base[i + j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

static int		ft_is_number(char c, char *base, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

static int		ft_convert_from(char *nbr, char *base_from, int size)
{
	long	inbr;
	int		i;
	int		isigne;
	int		ichiffre;

	i = 0;
	isigne = 1;
	inbr = 0;
	while (nbr[i])
	{
		if (i == 0 && (nbr[i] == '+' || nbr[i] == '-'))
		{
			isigne = (nbr[i] == '-') ? -1 : 1;
		}
		else
		{
			ichiffre = ft_is_number(nbr[i], base_from, size);
			if (ichiffre < 0)
				return (-1);
			inbr = (inbr * size) + ichiffre;
		}
		i++;
	}
	return (inbr * isigne);
}

static long		ft_convert_to(int nbr, int size, char *base, char *temp)
{
	long	div;
	int		length;
	int		neg;

	div = nbr;
	length = 0;
	neg = 0;
	if (div < 0)
	{
		div *= -1;
		neg = 1;
	}
	while (div >= size)
	{
		temp[length] = base[div % size];
		div = div / size;
		length++;
	}
	temp[length] = base[div];
	if (neg)
		temp[length + 1] = '-';
	return (length + neg);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		size;
	int		nbr_decimal;
	long	size_str;
	char	*tab;
	char	*temp;

	size = ft_test_base(base_from);
	if (size == 0)
		return (NULL);
	nbr_decimal = ft_convert_from(nbr, base_from, size);
	temp = (char*)malloc(sizeof(char) * 50);
	size = ft_test_base(base_to);
	size_str = ft_convert_to(nbr_decimal, size, base_to, temp);
	tab = (char*)malloc(sizeof(char) * size_str + 2);
	if (tab == NULL)
		return (NULL);
	size = 0;
	while (size_str >= 0)
	{
		tab[size] = temp[size_str];
		size++;
		size_str--;
	}
	tab[size] = '\0';
	return (tab);
}
