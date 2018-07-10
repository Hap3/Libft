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
	tmp = LEN;
	if (WIDTH <= LEN || WIDTH <= PRECISION)
		return ;
	(PRECISION > LEN ? tmp = PRECISION : tmp);
	(arg == 0 && PRE_ON ? tmp = 0 : 0);
	(FLAGS & HASHTAG && arg > 0 ? tmp += 2 : 0);
	if (FLAGS & ZERO)
		c = '0';
	else
		c = ' ';
	while (i < WIDTH - tmp)
	{
		ft_buffer(c, param);
		i++;
	}
}

static void		ft_hashtag_hexa(t_param *param, unsigned long long arg)
{
	if (arg == 0)
		return ;
	(FLAGS & HASHTAG || WIDTH == 0 ? ft_buffer('0', param) : 0);
	if (TYPE & x)
		ft_buffer('x', param);
	else
		ft_buffer('X', param);
}

int				ptr_hexa(va_list ap, t_param *param)
{
	char				*base;
	unsigned long long	arg;

	if (TYPE & x)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	arg = (unsigned long long)ft_cast_unbr(ap, param);
	ARG_STR = ft_itoa_base_char(arg, base);
	LEN = ft_strlen(ARG_STR);
	(FLAGS & HASHTAG && FLAGS & ZERO ? ft_hashtag_hexa(param, arg) : 0);
	(!(FLAGS & MINUS) ? ft_width_hexa(param, arg) : 0);
	(FLAGS & HASHTAG && !(FLAGS & ZERO) ? ft_hashtag_hexa(param, arg) : 0);
	if (!((PRECISION == 0) && arg == 0 && PRE_ON == 1))
		ft_precision_nbr(param);
	(FLAGS & MINUS ? ft_width_hexa(param, arg) : 0);
	(arg != 0 && ARG_STR != NULL ? ft_strdel(&ARG_STR) : 0);
	return (1);
}
