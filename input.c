/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:33:44 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/16 11:12:22 by ncohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tetri(char *str)
{
	int 	i;
	char	hauteur;
	char	longueur;
	int		save;
	t_tetri *tetri;

	i = 0;
	hauteur = 1;
	longueur = 1;
	while (str[i] != '#')
		i++;
	save = i;
	while (str[i] != '\0')
	{
		while (str[i] != '\n' && str[i + 1] != '\n')
		{
			if (hauteur + longueur != 4)
			{
				if (str[i + 1] == '#' || str[i + 5] == '#' || str[i - 1] == '#')
				{
					if (str[i + 1] == '#' || str[i - 1] == '#')
						longueur++;
						if (str[i + 1] == '#')
							tetri->pos[longueur + hauteur - 1][1] = 1;
						if (str[i - 1] == '#')
							tetri->pos[longueur + hauteur - 1][1] = -1;
					else
						hauteur++;
						tetro->pos[longueur + hauteur - 1][0] = 1;
				}
				else
					error("pas une bonne forme");
				i += 5;
			}
			else
				ft_fill_tetri();
				i = (22 - save)
		}
	}
	return (tetritest);
}

int		check_file(char *str)
{
	int		i;
	int		bump;
	int		nfull;

	i = 0;
	bump = 0;
	nfull = 0;
	while (1)
	{
		bump = (i + 1) / 21;
		if ((i + 1 + bump) % 5 == 1)
			error((str[i] != '\n' && str[i] != '\0'));
		else if ((i + 1 + bump) % 21 == 0)
		{
			error((str[i] != '\n' || nfull != 4));
			nfull = 0;
		}
		else
			error((str[i] != EMPTY && str[i] != FULL));
		nfull += (str[i] == FULL ? 1 : 0);
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (!(i > 0 && str[i - 1] == '\n'));
}

t_tetri	*open_file(char *file)
{
	int		fd;
	char	*str;

	error((file == NULL));
	fd = open(*file, O_RDONLY);
	error((fd < 0));
	str = ft_read(fd);
	error((str == NULL));
	error((check_file(str) == 0));
	return (check_tetri(str));
}
