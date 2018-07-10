/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:50:20 by cpaquet           #+#    #+#             */
/*   Updated: 2018/06/11 17:18:46 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE_GNL 1024
# include "libft.h"
# include <stdlib.h>

typedef struct s_gnl
{
	int			ret_read;
	t_list		*fd_save;
	t_list		*current_fd;
}				t_gnl;

typedef struct	s_fd
{
	int			fd;
	char		*remain;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
