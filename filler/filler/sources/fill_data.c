/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:04:47 by dygouasd          #+#    #+#             */
/*   Updated: 2018/02/16 11:31:39 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		piece_data3(t_fill *fl)
{
	int		save;
	int		save_y;
	int		i;
	int		j;

	i = 0;
	j = 0;
	save = -1;
	save_y = 0;
	while (i < fl->p[1])
	{
		while (fl->piece[i][j] && fl->piece[i][j] != '*')
			++j;
		if (fl->piece[i][j] == '*' && (save > j || save == -1))
			save = j;
		if (save == -1)
			++save_y;
		j = 0;
		++i;
	}
	fl->sub_pos_x = save;
	fl->sub_pos_y = save_y;
	return (0);
}

void	piece_data2(t_fill *fl, int i, int j)
{
	while (j < fl->p[0])
	{
		if (fl->piece[i][j] == '*')
		{
			++fl->realenpy;
			return ;
		}
		++j;
	}
}

void	piece_data(t_fill *fl)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < fl->p[0])
	{
		i = 0;
		while (i < fl->p[1])
		{
			if (j == 0)
				piece_data2(fl, i, j);
			if (fl->piece[i][j] == '*')
			{
				++fl->realenpx;
				break ;
			}
			++i;
		}
		++j;
	}
}
