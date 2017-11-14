/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:33:44 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/14 22:32:33 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_file(char *str)
{
	int		i;
	int		bump;
	int		nfull;

	i = 0;
	bump = 0;
	nfull = 0;
	while (str[i])
	{
		bump = (i + 1 ) / 21;
		if ((i + 1 + bump) % 5 == 1)
			if (str[i] != '\n')
				return (0);
		else if ((i + 1 + bump) % 21 == 0)
			if (str[i] != '\n' || nfull != 4)
				return (0);
			else
				nfull = 0;
		else
			if (str[i] != EMPTY && str[i] != FULL)
				return (0);
		nfull += (str[i] == FULL ? 1 : 0);
		i++;
	}
}

int		open_file(char *file)
{
	int		fd;
	char	*str;

	if (file == NULL)
		return (0);
	fd = open(*file, O_RDONLY);
	if (fd < 0)
		return (0);
	str = ft_read(fd);
	if (str == NULL)
		return (0);
	if (!check_file(str))
		return (0);
	return (1);
}
