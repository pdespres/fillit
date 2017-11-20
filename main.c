/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:55:54 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/20 15:33:32 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	Rules:																	*/
/*	l'ensemble des tetri est un tab de chaine[4] avec indice = ordre		*/
/*	le tab[0] est reserve pour des infos de map								*/
/*	un tetri est une chaine[4] avec les 4 pos des blocs max 255				*/
/*	map: carre de cote X sous forme de chaine de longueur X*X				*/

int			main(int ac, char **av)
{
	char	**tetri;
	t_char	*map;
	int		i = 0;
	char	*str;

	map = NULL;
	str = NULL;
	if (ac != 2)
	{
		write(2, "usage: ./fillit input_file\n", 27);
		return (0);
	}
	tetri = open_file(av[1], str);
	free(str);
	while(tetri[i])
	{
		printf("Tetri %d  %d %d %d %d\n", i, tetri[i][1], tetri[i][2], tetri[i][3], tetri[i][4]);
		i++;
	}

	tetri[0][0] = sizemini(tetri);
	while (1)
	{
		free(map);
		map = create_map(tetri[0][0]);
		printf("map de taille %d\n", tetri[0][0]);
		if (resolve(map, tetri, 1))
			break ;
		tetri[0][0]++;
	}
	print_map(map, tetri[0][0]);
	return (0);
}
