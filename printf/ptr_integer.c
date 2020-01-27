/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dDi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:04:51 by cpaquet           #+#    #+#             */
/*   Updated: 2018/03/21 14:28:38 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width_integer(t_param *param)
{
	char	c;
	int		i;
	int		tmp;

	tmp = param->len_param;
	i = 0;
	(param->width && param->flags & SPACE ? param->width -= 1 : 0);
	if (param->width <= param->len_param || param->width <= param->precision)
		return ;
	(param->precision > param->len_param ? tmp = param->precision : tmp);
	(param->neg_param == 1 || (param->neg_param == 0 && param->flags & PLUS) || param->flags & HASHTAG ? tmp++ : 0);
	if (param->flags & ZERO)
		c = '0';
	else
		c = ' ';
	while (i++ < param->width - tmp)
		ft_buffer(c, param);
}

static void		ft_sign_integer(t_param *param)
{
	(param->neg_param == 0 && param->flags & PLUS ? ft_buffer('+', param) : 0);
	(param->neg_param == 1 ? ft_buffer('-', param) : 0);
}

static void		ft_space_integer(t_param *param, unsigned long long arg)
{
	(param->flags & SPACE && param->neg_param == 0 ? ft_buffer(' ', param) : 0);
	(param->precision_on && param->precision == 0 && arg == 0 && param->width > 0 ?
	ft_buffer(' ', param) : 0);
}

int				ptr_integer(va_list ap, t_param *param)
{
	char				*base;
	unsigned long long	arg;

	base = "0123456789";
	((param->type & D || param->type & U) && (param->sizes ^ LL) ? param->sizes = param->sizes ^ L : 0);
	arg = (unsigned long long)ft_cast_nbr(ap, param);
	param->arg_str = ft_itoa_base_char(arg, base);
	param->len_param = ft_strlen(param->arg_str);
	ft_space_integer(param, arg);
	if (!(param->flags & MINUS))
	{
		(param->flags & ZERO ? ft_sign_integer(param) : 0);
		ft_width_integer(param);
	}
	(!(param->flags & ZERO) ? ft_sign_integer(param) : 0);
	(!((param->precision == 0) && arg == 0 && param->precision_on == 1) ?
	ft_precision_nbr(param) : 0);
	(param->flags & MINUS ? ft_width_integer(param) : 0);
	(arg != 0 && param->arg_str != NULL ? ft_strdel(&param->arg_str) : 0);
	return (1);
}
