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

	tmp = param->len_param;
	i = 0;
	if (param->width <= param->len_param || param->width <= param->precision)
		return ;
	(param->precision > param->len_param ? tmp = param->precision : tmp);
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

int				ptr_unsigned(va_list ap, t_param *param)
{
	char				*base;
	unsigned long long	arg;

	base = "0123456789";
	if ((param->type & D || param->type & U) && (param->sizes ^ LL))
		param->sizes = param->sizes | L;
	arg = (unsigned long long)ft_cast_unbr(ap, param);
	param->arg_str = ft_itoa_base_char(arg, base);
	param->len_param = ft_strlen(param->arg_str);
	(!(param->flags & MINUS) ? ft_width_unsigned(param) : 0);
	if (!((param->precision == 0) && arg == 0 && param->precision_on == 1))
		ft_precision_nbr(param);
	(param->flags & MINUS ? ft_width_unsigned(param) : 0);
	(arg != 0 && param->arg_str != NULL ? ft_strdel(&param->arg_str) : 0);
	return (1);
}
