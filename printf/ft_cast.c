/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:56:54 by cpaquet           #+#    #+#             */
/*   Updated: 2018/01/30 16:25:48 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long		ft_cast_unbr(va_list ap, t_param *param)
{
	unsigned long long arg;

	arg = 0;
	if (param->sizes == 0)
		arg = (unsigned long long)(va_arg(ap, unsigned));
	else if (param->sizes & J)
		arg = (unsigned long long)va_arg(ap, uintmax_t);
	else if (param->sizes & LL)
		arg = va_arg(ap, unsigned long long int);
	else if (param->sizes & L)
		arg = (unsigned long long)va_arg(ap, long unsigned int);
	else if (param->sizes & HH)
		arg = (unsigned long long)((unsigned char)va_arg(ap, unsigned int));
	else if (param->sizes & H)
		arg = (uintmax_t)((unsigned short)va_arg(ap, unsigned int));
	else
		arg = (unsigned long long)(va_arg(ap, size_t));
	return (arg);
}

long long				ft_cast_nbr(va_list ap, t_param *param)
{
	long long arg;

	arg = 0;
	if (param->sizes == 0)
		arg = (long long)(va_arg(ap, int));
	else if (param->sizes & J)
		arg = (long long)va_arg(ap, intmax_t);
	else if (param->sizes & LL)
		arg = va_arg(ap, long long);
	else if (param->sizes & L)
		arg = (long long)va_arg(ap, long int);
	else if (param->sizes & HH)
		arg = (long long)((char)va_arg(ap, int));
	else if (param->sizes & H)
		arg = (long long)((short)va_arg(ap, int));
	else if (param->sizes & Z)
		arg = (long long)va_arg(ap, size_t);
	if (arg < 0)
	{
		param->neg_param = 1;
		arg = -arg;
	}
	return (arg);
}
