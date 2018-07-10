/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_string_uni.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:59:23 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/07 16:03:56 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_calcul_len(wchar_t *arg, t_param *param)
{
	int		index;
	int		a;

	index = 0;
	while (arg[index])
	{
		a = 0;
		while (arg[index] >> a)
			a++;
		if (a <= 8)
			LEN++;
		else if (a > 8 && a < 12)
			LEN += 2;
		else if (a >= 12 && a < 17)
			LEN += 3;
		else if (a >= 17 && a < 22)
			LEN += 4;
		index++;
	}
}
