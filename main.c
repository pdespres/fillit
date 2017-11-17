/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:55:54 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/17 16:17:16 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	Rules:																	*/
/*	l'ensemble des tetri est un tab de chaine[4] avec indice = ordre		*/
/*	le tab[0] est reserve pour des infos de map								*/
/*	un tetri est une chaine[4] avec les 4 pos des blocs max 255				*/
*/	map: carre de cote X sous forme de chaine de longueur X*X				*/

int			main(int ac, char **av)
{
	char	**tetri;
	t_char	*map;

	map = NULL;
	if (ac != 2)
	{
		ft_putstr_fd("usage: ./fillit input_file\n", 2);
		return (0);
	}
	tetri = open_file(av[1]);
	tetri[0][0] = sizemini(tetri);
	while (1)
	{
		free(map);
		map = create_map(tetri[0][0]);
		if (resolve(map, tetri, 0))
			break ;
		tetri[0][0]++;
	}
	print_map(map, tetri[0][0]);
	return (0);
}
