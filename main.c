/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:55:54 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/15 15:08:03 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	t_tetri		*tetri;

	if (ac != 2)
	{
		ft_putstr_fd("usage: ./fillit input_file\n", 2);
		return (0);
	}
	tetri = open_file(av[1]);
	return (0);
}
