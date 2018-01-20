/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillresolv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:49:03 by dygouasd          #+#    #+#             */
/*   Updated: 2017/12/06 14:51:38 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

void	fill_newline(int size, int height, char *mapstr)
{
	int		nl;

	nl = 0;
	while (nl < size)
	{
		nl += nl < height ? (size / height) - 1 : (size / height);
		mapstr[nl] = '\n';
	}
}

void	print_map(int height, t_data *t, int size, char *map)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	ft_memset(map, '.', size);
	while (t->tetras != 0)
	{
		j = 0;
		i = t->p < 11 ? t->p : (t->p / 11 * height) + (t->p / 11) + t->p % 11;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				map[i] = t->tetrachar[j][k] != 0 ? t->tetrachar[j][k] : map[i];
				i++;
				k++;
			}
			i += (height - 4) + 1;
			++j;
		}
		t++;
	}
	fill_newline(size, height, map);
}

void	delete_tetra(char *map, long tetra, int p)
{
	long	*filler;

	filler = (long*)&map[p / 8];
	*filler ^= tetra << p % 8;
}

int		fill_map(char *map, t_data *t, int p, int size)
{
	long	*filler;
	int		mp;

	mp = p % 8;
	filler = (long*)&map[p / 8];
	if (COLLISION_T(*filler, t->tetras, mp)
		&& COLLISION_X(p, size, t->size_x)
		&& COLLISION_Y(p, size, t->size_y))
	{
		*filler |= t->tetras << mp;
		t->p = p;
		return (0);
	}
	return (-1);
}

int		backtracker(char *map, int n, int p, int size)
{
	int		i;
	int		range;

	i = 0;
	if (g_t[n].tetras == 0)
		return (0);
	while (p + i < size * 11)
	{
		range = (p + i) < 11 ? 0 : (p + i) % 11;
		if (range < size && fill_map(map, &g_t[n], p + i, size) == 0)
			break ;
		++i;
	}
	if (p + i >= size * 11)
		return (-1);
	if (backtracker(map, n + 1, 0, size) == -1)
	{
		delete_tetra(map, g_t[n].tetras, p + i);
		return (backtracker(map, n, p + i + 1, size));
	}
	return (0);
}
