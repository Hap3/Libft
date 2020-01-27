/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cC.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:17:44 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/06 10:57:30 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width_p(t_param *param)
{
	int		i;

	i = 0;
	param->width -= 2;
	if (param->width < param->len_param)
		return ;
	while (i < param->width - param->len_param)
	{
		ft_buffer(' ', param);
		i++;
	}
}

static void		ft_hashtag_p(t_param *param)
{
	ft_buffer('0', param);
	ft_buffer('x', param);
}

int				ptr_p(va_list ap, t_param *param)
{
	unsigned long long	arg;
	char				*base;
	int					i;

	i = 0;
	base = "0123456789abcdef";
	arg = va_arg(ap, unsigned long long);
	param->arg_str = ft_itoa_base_char(arg, base);
	param->len_param = ft_strlen(param->arg_str);
	(!(param->flags & MINUS) ? ft_width_p(param) : 0);
	ft_hashtag_p(param);
	while (param->arg_str[i])
		ft_buffer(param->arg_str[i++], param);
	(param->flags & MINUS ? ft_width_p(param) : 0);
	(arg != 0 && param->arg_str != NULL ? ft_strdel(&param->arg_str) : 0);
	return (1);
}
