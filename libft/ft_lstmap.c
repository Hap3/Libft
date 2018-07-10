/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:40:58 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/20 12:13:51 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lsti;

	if (!(lsti = malloc(sizeof(t_list))))
		return (NULL);
	lsti = (*f)(lst);
	if (!(lst->next))
		return (lsti);
	lsti->next = ft_lstmap(lst->next, f);
	return (lsti);
}
