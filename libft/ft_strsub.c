/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:53:38 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/20 12:11:09 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*cs;

	cs = (char *)s;
	if (s == NULL)
		return (NULL);
	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_strncpy(str, &cs[start], len);
	str[len] = '\0';
	return (str);
}
