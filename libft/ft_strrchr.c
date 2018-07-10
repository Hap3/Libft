/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:09:57 by cpaquet           #+#    #+#             */
/*   Updated: 2017/11/23 11:30:41 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*cs;

	i = 0;
	cs = (char *)s;
	i = ft_strlen(cs);
	if (s[i] - c == 0)
		return (&cs[i]);
	while (i)
	{
		if (s[i] - c == 0)
			return (&cs[i]);
		if (s[i - 1] - c == 0)
			return (&cs[i - 1]);
		i--;
	}
	return (NULL);
}
