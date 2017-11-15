/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdespres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:47:26 by pdespres          #+#    #+#             */
/*   Updated: 2017/11/10 14:37:49 by pdespres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*ptr;

	new = (t_list*)malloc(sizeof(*new) * 1);
	if (new == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		ptr = malloc(content_size);
		if (ptr == NULL)
			return (NULL);
		new->content = ft_memcpy(ptr, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
