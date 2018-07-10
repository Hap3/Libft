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
	if (SIZES == 0)
		arg = (unsigned long long)(va_arg(ap, unsigned));
	else if (SIZES & J)
		arg = (unsigned long long)va_arg(ap, uintmax_t);
	else if (SIZES & LL)
		arg = va_arg(ap, unsigned long long int);
	else if (SIZES & L)
		arg = (unsigned long long)va_arg(ap, long unsigned int);
	else if (SIZES & HH)
		arg = (unsigned long long)((unsigned char)va_arg(ap, unsigned int));
	else if (SIZES & H)
		arg = (uintmax_t)((unsigned short)va_arg(ap, unsigned int));
	else
		arg = (unsigned long long)(va_arg(ap, size_t));
	return (arg);
}

long long				ft_cast_nbr(va_list ap, t_param *param)
{
	long long arg;

	arg = 0;
	if (SIZES == 0)
		arg = (long long)(va_arg(ap, int));
	else if (SIZES & J)
		arg = (long long)va_arg(ap, intmax_t);
	else if (SIZES & LL)
		arg = va_arg(ap, long long);
	else if (SIZES & L)
		arg = (long long)va_arg(ap, long int);
	else if (SIZES & HH)
		arg = (long long)((char)va_arg(ap, int));
	else if (SIZES & H)
		arg = (long long)((short)va_arg(ap, int));
	else if (SIZES & Z)
		arg = (long long)va_arg(ap, size_t);
	if (arg < 0)
	{
		NEG = 1;
		arg = -arg;
	}
	return (arg);
}
