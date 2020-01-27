/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:14:45 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/06 11:21:06 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width_hexa(t_param *param, unsigned long long arg)
{
	char	c;
	int		tmp;
	int		i;

	i = 0;
	tmp = param->len_param;
	if (param->width <= param->len_param || param->width <= param->precision)
		return ;
	(param->precision > param->len_param ? tmp = param->precision : tmp);
	(arg == 0 && param->precision_on ? tmp = 0 : 0);
	(param->flags & HASHTAG && arg > 0 ? tmp += 2 : 0);
	if (param->flags & ZERO)
		c = '0';
	else
		c = ' ';
	while (i < param->width - tmp)
	{
		ft_buffer(c, param);
		i++;
	}
}

static void		ft_hashtag_hexa(t_param *param, unsigned long long arg)
{
	if (arg == 0)
		return ;
	(param->flags & HASHTAG || param->width == 0 ? ft_buffer('0', param) : 0);
	if (param->type & x)
		ft_buffer('x', param);
	else
		ft_buffer('X', param);
}

int				ptr_hexa(va_list ap, t_param *param)
{
	char				*base;
	unsigned long long	arg;

	if (param->type & x)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	arg = (unsigned long long)ft_cast_unbr(ap, param);
	param->arg_str = ft_itoa_base_char(arg, base);
	param->len_param = ft_strlen(param->arg_str);
	(param->flags & HASHTAG && param->flags & ZERO ? ft_hashtag_hexa(param, arg) : 0);
	(!(param->flags & MINUS) ? ft_width_hexa(param, arg) : 0);
	(param->flags & HASHTAG && !(param->flags & ZERO) ? ft_hashtag_hexa(param, arg) : 0);
	if (!((param->precision == 0) && arg == 0 && param->precision_on == 1))
		ft_precision_nbr(param);
	(param->flags & MINUS ? ft_width_hexa(param, arg) : 0);
	(arg != 0 && param->arg_str != NULL ? ft_strdel(&param->arg_str) : 0);
	return (1);
}
