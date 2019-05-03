/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 15:38:01 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/07 10:42:32 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		put_line(t_tool *t, int x1, int y1)
{
	t->d[0] = ABS((t->in[0] - x1));
	t->d[1] = ABS((t->in[1] - y1));
	t->s[0] = x1 < t->in[0] ? 1 : -1;
	t->s[1] = y1 < t->in[1] ? 1 : -1;
	t->er[0] = (t->d[0] > t->d[1] ? t->d[0] : -t->d[1]) / 2;
	while (1)
	{
		if (RANGE(x1, y1))
			t->img_data[y1 * WIDTH + x1] = t->color[0];
		if (x1 == t->in[0] && y1 == t->in[1])
			break ;
		t->er[1] = t->er[0];
		if (t->er[1] > -t->d[0])
		{
			t->er[0] -= t->d[1];
			x1 += t->s[0];
		}
		if (t->er[1] < t->d[1])
		{
			t->er[0] += t->d[0];
			y1 += t->s[1];
		}
	}
	return (0);
}

int		split_print(t_tool *t, int i, int j)
{
	int		up;
	int		down;
	int		left;

	up = t->map[i][j] ? t->map[i][j] * t->depth : 0;
	down = (j + 1) < t->lenx ? t->map[i][j + 1] * t->depth : 0;
	left = (i + 1) < t->leny ? t->map[i + 1][j] * t->depth : 0;
	if ((j + 1) < t->lenx)
	{
		t->in[0] = t->pos[0] + ((j + 1) * t->nbpix) + (i * -t->nbpix);
		t->in[1] = t->pos[1] + ((j + 1) * t->inc) + (i * t->inc) - down;
		put_line(t, t->pos[0] + (j * t->nbpix) + (i * -t->nbpix),
		t->pos[1] + (j * t->inc) + (i * t->inc) - up);
	}
	if ((i + 1) < t->leny)
	{
		t->in[0] = t->pos[0] + (j * t->nbpix) + ((i + 1) * -t->nbpix);
		t->in[1] = t->pos[1] + (j * t->inc) + ((i + 1) * t->inc) - left;
		put_line(t, t->pos[0] + (i * -t->nbpix) + (j * t->nbpix),
		t->pos[1] + (i * t->inc) + (j * t->inc) - up);
	}
	return (0);
}

int		split_print_wua(t_tool *t, int i, int j)
{
	int		up;
	int		down;
	int		left;

	up = t->map[i][j] ? t->map[i][j] * t->depth : 0;
	down = (j + 1) < t->lenx ? t->map[i][j + 1] * t->depth : 0;
	left = (i + 1) < t->leny ? t->map[i + 1][j] * t->depth : 0;
	if ((j + 1) < t->lenx)
	{
		t->in[0] = t->pos[0] + (j * t->nbpix) + (i * -t->nbpix);
		t->in[1] = t->pos[1] + (j * t->inc) + (i * t->inc) - down;
		put_line(t, t->pos[0] + (j * t->nbpix) + (i * -t->nbpix),
		t->pos[1] + (j * t->inc) + (i * t->inc) - up);
	}
	if ((i + 1) < t->leny)
	{
		t->in[0] = t->pos[0] + (j * t->nbpix) + (i * -t->nbpix);
		t->in[1] = t->pos[1] + (j * t->inc) + (i * t->inc) - left;
		put_line(t, t->pos[0] + (i * -t->nbpix) + (j * t->nbpix),
		t->pos[1] + (i * t->inc) + (j * t->inc) - up);
	}
	return (0);
}

int		print_quadri(t_tool *t)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < t->leny)
	{
		while (j < t->lenx)
		{
			if (t->fun == 1)
				split_print_wua(t, i, j);
			else
				split_print(t, i, j);
			++j;
		}
		j = 0;
		++i;
	}
	return (0);
}
