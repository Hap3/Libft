/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:08:41 by cpaquet           #+#    #+#             */
/*   Updated: 2017/11/24 17:45:00 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *suiv;

	if (!(suiv = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (content == 0)
	{
		suiv->content = 0;
		suiv->content_size = 0;
	}
	else
	{
		if (!(suiv->content = (void*)malloc(sizeof(*content) * content_size)))
			return (0);
		ft_memcpy(suiv->content, (void *)content, content_size);
		suiv->content_size = content_size;
	}
	suiv->next = 0;
	return (suiv);
}
