/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:30:57 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/20 12:14:53 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t					i;
	size_t					j;
	unsigned long long		nb;
	int						neg;

	i = 0;
	j = 0;
	nb = 0;
	neg = 0;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = (nb * 10) + (str[i++] - '0');
		j++;
	}
	if (neg == -1 && (nb > 9223372036854775808UL || j > 19))
		return (0);
	if (neg != -1 && (nb > 9223372036854775807UL || j > 19))
		return (-1);
	return (neg != -1 ? nb : -nb);
}
