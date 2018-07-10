/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:56:20 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/07 12:34:44 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_end_type(t_param *param)
{
	FLAGS = FLAGS & 0;
	WIDTH = WIDTH & 0;
	SIZES = SIZES & 0;
	PRECISION = PRECISION & 0;
	TYPE = TYPE & 0;
	LEN = LEN & 0;
	NEG = NEG & 0;
	PRE_ON = PRE_ON & 0;
}

int				ft_type(va_list ap, t_param *param)
{
	static int		(*ftab[16])(va_list, t_param*) =
	{&ptr_string, &ptr_string_uni, &ptr_integer, &ptr_integer, &ptr_integer,
	&ptr_octal, &ptr_octal, &ptr_unsigned, &ptr_unsigned, &ptr_hexa, &ptr_hexa,
	&ptr_p, &ptr_char, &ptr_c_uni, &ptr_binary, &ptr_w};
	int				i;
	int				ret;

	i = 0;
	ret = 0;
	if (TYPE & pct)
		ptr_pct(param);
	else
		while (i < 17)
		{
			if (TYPE & (1 << i))
				ret = ftab[i](ap, param);
			i++;
		}
	ft_end_type(param);
	if (ret == -1)
		return (-1);
	return (1);
}
