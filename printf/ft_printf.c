/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:50:56 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/07 15:54:32 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_param		param;
	va_list		ap;

	ft_bzero(&param, sizeof(t_param));
	va_start(ap, format);
	if (!(format) || format[param.index] == '\0')
		return (0);
	param.fd = 1;
	while (format[param.index] != '\0')
	{
		param.index_save = param.return_index;
		while (format[param.index] != '%' && format[param.index] != '\0')
			ft_buffer(format[param.index++], &param);
		if (ft_control(ap, format, &param) != -1)
			if (ft_type(ap, &param) == -1)
			{
				if (param.index_save % BUFF_SIZE != 0)
					write(param.fd, param.buffer, param.index_save);
				return (-1);
			}
	}
	if (param.return_index != 0 && param.return_index % BUFF_SIZE != 0)
		write(param.fd, param.buffer, param.return_index % BUFF_SIZE);
	return (param.return_index);
}
