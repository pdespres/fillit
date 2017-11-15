/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:50:03 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/15 21:23:01 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>

# define EMPTY '.'
# define FULL '#'

typedef struct			s_list
{
	char				num;
	char				p1[2];
	char				p2[2];
	char				p3[2];
	char				lmax;
	char				hmax;
	struct s_list		*next;
}						t_list;

#endif
