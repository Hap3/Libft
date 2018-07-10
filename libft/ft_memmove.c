/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:47:19 by cpaquet           #+#    #+#             */
/*   Updated: 2017/11/23 14:38:15 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*csrc;
	char		*cdst;
	size_t		i;

	csrc = src;
	cdst = dst;
	i = 0;
	if (src < dst)
	{
		while (len--)
			cdst[len] = csrc[len];
	}
	else
	{
		while (len--)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	return (cdst);
}
