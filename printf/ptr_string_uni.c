/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_string_uni.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:59:23 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/07 18:56:47 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_str_two_oct(wchar_t arg, t_param *param)
{
	if (MB_CUR_MAX < 2)
		return (-1);
	if (PRE_ON && PRECISION < 2)
		return (0);
	ft_buffer((0xC0 | ((arg >> 6) & 0x1F)), param);
	ft_buffer((0x80 | (arg & 0x3F)), param);
	PRECISION -= 2;
	return (1);
}

static int			ft_str_three_oct(wchar_t arg, t_param *param)
{
	if (MB_CUR_MAX < 3)
		return (-1);
	if (PRE_ON && PRECISION < 3)
		return (0);
	ft_buffer((0xE0 | ((arg >> 12) & 0x1F)), param);
	ft_buffer((0x80 | ((arg >> 6) & 0x3F)), param);
	ft_buffer((0x80 | (arg & 0x3F)), param);
	PRECISION -= 3;
	return (1);
}

static int			ft_str_four_oct(wchar_t arg, t_param *param)
{
	if (MB_CUR_MAX < 4)
		return (-1);
	if (PRE_ON && PRECISION < 4)
		return (0);
	ft_buffer((0xF0 | ((arg >> 18) & 0x1F)), param);
	ft_buffer((0x80 | ((arg >> 12) & 0x3F)), param);
	ft_buffer((0x80 | ((arg >> 6) & 0x3F)), param);
	ft_buffer((0x80 | (arg & 0x3F)), param);
	PRECISION -= 4;
	return (1);
}

static int			ft_c_uni(t_param *param, wchar_t arg)
{
	int			a;
	int			ret;

	ret = 1;
	a = 1;
	while (arg >> a)
		a++;
	if (a <= 8)
	{
		if (PRE_ON && PRECISION < 1)
			return (0);
		ft_buffer(arg, param);
		PRECISION--;
	}
	else if (a > 8 && a < 12)
		ret = ft_str_two_oct(arg, param);
	else if (a >= 12 && a < 17)
		ret = ft_str_three_oct(arg, param);
	else if (a >= 17 && a < 22)
		ret = ft_str_four_oct(arg, param);
	return (ret);
}

int					ptr_string_uni(va_list ap, t_param *param)
{
	wchar_t		*arg;
	int			i;
	int			ret;

	i = 0;
	ret = 1;
	arg = va_arg(ap, wchar_t *);
	(arg == NULL ? arg = L"(null)" : 0);
	ft_calcul_len(arg, param);
	(PRE_ON && LEN > PRECISION ? LEN = 0 : 0);
	(!(FLAGS & MINUS) ? ft_width_char(param) : 0);
	while (arg[i] && ret == 1)
	{
		if ((arg[i] >= 0xD800 && arg[i] <= 0xDFFF) || arg[i] > 0x10FFFF
		|| arg[i] < 0)
			return (-1);
		if ((ret = ft_c_uni(param, arg[i])) == -1)
			return (-1);
		i++;
	}
	(FLAGS & MINUS ? ft_width_char(param) : 0);
	return (1);
}
