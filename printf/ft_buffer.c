/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param->buffer.c                                        :+:      :+:    :+:   */
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
	param->buffer[param->return_index % BUFF_SIZE] = c;
	param->return_index++;
	if (param->return_index != 0 && param->return_index % BUFF_SIZE == 0)
	{
		write(param->fd, param->buffer, BUFF_SIZE);
		ft_bzero(param->buffer, BUFF_SIZE);
	}
}
