/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cC.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:17:44 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/06 18:30:29 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_width_char(t_param *param)
{
	int		i;
	char	c;

	i = 0;
	if (param->width <= param->len_param)
		return ;
	if (param->flags & ZERO)
		c = '0';
	else
		c = ' ';
	while (i < param->width - param->len_param)
	{
		ft_buffer(c, param);
		i++;
	}
}

int			ptr_char(va_list ap, t_param *param)
{
	int		arg;

	param->len_param = 1;
	if (param->sizes & L)
		return (ptr_c_uni(ap, param));
	arg = va_arg(ap, int);
	if (!(param->flags & MINUS))
		ft_width_char(param);
	ft_buffer(arg, param);
	if (param->flags & MINUS)
		ft_width_char(param);
	return (1);
}
