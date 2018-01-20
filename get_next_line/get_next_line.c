/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:12:02 by dygouasd          #+#    #+#             */
/*   Updated: 2017/12/06 17:50:32 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int		ft_putinline(t_p *k, char **line)
{
	char	*tmp;

	if ((tmp = ft_strchr(k->pos, '\n')) != NULL)
	{
		*line = ft_strsub(k->pos, 0, tmp - k->pos);
		k->pos = tmp + 1;
		return (1);
	}
	tmp = (!tmp) ? k->pos : tmp;
	if ((tmp = ft_strchr(tmp, '\0')) != NULL && *k->pos != '\0')
	{
		*line = ft_strsub(k->pos, 0, tmp - k->pos);
		k->pos = tmp;
		return (1);
	}
	ft_strdel(&k->buff);
	k->buff = NULL;
	return (0);
}

char	*ft_realloc(char *buf, t_p *k)
{
	char		*tmp2;

	k->indice = 0;
	tmp2 = malloc(ft_strlen(k->buff) + BUFF_TOTAL);
	ft_strcpy(tmp2, k->buff);
	ft_strcat(tmp2, buf);
	k->pos = &tmp2[k->pos - k->buff];
	free(k->buff);
	return (tmp2);
}

int		ft_read(const int fd, t_p *k, char **line)
{
	int		rec;
	char	buf[BUFF_TOTAL];

	if (k == NULL || fd < 0 || !line)
		return (-1);
	while ((rec = read(fd, buf, BUFF_SIZE)) > 0)
	{
		k->indice += rec;
		buf[rec] = '\0';
		if (k->buff == NULL)
		{
			if ((k->buff = malloc(sizeof(char) * BUFF_TOTAL + 1)) == NULL)
				return (-1);
			ft_strcpy(k->buff, buf);
			k->pos = &k->buff[0];
		}
		else
			k->buff = k->indice + BUFF_SIZE > BUFF_TOTAL ? \
				ft_realloc(buf, k) : ft_strcat(k->buff, buf);
		if (ft_strchr(k->pos, '\n'))
			break ;
	}
	if (rec == 0 && k->pos == NULL)
		return (0);
	return ((rec == -1) ? -1 : ft_putinline(k, line));
}

void	ft_delete_fd(t_p **begin, const int fd)
{
	t_p		*tmp;

	tmp = *begin;
	while (tmp->next != NULL && tmp->next->fd != fd)
		tmp = tmp->next;
	if (tmp->fd == fd)
	{
		if (tmp->next != NULL)
			*begin = (*begin)->next;
		free(tmp);
		return ;
	}
	if (tmp->next != NULL && tmp->next->fd == fd)
	{
		free(tmp->next);
		if (tmp->next->next != NULL)
			tmp->next = tmp->next->next;
		else
			tmp->next = NULL;
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_p		*k = NULL;
	t_p				*save;
	int				i;

	save = k;
	while (save != NULL && save->next != NULL && save->fd != fd)
		save = save->next;
	if (save == NULL)
	{
		if ((k = ft_memalloc(sizeof(t_p))) == NULL)
			return (-1);
		save = k;
	}
	else if (save->fd != fd)
	{
		if ((save->next = ft_memalloc(sizeof(t_p))) == NULL)
			return (-1);
		save = save->next;
	}
	save->fd = fd;
	if ((i = ft_read(fd, save, line)) == 0)
		ft_delete_fd(&k, fd);
	return (i);
}
