/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:33:50 by cpaquet           #+#    #+#             */
/*   Updated: 2017/11/17 18:19:39 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *to_find)
{
	size_t	i;
	size_t	j;
	char	*csrc;

	i = 0;
	j = 0;
	csrc = (char *)src;
	if (to_find[j] == 0)
		return (csrc);
	while (src[i] != '\0' && to_find != '\0')
	{
		while (src[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&csrc[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
