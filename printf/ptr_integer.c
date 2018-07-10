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

	tmp = LEN;
	i = 0;
	(WIDTH && FLAGS & SPACE ? WIDTH -= 1 : 0);
	if (WIDTH <= LEN || WIDTH <= PRECISION)
		return ;
	(PRECISION > LEN ? tmp = PRECISION : tmp);
	(NEG == 1 || (NEG == 0 && FLAGS & PLUS) || FLAGS & HASHTAG ? tmp++ : 0);
	if (FLAGS & ZERO)
		c = '0';
	else
		c = ' ';
	while (i++ < WIDTH - tmp)
		ft_buffer(c, param);
}

static void		ft_sign_integer(t_param *param)
{
	(NEG == 0 && FLAGS & PLUS ? ft_buffer('+', param) : 0);
	(NEG == 1 ? ft_buffer('-', param) : 0);
}

static void		ft_space_integer(t_param *param, unsigned long long arg)
{
	(FLAGS & SPACE && NEG == 0 ? ft_buffer(' ', param) : 0);
	(PRE_ON && PRECISION == 0 && arg == 0 && WIDTH > 0 ?
	ft_buffer(' ', param) : 0);
}

int				ptr_integer(va_list ap, t_param *param)
{
	char				*base;
	unsigned long long	arg;

	base = "0123456789";
	((TYPE & D || TYPE & U) && (SIZES ^ LL) ? SIZES = SIZES ^ L : 0);
	arg = (unsigned long long)ft_cast_nbr(ap, param);
	ARG_STR = ft_itoa_base_char(arg, base);
	LEN = ft_strlen(ARG_STR);
	ft_space_integer(param, arg);
	if (!(FLAGS & MINUS))
	{
		(FLAGS & ZERO ? ft_sign_integer(param) : 0);
		ft_width_integer(param);
	}
	(!(FLAGS & ZERO) ? ft_sign_integer(param) : 0);
	(!((PRECISION == 0) && arg == 0 && PRE_ON == 1) ?
	ft_precision_nbr(param) : 0);
	(FLAGS & MINUS ? ft_width_integer(param) : 0);
	(arg != 0 && ARG_STR != NULL ? ft_strdel(&ARG_STR) : 0);
	return (1);
}
