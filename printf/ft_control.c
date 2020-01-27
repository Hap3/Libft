/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:17:01 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/07 12:33:28 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_type(const char *format, t_param *param, int *type)
{
	int i;

	i = 0;
	while (format[param->index] && TYPES_LIST[i])
	{
		if (TYPES_LIST[i] == format[param->index])
		{
			param->index++;
			*type = *type | (1 << i);
			return (1);
		}
		i++;
	}
	return (-1);
}

static int	ft_check_char(char c, char *options_list)
{
	int		i;

	i = 0;
	while (options_list[i])
	{
		if (c == options_list[i])
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_check_options(const char *format, t_param *param,
		char *options_list, int *flags)
{
	int		i;
	int		j;

	i = param->index;
	while (format[i] != '\0' && ft_check_char(format[i], options_list) != -1)
	{
		j = ft_check_char(format[i], options_list);
		*flags = *flags | (1 << j);
		if (format[i] == format[i + 1] && j <= 2)
		{
			*flags = *flags | (1 << (j + 1));
			i++;
		}
		i++;
	}
	param->index = i;
	return ;
}

static void	ft_check_size(va_list ap, const char *format, t_param *param,
		int *value)
{
	int		i;

	i = param->index;
	if (format[param->index] == '*')
	{
		*value = va_arg(ap, int);
		param->index++;
	}
	else
	{
		while (format[i] != '\0' && ft_isdigit(format[i]))
			i++;
		if (i != param->index)
		{
			*value = ft_atoi(&format[param->index]);
			param->index = i;
			return ;
		}
	}
	return ;
}

int			ft_control(va_list ap, const char *format, t_param *param)
{
	if (format[param->index] != '%')
		return (0);
	param->index++;
	ft_check_options(format, param, FLAGS_LIST, &(param->flags));
	ft_check_size(ap, format, param, &(param->width));
	if (format[param->index] == '.')
	{
		param->index++;
		param->precision_on = 1;
		ft_check_size(ap, format, param, &(param->precision));
	}
	ft_check_options(format, param, SIZES_LIST, &(param->sizes));
	if (ft_check_type(format, param, &(param->type)) == -1)
		return (-1);
	ft_clean_flags(param);
	return (1);
}
