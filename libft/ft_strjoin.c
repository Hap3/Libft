/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:04:39 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/20 12:12:24 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	char *cs1;
	char *cs2;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(cs1) + ft_strlen(cs2))))
		return (NULL);
	ft_strcpy(str, cs1);
	ft_strcpy(&str[ft_strlen(cs1)], cs2);
	str[ft_strlen(cs1) + ft_strlen(cs2)] = '\0';
	return (str);
}
