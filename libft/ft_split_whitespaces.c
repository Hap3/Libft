/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 17:00:11 by cpaquet           #+#    #+#             */
/*   Updated: 2018/03/20 15:01:39 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char		ft_strlen_words(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\t' && str[i] != '\n' && str[i] != ' ' && str[i] != '\0')
		i++;
	return (i);
}

static int		ft_words(char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != '\n') && (str[i] != '\t') && (str[i] != ' ')
		&& (str[i] != '\0'))
		{
			while ((str[i] != '\n') && (str[i] != '\t')
			&& (str[i] != ' ') && (str[i] != '\0'))
				i++;
			c++;
		}
		else
			i++;
	}
	return (c);
}

char			**ft_split_whitespaces(char *str)
{
	char	**result;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(result = (char **)malloc(sizeof(char *) * (ft_words(str) + 1))))
		return (NULL);
	while (str[i] != '\0' || j < ft_words(str))
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			while ((str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			&& str[i] != '\0')
				i++;
		if (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && str[i] != '\0')
		{
			if (!(result[j] = ft_strnew(ft_strlen_words(str + i))))
				return (NULL);
			ft_strncpy(result[j], &str[i], ft_strlen_words(&str[i]));
			j++;
			i = i + ft_strlen_words(str + i);
		}
	}
	result[j] = 0;
	return (result);
}
