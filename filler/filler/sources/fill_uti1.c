/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_uti1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:03:26 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/01 15:48:52 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		len_nbr(intmax_t i)
{
	int			j;

	j = 0;
	if (i <= 0)
		return (-1);
	while (i != 0)
	{
		i /= 10;
		++j;
	}
	return (j);
}

int		get_pos(t_fill *fl)
{
	int		i;
	int		j;

	i = 0;
	while (fl->map[i])
	{
		j = 0;
		while (fl->map[i][j] != '\0')
		{
			if (fl->map[i + 1] != NULL && fl->map[i][j] == '.' &&
				(fl->map[i + 1][j] == fl->h || fl->map[i][j + 1] == fl->h))
				fl->map[i][j] = '*';
			if (((i != 0 && fl->map[i - 1][j] == fl->h) ||
				(j != 0 && fl->map[i][j - 1] == fl->h)) && fl->map[i][j] == '.')
				fl->map[i][j] = '*';
			++j;
		}
		++i;
	}
	return (0);
}

void	want_free(t_fill *fl, int j)
{
	int		i;

	i = 0;
	if (j == 1)
	{
		while (i < fl->p[1])
			free(fl->piece[i++]);
		if (fl->piece)
			free(fl->piece);
		fl->piece = NULL;
	}
	else if (j == 2)
	{
		while (i < fl->m[1] && j == 2)
			free(fl->map[i++]);
		if (fl->map)
			free(fl->map);
		fl->map = NULL;
	}
}

int		check_all(t_fill *fl)
{
	int		i;

	i = 0;
	while (fl->map[i])
	{
		if (ft_strlen(fl->map[i]) != (size_t)fl->m[0])
			return (-1);
		++i;
	}
	if (i < fl->m[1] || i > fl->m[1])
		return (-1);
	return (0);
}
