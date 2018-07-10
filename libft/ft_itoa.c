/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:10:43 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/20 12:14:42 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nb)
{
	size_t i;

	i = 1;
	while (nb > 9)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

static char	*ft_null(void)
{
	char *str;

	str = ft_strnew(1);
	str[0] = '0';
	return (str);
}

static char	*ft_pos(int n)
{
	char	*str;
	size_t	i;

	i = ft_len(n);
	str = ft_strnew(i);
	while (i)
	{
		--i;
		str[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

static char	*ft_nega(int n)
{
	char	*str;
	size_t	i;

	n = -n;
	i = ft_len(n) + 1;
	str = ft_strnew(i);
	while (i)
	{
		--i;
		str[i] = (n % 10) + '0';
		n = n / 10;
	}
	str[0] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	char *str;

	str = NULL;
	if (n == 0)
		str = ft_null();
	if (n > 0)
		str = ft_pos(n);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			str = ft_strjoin(ft_nega(-214748364), "8");
			return (str);
		}
		str = ft_nega(n);
	}
	return (str);
}
