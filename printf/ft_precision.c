/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param->precision.c                                     :+:      :+:    :+:   */
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

	i = param->precision;
	j = 0;
	(i < param->len_param ? i = param->len_param : i);
	while (i > param->len_param)
	{
		ft_buffer('0', param);
		i--;
	}
	while (i)
	{
		ft_buffer(param->arg_str[j++], param);
		i--;
	}
}

void		ft_precision_str(t_param *param, char *arg)
{
	int		i;
	int		j;

	i = 0;
	if (param->precision < param->len_param && param->precision_on && param->precision >= 0)
		j = param->precision;
	else
		j = param->len_param;
	while (i < j)
		ft_buffer(arg[i++], param);
}
