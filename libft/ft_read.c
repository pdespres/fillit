/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:27:16 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/15 18:29:35 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd)
{
	size_t	ret;
	size_t	buf_size;
	char	*buf;
	char	*str;
	char	*tmp;

	buf_size = BUF_SZ;
	if (!(str = (char*)malloc(1)))
		return (NULL);
	if (!(buf = (char*)malloc(sizeof(*buf) * (buf_size + 1))))
		return (NULL);
	str[0] = '\0';
	while ((ret = read(fd, buf, buf_size)))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(str, buf);
		free(buf);
		free(str);
		str = tmp;
		if (buf_size != BUF_MX && ret == buf_size)
			buf_size = ((buf_size * 2) <= BUF_MX ? (buf_size * 2) : BUF_MX);
		if (!(buf = (char*)malloc(sizeof(*buf) * (buf_size + 1))))
			return (NULL);
	}
	return (str);
}
