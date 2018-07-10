/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cC.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:17:44 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/06 18:30:29 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_width_char(t_param *param)
{
	int		i;
	char	c;

	i = 0;
	if (WIDTH <= LEN)
		return ;
	if (FLAGS & ZERO)
		c = '0';
	else
		c = ' ';
	while (i < WIDTH - LEN)
	{
		ft_buffer(c, param);
		i++;
	}
}

int			ptr_char(va_list ap, t_param *param)
{
	int		arg;

	LEN = 1;
	if (SIZES & L)
		return (ptr_c_uni(ap, param));
	arg = va_arg(ap, int);
	if (!(FLAGS & MINUS))
		ft_width_char(param);
	ft_buffer(arg, param);
	if (FLAGS & MINUS)
		ft_width_char(param);
	return (1);
}
