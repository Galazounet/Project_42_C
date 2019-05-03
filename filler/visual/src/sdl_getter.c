/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_getter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:58:32 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 12:58:33 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int		getmapsize(t_map *m, int fd)
{
	char	*line;
	int		ret;
	char	*c;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line != NULL && ft_strlen(line) > 0)
		{
			if (ft_strstr(line, "Plateau") != NULL)
			{
				c = ft_strchr(line, ' ');
				m->size_y = ft_atoi(c);
				m->size_x = ft_atoi(c + lennbr(m->size_y) + 1);
				free(line);
				break ;
			}
			free(line);
		}
	}
	return (ret);
}

int		getplayerinfos(t_interface *i, int fd)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line != NULL && ft_strlen(line) > 0)
		{
			if (ft_strstr(line, "p1") != NULL)
			{
				*ft_strrchr(line, '.') = '\0';
				if ((i->p1 = ft_strdup(ft_strrchr(line, '/') + 1)) == NULL)
					return (-1);
			}
			if (ft_strstr(line, "p2") != NULL)
			{
				*ft_strrchr(line, '.') = '\0';
				if ((i->p2 = ft_strdup(ft_strrchr(line, '/') + 1)) == NULL)
					return (-1);
				free(line);
				break ;
			}
			free(line);
		}
	}
	return (ret);
}

int		getmap(t_map *m, int fd)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line != NULL)
		{
			if (line[0] == '0')
				fillmap(line, m->map, m->size_y);
			else if (line[0] == 'P')
			{
				free(line);
				break ;
			}
			free(line);
		}
	}
	return (ret);
}

float	getpercent(int color, char **map)
{
	int c;
	int	i;
	int	j;
	int n;

	c = color == BLUE ? 'O' : 'X';
	i = 0;
	n = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				n += 1;
			++j;
		}
		++i;
	}
	return ((float)((float)n / ((float)i * (float)j)));
}
