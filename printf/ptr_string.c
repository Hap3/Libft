/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sS.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:17:11 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/06 11:22:43 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width_string(t_param *param)
{
	int		tmp;
	int		i;
	char	c;

	i = 0;
	tmp = param->len_param;
	(tmp > param->precision && param->precision_on && param->precision >= 0 ? tmp = param->precision : 0);
	if (param->width <= tmp)
		return ;
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

int				ptr_string(va_list ap, t_param *param)
{
	if (param->sizes & L)
		return (ptr_string_uni(ap, param));
	param->arg_str = (char *)va_arg(ap, void*);
	(param->arg_str == NULL ? param->arg_str = "(null)" : 0);
	param->len_param = ft_strlen(param->arg_str);
	(!(param->flags & MINUS) ? ft_width_string(param) : 0);
	ft_precision_str(param, param->arg_str);
	(param->flags & MINUS ? ft_width_string(param) : 0);
	return (1);
}
