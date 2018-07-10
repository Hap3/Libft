/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uU.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:08:53 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/06 10:57:32 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width_unsigned(t_param *param)
{
	int		tmp;
	char	c;
	int		i;

	tmp = LEN;
	i = 0;
	if (WIDTH <= LEN || WIDTH <= PRECISION)
		return ;
	(PRECISION > LEN ? tmp = PRECISION : tmp);
	if (FLAGS & ZERO)
		c = '0';
	else
		c = ' ';
	while (i < WIDTH - tmp)
	{
		ft_buffer(c, param);
		i++;
	}
}

int				ptr_unsigned(va_list ap, t_param *param)
{
	char				*base;
	unsigned long long	arg;

	base = "0123456789";
	if ((TYPE & D || TYPE & U) && (SIZES ^ LL))
		SIZES = SIZES | L;
	arg = (unsigned long long)ft_cast_unbr(ap, param);
	ARG_STR = ft_itoa_base_char(arg, base);
	LEN = ft_strlen(ARG_STR);
	(!(FLAGS & MINUS) ? ft_width_unsigned(param) : 0);
	if (!((PRECISION == 0) && arg == 0 && PRE_ON == 1))
		ft_precision_nbr(param);
	(FLAGS & MINUS ? ft_width_unsigned(param) : 0);
	(arg != 0 && ARG_STR != NULL ? ft_strdel(&ARG_STR) : 0);
	return (1);
}
