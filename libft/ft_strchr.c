/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:59:45 by cpaquet           #+#    #+#             */
/*   Updated: 2017/11/17 18:21:20 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (c == '\0')
		return (&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] - c == 0)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
