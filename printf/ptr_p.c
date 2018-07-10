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
	WIDTH -= 2;
	if (WIDTH < LEN)
		return ;
	while (i < WIDTH - LEN)
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
	ARG_STR = ft_itoa_base_char(arg, base);
	LEN = ft_strlen(ARG_STR);
	(!(FLAGS & MINUS) ? ft_width_p(param) : 0);
	ft_hashtag_p(param);
	while (ARG_STR[i])
		ft_buffer(ARG_STR[i++], param);
	(FLAGS & MINUS ? ft_width_p(param) : 0);
	(arg != 0 && ARG_STR != NULL ? ft_strdel(&ARG_STR) : 0);
	return (1);
}
