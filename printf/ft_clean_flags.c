/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_flags.c                                   :+:      :+:    :+:   */
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
	((FLAGS & MINUS) && (FLAGS & ZERO) ? FLAGS = FLAGS ^ ZERO : 0);
	((FLAGS & PLUS) && (FLAGS & SPACE) ? FLAGS = FLAGS ^ SPACE : 0);
	(PRE_ON && (FLAGS & ZERO) && !(TYPE & pct) ? FLAGS = FLAGS ^ ZERO : 0);
}
