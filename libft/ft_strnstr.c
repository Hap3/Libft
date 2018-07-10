/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:01:23 by cpaquet           #+#    #+#             */
/*   Updated: 2017/11/21 10:58:37 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*csrc;

	i = 0;
	j = 0;
	csrc = (char *)src;
	if (len == 0)
		return (NULL);
	if (to_find[j] == 0 && csrc[i] != 0)
		return (csrc);
	while (src[i] != '\0' && to_find != '\0' && i < len)
	{
		while (src[i + j] == to_find[j] && i + j < len)
		{
			if (to_find[j + 1] == '\0')
				return (&csrc[i]);
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}
