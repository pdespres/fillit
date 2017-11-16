/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:33:44 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/16 17:39:15 by ncohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tetri(char *str)
{
	int 	i;
	char	hauteur;
	char	longueur;
	int		save;
	int		dont_back;
	t_tetri *tetri;
	int		piece_num;

	piece_num = 0;
	i = 0;
	dont_back = -1;
	while (str[i] != '\0')
	{
		longueur = 1;
		hauteur = 1;
		while (str[i] != '#')
			i++;
		tetri = ft_new_tetri(tetri);
		while (hauteur + longueur != 5)
		{
			if (str[i + 1] == '#' || str[i + 5] == '#' || str[i - 1] == '#')
			{
				if ((str[i + 1] == '#' && i + 1 != dont_back) || 
						(str[i - 1] == '#' && i - 1 != dont_back))
					longueur++;
					if (str[i + 1] == '#')
						tetri->pos[longueur + hauteur - 2][0] = 1;
						dont_back = i;
						i += i + 1;
					else if (str[i - 1] == '#')
						tetri->pos[longueur + hauteur - 2][0] = -1;
						dont_back = i;
						i += i - 1;
				else if (str[i + 5] == '#')
					hauteur++;
					tetri->pos[longueur + hauteur - 2][1] = 1;
					i += 5;
				else if	(str[i - 1] && i - 1 == dont_back)
					if (str[i - 2] == '#')
						tetri->pos[longueur + hauteur - 2][0] = -1;
			}
			else if (str[i + 4] == '#')
				hauteur++;
				tetri->pos[longueur + hauteur - 2][1] = 1;
				i += 4;
			else
				error("pas une bonne forme");
		}
		tetri->lmax = longueur;
		tetri->hmax = hauteur;
		tetri->num = piece_num;
		while(str[i - 1] != '\n' && str[i - 2] != '\n')
			i++;
	}
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
