/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:50:03 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/15 15:16:04 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>

# define EMPTY '.'
# define FULL '#'

typedef unsigned char	t_byte;
typedef struct			s_tetri
{
	char				num;
	char				lettre;
	char				type;
	char				p1[2];
	char				p2[2];
	char				p3[2];
	char				lmax;
	char				hmax;
	truct s_tetri		*next;
}						t_tetri;

#endif
