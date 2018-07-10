/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:47:19 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/07 13:41:47 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width_pct(t_param *param)
{
	int		i;
	char	c;

	i = 0;
	(WIDTH >= 1 ? WIDTH-- : 0);
	if (FLAGS & ZERO)
		c = '0';
	else
		c = ' ';
	while (i < WIDTH)
	{
		ft_buffer(c, param);
		i++;
	}
}

int				ptr_pct(t_param *param)
{
	(!(FLAGS & MINUS) ? ft_width_pct(param) : 0);
	ft_buffer('%', param);
	(FLAGS & MINUS ? ft_width_pct(param) : 0);
	return (1);
}
