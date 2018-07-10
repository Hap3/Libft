/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:57:05 by cpaquet           #+#    #+#             */
/*   Updated: 2018/01/31 14:53:50 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_precision_nbr(t_param *param)
{
	int		i;
	int		j;

	i = PRECISION;
	j = 0;
	(i < LEN ? i = LEN : i);
	while (i > LEN)
	{
		ft_buffer('0', param);
		i--;
	}
	while (i)
	{
		ft_buffer(ARG_STR[j++], param);
		i--;
	}
}

void		ft_precision_str(t_param *param, char *arg)
{
	int		i;
	int		j;

	i = 0;
	if (PRECISION < LEN && PRE_ON && PRECISION >= 0)
		j = PRECISION;
	else
		j = LEN;
	while (i < j)
		ft_buffer(arg[i++], param);
}
