/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:32:10 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/17 19:11:04 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		bump = (i + 1) / 21;
		if ((i + 1 + bump) % 5 == 1)
			ft_error((str[i] != '\n' && str[i] != '\0'));
		else if ((i + 1 + bump) % 21 == 0)
		{
			ft_error((str[i] != '\n' || nfull != 4));
			nfull = 0;
		}
		else
			ft_error((str[i] != EMPTY && str[i] != FULL));
		nfull += (str[i] == FULL ? 1 : 0);
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (!(i > 0 && str[i - 1] == '\n'));
}

char	**open_file(char *file)
{
	int		fd;
	char	*str;

	ft_error((file == NULL));
	fd = open(file, O_RDONLY);
	ft_error((fd < 0));
	str = read_file(fd);
	ft_error((str == NULL));
	ft_error(close(fd) == -1);
	ft_error((check_file(str) == 0));
	return (check_tetri(str));
}
