/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:50:03 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/16 11:08:23 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>

# define EMPTY '.'
# define FULL '#'

// p[4][2]: p[0] est pour algo.c (pos actuelle) | p[?][0] = x | p[?][1] = y
typedef struct			s_list
{
	char				num;
	int					p[4][2];
	int					lmax;
	int					hmax;
	struct s_list		*next;
}						t_list;

#endif
