/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:07:47 by cpaquet           #+#    #+#             */
/*   Updated: 2017/11/23 15:52:34 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen((char *)s) - 1;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i++;
	while (j >= i && (s[j] == '\n' || s[j] == '\t' || s[j] == ' '))
		j--;
	if (!(str = ft_strsub(s, i, j - i + 1)))
		return (NULL);
	return (str);
}
