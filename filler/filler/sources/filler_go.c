/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_go.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 09:31:03 by dygouasd          #+#    #+#             */
/*   Updated: 2018/02/16 13:31:42 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		proximity_test(t_fill *fl, int x, int y)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 2147483647;
	while (fl->map[i])
	{
		j = 0;
		while (fl->map[i][j] != '\0')
		{
			if (fl->map[i][j] == '*' && ABS((x - j)) + ABS((y - i)) < k)
				k = ABS((x - j)) + ABS((y - i));
			++j;
		}
		++i;
	}
	return (k);
}

int		time_to_pos_piece(t_fill *fl, int x, int y)
{
	int		i;
	int		j;
	int		pos;

	i = 0;
	pos = 0;
	while (fl->piece[i] != NULL)
	{
		j = 0;
		while (fl->piece[i][j] != '\0')
		{
			if (INMAP((i + y), (j + x), fl->m[1], fl->m[0]) &&
				fl->map[i + y][j + x] == fl->h && fl->piece[i][j] == '*')
				return (0);
			else if (((i + y < 0 || j + x < 0) || (i + y >= fl->m[1] ||
				j + x >= fl->m[0])) && fl->piece[i][j] == '*')
				return (0);
			else if (INMAP((i + y), (j + x), fl->m[1], fl->m[0]) &&
				fl->piece[i][j] == '*' && fl->map[i + y][j + x] == fl->a)
				++pos;
			++j;
		}
		++i;
	}
	return (pos);
}

int		time_to_pos_map(t_fill *fl)
{
	int		i;
	int		j;
	int		ret;
	int		newpos;

	newpos = 2147483647;
	i = fl->realenpy - fl->p[1] - 1;
	while (i++ < (fl->m[1]))
	{
		j = fl->realenpx - fl->p[0] - 1;
		while (j++ < (fl->m[0]))
		{
			if (time_to_pos_piece(fl, j, i) == 1)
			{
				ret = proximity_test(fl, j + fl->sub_pos_x, i + fl->sub_pos_y);
				if (ret <= newpos)
				{
					newpos = ret;
					fl->pos[0] = i;
					fl->pos[1] = j;
				}
			}
		}
	}
	return (0);
}

int		take_place(t_fill *fl)
{
	piece_data(fl);
	piece_data3(fl);
	get_pos(fl);
	time_to_pos_map(fl);
	ft_putnbr(fl->pos[0]);
	ft_putstr(" ");
	ft_putnbr(fl->pos[1]);
	ft_putendl("");
	fl->realenpx = 0;
	fl->realenpy = 0;
	fl->pos[0] = 0;
	fl->pos[1] = 0;
	return (0);
}
