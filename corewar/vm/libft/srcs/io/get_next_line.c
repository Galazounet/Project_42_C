/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:35:11 by afrangio          #+#    #+#             */
/*   Updated: 2018/09/26 14:35:02 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char		*copy_until_backslash(char **suite)
{
	char	*tmpret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmpret = ft_memalloc(sizeof(char) * ft_strlen(*suite) + 1);
	while ((*suite)[i] != '\n' && (*suite)[i])
	{
		tmpret[i] = (*suite)[i];
		i++;
	}
	tmpret[i] = '\0';
	while ((*suite)[i + j])
	{
		(*suite)[j] = (*suite)[i + 1 + j];
		j++;
	}
	(*suite)[j] = '\0';
	return (tmpret);
}

static int		ft_read(char **suite, int fd)
{
	char	*tmp;
	int		lu;
	int		realloc_size;

	lu = 1;
	tmp = ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	if (!ft_strstr(*suite, "\n"))
	{
		while ((lu = (read(fd, tmp, BUFF_SIZE))) > 0)
		{
			if (lu < 0)
				return (-1);
			realloc_size = sizeof(char) * ft_strlen(*suite) + 1 + BUFF_SIZE;
			if (*suite)
				*suite = ft_realloc(*suite, realloc_size);
			ft_strncat(*suite, tmp, BUFF_SIZE);
			if (ft_strstr(tmp, "\n"))
				break ;
			ft_bzero(tmp, BUFF_SIZE);
		}
	}
	free(tmp);
	return (lu);
}

int				get_next_line(int fd, char **line)
{
	static char	*suite[OPEN_MAX];
	int			lu;

	if (fd < 0 || fd > OPEN_MAX)
		return (-1);
	if (!line)
		return (-1);
	if (!suite[fd])
		suite[fd] = ft_memalloc(sizeof(char) * BUFF_SIZE);
	lu = ft_read(&suite[fd], fd);
	*line = copy_until_backslash(&suite[fd]);
	if (ft_strlen(*line) || ft_strlen(suite[fd]) || lu > 0)
		lu = 1;
	else
		free(suite[fd]);
	return (lu);
}
