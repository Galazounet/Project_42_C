/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 07:40:01 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/18 14:46:15 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					read_fd(int const fd, char **str)
{
	int				ret;
	char			*tmp;
	char			*ptr;

	if (*str != NULL && ft_strchr(*str, '\n'))
		return (1);
	if ((tmp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		if (*str == NULL)
			*str = ft_strdup(tmp);
		else
		{
			ptr = *str;
			*str = ft_strjoin(ptr, tmp);
			free(ptr);
		}
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	if (tmp)
		free(tmp);
	return (ret < 0 ? -1 : 0);
}

int					cp_line_with_str(char **buf, char **line, char *s)
{
	char			*str;

	str = NULL;
	if (s == NULL)
	{
		*line = ft_strdup(*buf);
		ft_strdel(buf);
		return (1);
	}
	str = ft_strdup(s + 1);
	*line = ft_strnew(((s - *buf)));
	*line = ft_strncpy(*line, *buf, (s - *buf));
	ft_strdel(buf);
	*buf = ft_strdup(str);
	if (ft_strcmp(*buf, "\0") == 0)
		ft_strdel(buf);
	ft_strdel(&str);
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static char		*buf;
	char			*str;
	int				ret;

	str = NULL;
	ret = 1;
	if (fd < 0 || line == NULL)
	{
		if (buf)
			ft_strdel(&buf);
		return (-1);
	}
	if ((ret = read_fd(fd, &buf)) < 0)
	{
		if (buf)
			ft_strdel(&buf);
		return (ret);
	}
	if (buf == NULL)
		return (0);
	str = ft_strchr(buf, '\n');
	return (cp_line_with_str(&buf, line, str));
}
