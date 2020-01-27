/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oO.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:12:41 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/06 14:13:17 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width_octal(t_param *param)
{
	char	c;
	int		i;
	int		tmp;

	tmp = param->len_param;
	i = 0;
	if (param->width <= param->len_param || param->width <= param->precision)
		return ;
	(param->flags & HASHTAG ? param->width-- : 0);
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

static void		ft_hashtag_octal(t_param *param)
{
	ft_buffer('0', param);
	if (param->precision > 0)
		param->precision--;
}

int				ptr_octal(va_list ap, t_param *param)
{
	char				*base;
	unsigned long long	arg;

	base = "01234567";
	(param->type & O && (!(param->sizes & LL)) ? param->sizes = S | L : 0);
	arg = (unsigned long long)ft_cast_unbr(ap, param);
	param->arg_str = ft_itoa_base_char(arg, base);
	param->len_param = ft_strlen(param->arg_str);
	(arg == 0 && (param->precision_on || param->flags & HASHTAG) ? param->len_param = 0 : 0);
	(!(param->flags & MINUS) ? ft_width_octal(param) : 0);
	(param->flags & HASHTAG ? ft_hashtag_octal(param) : 0);
	(!(arg == 0 && param->precision_on && param->precision == 0) ? ft_precision_nbr(param) : 0);
	(param->flags & MINUS ? ft_width_octal(param) : 0);
	(arg != 0 && param->arg_str != NULL ? ft_strdel(&param->arg_str) : 0);
	return (1);
}
