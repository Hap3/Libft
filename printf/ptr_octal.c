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

	tmp = LEN;
	i = 0;
	if (WIDTH <= LEN || WIDTH <= PRECISION)
		return ;
	(FLAGS & HASHTAG ? WIDTH-- : 0);
	(PRECISION > LEN ? tmp = PRECISION : tmp);
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

static void		ft_hashtag_octal(t_param *param)
{
	ft_buffer('0', param);
	if (PRECISION > 0)
		PRECISION--;
}

int				ptr_octal(va_list ap, t_param *param)
{
	char				*base;
	unsigned long long	arg;

	base = "01234567";
	(TYPE & O && (!(SIZES & LL)) ? SIZES = S | L : 0);
	arg = (unsigned long long)ft_cast_unbr(ap, param);
	ARG_STR = ft_itoa_base_char(arg, base);
	LEN = ft_strlen(ARG_STR);
	(arg == 0 && (PRE_ON || FLAGS & HASHTAG) ? LEN = 0 : 0);
	(!(FLAGS & MINUS) ? ft_width_octal(param) : 0);
	(FLAGS & HASHTAG ? ft_hashtag_octal(param) : 0);
	(!(arg == 0 && PRE_ON && PRECISION == 0) ? ft_precision_nbr(param) : 0);
	(FLAGS & MINUS ? ft_width_octal(param) : 0);
	(arg != 0 && ARG_STR != NULL ? ft_strdel(&ARG_STR) : 0);
	return (1);
}
