/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:55:54 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/16 09:53:47 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	t_list		*tetri;
	int			cote_carre;
	char		**map;

	map = NULL;
	if (ac != 2)
	{
		ft_putstr_fd("usage: ./fillit input_file\n", 2);
		return (0);
	}
	tetri = open_file(av[1]);
	cotecarre = sizemini(tetri);
	while (1)
	{
		ft_freetabmem(map);
		map = create_map(cotecarre);
		if (resolve(map, tetri, cotecarre))
			break ;
		cotecarre += 2;
	}
	print_map(map);
	return (0);
}
