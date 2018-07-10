/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:29:01 by cpaquet           #+#    #+#             */
/*   Updated: 2017/11/24 12:04:23 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*cs;
	char	cc;

	i = 0;
	cs = (char *)s;
	cc = (char)c;
	while (i < n)
	{
		if (cs[i] == cc)
			return (&cs[i]);
		i++;
	}
	return (NULL);
}
