/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:32:10 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/20 16:03:57 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**check_tetri(char **str)
{
	int 	i;
	char	**str_places;
	int		decalage;
	int		x;

	i = 0;
	while(str[0][i])
	{
		i++;
	}
	printf("max i %d\n", i);
	x = i / 20 - (i / 20) / 20;
	if(!(str_places = (char**)malloc(sizeof(*str_places) * (x + 2))))
		return (NULL);
	str_places[x + 1] = 0;
	i = 0;
	while (i <= x)
	{
		if(!(str_places[i] = (char*)malloc(sizeof(**str_places) * 5)))
			return (NULL);
		i++;
	}
	i = 0;
	x = 1;
	decalage = 0;
	printf("la str existe tjrs?\n%s\n", *str)
	while(str[0][i])
	{
		if (i % 21 == 0)
		{
			x = 1;
			decalage = 0;
		}
		if (str[0][i] == FULL)
		{
			if (x == 1)
				decalage = (i - (i / 21) * 21) / 5 * 5 + (i / 21 * 21);
	//		printf("[%d][%d] = %d - %d = %d\n", i/21+1,x,i,decalage,i-decalage);
			str_places[i / 21 + 1][x] = i - decalage;
			x++;
		}
		i++;
	}
	return (str_places);
}

static char	*read_file(int fd)
{
	size_t	ret;
	size_t	buf_size;
	char	*buf;
	char	*str;
	char	*tmp;

	buf_size = 1023;
	if (!(str = (char*)malloc(1)))
		return (NULL);
	if (!(buf = (char*)malloc(sizeof(*buf) * (buf_size + 1))))
		return (NULL);
	str[0] = '\0';
	while ((ret = read(fd, buf, buf_size)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(str, buf);
		free(buf);
		free(str);
		str = tmp;
		free(tmp);
		if (!(buf = (char*)malloc(sizeof(*buf) * (buf_size + 1))))
			return (NULL);
	}
	free(buf);
	return (str);
}

static int	check_file(char *str)
{
	int		i;
	int		bump;
	int		nfull;

	i = 0;
	bump = 0;
	nfull = 0;
	while (1)
	{
		if ((i + 1 - bump) % 5 == 0)
		{
			ft_error((str[i] != '\n' && str[i] != '\0'));
		}
		else if ((i + 1) % 21 == 0)
		{
			ft_error((str[i] != '\n' || nfull != 4));
			nfull = 0;
		}
		else
		{
			ft_error((str[i] != EMPTY && str[i] != FULL));
		}
		bump = (i + 1) / 21;
		nfull += (str[i] == FULL ? 1 : 0);
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (!(i > 0 && str[i - 1] == '\n'));
}

char	**open_file(char *file, char *str)
{
	int		fd;
//	char	*str;
	char	**tetri;

	ft_error((file == NULL));
	fd = open(file, O_RDONLY);
	ft_error((fd < 0));
	str = read_file(fd);
	ft_error((str == NULL));
	ft_error(close(fd) == -1);
	ft_error((check_file(str) == 0));
	printf("%s\n", str);
	tetri = check_tetri(&str);
	ft_error(tetri == NULL);
	return(tetri);
}
