/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:11:29 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/20 11:56:40 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(unsigned long long nbr, int base_size)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr / base_size != 0 || nbr % base_size != 0)
	{
		nbr = nbr / base_size;
		++i;
	}
	return (i);
}

char		*ft_itoa_base(unsigned long long nbr, int base_size)
{
	char	*str;
	char	*base;
	int		len;
	int		tmp;

	tmp = 0;
	base = "0123456789ABCDEF";
	len = ft_count(nbr, base_size);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		EXIT_FAILURE;
	str[len--] = '\0';
	while (nbr / base_size != 0 || nbr % base_size != 0)
	{
		tmp = nbr % base_size;
		str[len--] = base[tmp];
		nbr = nbr / base_size;
	}
	return (str);
}
