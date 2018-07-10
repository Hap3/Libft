/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_c_uni.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:23:53 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/07 18:45:58 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				ft_two_oct(wchar_t arg, t_param *param)
{
	LEN = 2;
	if (!(FLAGS & MINUS))
		ft_width_char(param);
	if ((int)MB_CUR_MAX < LEN)
		return (-1);
	ft_buffer((char)(0xC0 | ((arg >> 6) & 0x1F)), param);
	ft_buffer((char)(0x80 | (arg & 0x3F)), param);
	return (1);
}

static int				ft_three_oct(wchar_t arg, t_param *param)
{
	LEN = 3;
	if (!(FLAGS & MINUS))
		ft_width_char(param);
	if ((int)MB_CUR_MAX < LEN)
		return (-1);
	ft_buffer((char)(0xE0 | ((arg >> 12) & 0x1F)), param);
	ft_buffer((char)(0x80 | ((arg >> 6) & 0x3F)), param);
	ft_buffer((char)(0x80 | (arg & 0x3F)), param);
	return (1);
}

static int				ft_four_oct(wchar_t arg, t_param *param)
{
	LEN = 4;
	if ((int)MB_CUR_MAX < LEN)
		return (-1);
	if (!(FLAGS & MINUS))
		ft_width_char(param);
	ft_buffer((char)(0xF0 | ((arg >> 18) & 0x1F)), param);
	ft_buffer((char)(0x80 | ((arg >> 12) & 0x3F)), param);
	ft_buffer((char)(0x80 | ((arg >> 6) & 0x3F)), param);
	ft_buffer((char)(0x80 | (arg & 0x3F)), param);
	return (1);
}

static int				ft_size_uni_char(wchar_t arg, t_param *param, int a)
{
	int		ret;

	ret = 0;
	if (a <= 8)
	{
		LEN = 1;
		if (!(FLAGS & MINUS))
			ft_width_char(param);
		ft_buffer(arg, param);
	}
	else if (a > 8 && a < 12)
		ret = ft_two_oct(arg, param);
	else if (a >= 12 && a < 17)
		ret = ft_three_oct(arg, param);
	else if (a >= 17 && a < 22)
		ret = ft_four_oct(arg, param);
	return (ret);
}

int						ptr_c_uni(va_list ap, t_param *param)
{
	wchar_t		arg;
	int			a;

	arg = va_arg(ap, wchar_t);
	if ((arg >= 0xD800 && arg <= 0xDFFF) || arg >= 0x10FFFF || arg < 0)
		return (-1);
	a = 0;
	while (arg >> a)
		a++;
	if (ft_size_uni_char(arg, param, a) == -1)
		return (-1);
	if (FLAGS & MINUS)
		ft_width_char(param);
	return (1);
}
