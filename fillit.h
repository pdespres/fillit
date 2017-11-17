/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:50:03 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/17 17:38:59 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>

# define EMPTY '.'
# define FULL '#'
# define SIDE tetri[0][0]

typdef unsigned char	t_char;

int			resolve(t_char *map, char **tetri, int ind);
char		*create_map(char size);
void		print_map(t_char *map, char size);
char		sizemini(char **tetri);
char		**open_file(char *file);

#endif
