/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:46:39 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/13 10:30:24 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*copie;

	size = ft_strlen(str);
	copie = (char*)malloc((size + 1) * sizeof(char));
	if (copie == NULL)
		return (NULL);
	return (ft_strcpy(copie, str));
}
