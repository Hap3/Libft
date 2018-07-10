/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:02:02 by cpaquet           #+#    #+#             */
/*   Updated: 2017/11/22 18:31:41 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*csrc;
	unsigned char	*cdst;
	unsigned char	cs;

	i = 0;
	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	cs = (unsigned char)c;
	while (i < n)
	{
		cdst[i] = csrc[i];
		if (csrc[i] == cs)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
