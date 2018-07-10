/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:07:43 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/01 17:30:31 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_buffer(const char c, t_param *param)
{
	BUFFER[RETURN % BUFF_SIZE] = c;
	RETURN++;
	if (RETURN != 0 && RETURN % BUFF_SIZE == 0)
	{
		write(FD, BUFFER, BUFF_SIZE);
		ft_bzero(BUFFER, BUFF_SIZE);
	}
}
