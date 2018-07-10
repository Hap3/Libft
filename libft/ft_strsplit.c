/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:27:26 by cpaquet           #+#    #+#             */
/*   Updated: 2018/04/25 09:19:19 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrwords(char const *s, char c)
{
	size_t m;
	size_t n;

	m = 0;
	n = 0;
	while (s[m] != '\0')
	{
		while (s[m] == c)
			m++;
		if (s[m] != '\0')
		{
			while (s[m] != c && s[m] != '\0')
				m++;
			n++;
		}
	}
	return (n);
}

static int		ft_lenword(char const *s, char c)
{
	size_t k;

	k = 0;
	while (s[k] != c && s[k] != '\0')
		k++;
	return (k);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_nbrwords(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			if (!(str[j] = ft_strnew((ft_lenword(s + i, c)))))
				return (NULL);
			ft_strncpy(str[j], s + i, ft_lenword(s + i, c));
			j++;
			i = i + ft_lenword(s + i, c);
		}
	}
	str[j] = 0;
	return (str);
}
