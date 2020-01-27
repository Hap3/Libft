/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_param->flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:54:52 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/07 12:33:01 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_clean_flags(t_param *param)
{
	((param->flags & MINUS) && (param->flags & ZERO) ? param->flags = param->flags ^ ZERO : 0);
	((param->flags & PLUS) && (param->flags & SPACE) ? param->flags = param->flags ^ SPACE : 0);
	(param->precision_on && (param->flags & ZERO) && !(param->type & pct) ? param->flags = param->flags ^ ZERO : 0);
}
