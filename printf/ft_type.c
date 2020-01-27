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
	param->flags = param->flags & 0;
	param->width = param->width & 0;
	param->sizes = param->sizes & 0;
	param->precision = param->precision & 0;
	param->type = param->type & 0;
	param->len_param = param->len_param & 0;
	param->neg_param = param->neg_param & 0;
	param->precision_on = param->precision_on & 0;
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
	if (param->type & pct)
		ptr_pct(param);
	else
		while (i < 17)
		{
			if (param->type & (1 << i))
				ret = ftab[i](ap, param);
			i++;
		}
	ft_end_type(param);
	if (ret == -1)
		return (-1);
	return (1);
}
