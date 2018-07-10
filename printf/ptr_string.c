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
	tmp = LEN;
	(tmp > PRECISION && PRE_ON && PRECISION >= 0 ? tmp = PRECISION : 0);
	if (WIDTH <= tmp)
		return ;
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

int				ptr_string(va_list ap, t_param *param)
{
	if (SIZES & L)
		return (ptr_string_uni(ap, param));
	ARG_STR = (char *)va_arg(ap, void*);
	(ARG_STR == NULL ? ARG_STR = "(null)" : 0);
	LEN = ft_strlen(ARG_STR);
	(!(FLAGS & MINUS) ? ft_width_string(param) : 0);
	ft_precision_str(param, ARG_STR);
	(FLAGS & MINUS ? ft_width_string(param) : 0);
	return (1);
}
