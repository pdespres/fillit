/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:56:53 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/13 12:22:43 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_howmanywords(char const *str, char sep)
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

static int	ft_create_lines(char const *str, char **tab, char sep)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && !(str[i] == sep))
		{
			i++;
			j++;
		}
		if (j > 0)
		{
			tab[k] = (char*)malloc(sizeof(**tab) * (j + 1));
			if (tab[k] == NULL)
				return (0);
			k++;
			i--;
		}
		i++;
	}
	return (1);
}

static int	ft_fill_array(char const *str, char **tab, char sep)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (str[i])
	{
		k = 0;
		if (!(str[i] == sep))
		{
			while (str[i] && !(str[i] == sep))
			{
				tab[j][k] = str[i];
				i++;
				k++;
			}
			tab[j][k] = '\0';
			j++;
			i--;
		}
		i++;
	}
	return (1);
}

char		**ft_strsplit(char const *str, char c)
{
	int		size;
	char	**tab;

	if (str == NULL)
		return (NULL);
	size = ft_howmanywords(str, c);
	tab = (char**)malloc(sizeof(*tab) * (size + 1));
	if (tab == NULL)
	{
		return (NULL);
	}
	tab[size] = 0;
	if (ft_create_lines(str, tab, c) == 0)
		return (NULL);
	ft_fill_array(str, tab, c);
	return (tab);
}
