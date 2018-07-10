/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printh2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:44:31 by cpaquet           #+#    #+#             */
/*   Updated: 2018/03/21 15:09:05 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <locale.h>
# include <stdint.h>
# include "libft.h"
# include "ft_printf_enum.h"
# include "colors.h"

# define BUFF_SIZE		2048
# define FLAGS_LIST		"#+-0 "
# define SIZES_LIST		"hhlljz"
# define TYPES_LIST		"sSdDioOuUxXpcCbw%"

# define INDEX			param->index
# define RETURN			param->return_index
# define SAVE			param->index_save
# define BUFFER			param->buffer

# define ARG_STR		param->arg_str
# define FLAGS			param->flags
# define WIDTH			param->width
# define PRECISION		param->precision
# define PRE_ON			param->precision_on
# define SIZES			param->sizes
# define TYPE			param->type
# define FD				param->fd

# define LEN			param->len_param
# define NEG			param->neg_param

typedef struct			s_param
{
	int		index;
	int		return_index;
	int		index_save;
	char	buffer[BUFF_SIZE];

	char	*arg_str;
	int		flags;
	int		width;
	int		precision;
	int		precision_on;
	int		type;
	int		sizes;
	int		fd;

	int		len_param;
	int		neg_param;
}						t_param;

int						ft_printf(const char *format, ...);
void					ft_buffer(const char ch, t_param *param);
int						ft_control(va_list ap, const char *format,
						t_param *param);
void					ft_clean_flags(t_param *param);
int						ft_type(va_list ap, t_param *param);

int						ptr_integer(va_list ap, t_param *param);
int						ptr_unsigned(va_list ap, t_param *param);
int						ptr_octal(va_list ap, t_param *param);
int						ptr_hexa(va_list ap, t_param *param);
int						ptr_p(va_list ap, t_param *param);
int						ptr_string(va_list ap, t_param *param);
int						ptr_char(va_list ap, t_param *param);
void					ft_width_char(t_param *param);
int						ptr_pct(t_param *param);
int						ptr_c_uni(va_list ap, t_param *param);
int						ptr_string_uni(va_list ap, t_param *param);
void					ft_calcul_len(wchar_t *arg, t_param *param);
int						ptr_binary(va_list ap, t_param *param);
int						ptr_w(va_list ap, t_param *param);

long long				ft_cast_nbr(va_list ap, t_param *param);
unsigned long long		ft_cast_unbr(va_list ap, t_param *param);
void					ft_precision_nbr(t_param *param);
void					ft_precision_str(t_param *param, char *arg);

#endif
