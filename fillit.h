/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:50:03 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/19 14:26:48 by ncohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define EMPTY '.'
# define FULL '#'
# define SIDE tetri[0][0]

typedef unsigned char	t_char;

int			resolve(t_char *map, char **tetri, int ind);
t_char		*create_map(char size);
void		print_map(t_char *map, char size);
char		sizemini(char **tetri);
char		**open_file(char *file);
void		ft_error(int i);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcat(char *s1, const char *s2);
size_t		ft_strlen(const char *str);
int		**check_tetri(char *str);

#endif
