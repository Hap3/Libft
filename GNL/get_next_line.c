/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:49:22 by cpaquet           #+#    #+#             */
/*   Updated: 2018/09/19 13:39:46 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define FD_REMAIN ((t_fd*)gnl_info->current_fd->content)->remain

static int			ft_search_fd(t_gnl *gnl_info, int fd)
{
	t_list	*tmp;
	t_list	*new_list;
	t_fd	new_fd;

	ft_bzero(&new_fd, sizeof(t_fd));
	new_fd.fd = fd;
	gnl_info->ret_read = 0;
	tmp = gnl_info->fd_save;
	gnl_info->current_fd = NULL;
	while (tmp && ((t_fd*)tmp->content)->fd != fd)
		tmp = tmp->next;
	if (tmp != NULL)
		gnl_info->current_fd = tmp;
	else
	{
		if (!(new_list = ft_lstnew(&new_fd, sizeof(t_fd))))
		{
			gnl_info->ret_read = -1;
			return (-1);
		}
		ft_lstadd(&gnl_info->fd_save, new_list);
		gnl_info->current_fd = gnl_info->fd_save;
	}
	return (1);
}

static int			ft_fill_fd(t_gnl *gnl_info, int fd)
{
	char	*tmp;
	char	buffer[BUFF_SIZE_GNL + 1];

	if (!FD_REMAIN)
		if (!(FD_REMAIN = ft_strnew(0)))
			return (-1);
	while (ft_strchr(FD_REMAIN, '\n') == 0 || ft_strchr(FD_REMAIN, '\0') == 0)
	{
		ft_bzero(buffer, BUFF_SIZE_GNL + 1);
		gnl_info->ret_read = read(fd, buffer, BUFF_SIZE_GNL);
		if (gnl_info->ret_read == -1 || gnl_info->ret_read == 0)
			return (1);
		tmp = FD_REMAIN;
		gnl_info->ret_read = 1;
		if (!(FD_REMAIN = ft_strjoin(tmp, buffer)))
		{
			gnl_info->ret_read = -1;
			return (-1);
		}
		ft_strdel(&tmp);
	}
	return (1);
}

static void			ft_free_fd(t_list **fd_save, t_list *to_delete, int flag)
{
	t_list	*tmp;

	if (*fd_save == to_delete)
		*fd_save = (*fd_save)->next;
	else
	{
		tmp = *fd_save;
		while (tmp->next != to_delete)
			tmp = tmp->next;
		tmp->next = tmp->next->next;
	}
	free(to_delete->content);
	free(to_delete);
	if (flag == 1 && to_delete)
		ft_free_fd(fd_save, *fd_save, 1);
}

static int			ft_use_fd(t_gnl *gnl_info, char **line)
{
	int		index;
	char	*tmp;

	index = 0;
	tmp = NULL;
	while (FD_REMAIN[index] != '\0' && FD_REMAIN[index] != '\n')
		index++;
	if (index == 0)
		return (1);
	*line = ft_strnew(index);
	ft_strncpy(*line, FD_REMAIN, index);
	if (FD_REMAIN[index] == '\n')
		index++;
	if (FD_REMAIN[0] != '\0')
	{
		gnl_info->ret_read = 1;
		if (!(tmp = ft_strdup(FD_REMAIN + index)))
			return (gnl_info->ret_read = -1);
	}
	ft_strdel(&FD_REMAIN);
	FD_REMAIN = tmp;
	if (!FD_REMAIN)
		ft_free_fd(&(gnl_info->fd_save), gnl_info->current_fd, 0);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	static t_gnl	*gnl_info = NULL;

	if (BUFF_SIZE_GNL == 0 || !(line) || fd < 0)
		return (-1);
	if (!gnl_info)
	{
		if (!(gnl_info = (t_gnl*)malloc(sizeof(t_gnl))))
			return (-1);
		ft_bzero(gnl_info, sizeof(t_gnl));
	}
	gnl_info->ret_read = 1;
	gnl_info->current_fd = NULL;
	if (ft_search_fd(gnl_info, fd) == -1 || ft_fill_fd(gnl_info, fd) == -1 ||
			ft_use_fd(gnl_info, line) == -1)
		ft_free_fd(&(gnl_info->fd_save), gnl_info->fd_save, 1);
	ret = gnl_info->ret_read;
	ret = (ret == 0 && *line && ft_strlen(*line) != 0 ? 1 : ret);
	if (gnl_info->fd_save == NULL)
	{
		free(gnl_info);
		gnl_info = NULL;
	}
	return (ret);
}
