/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:10:55 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/21 15:17:06 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			color(int i, t_tool *t, int iter)
{
	int		c;

	c = 0;
	if (iter == i)
		return (0x000000);
	i = t->r->iter < 1 ? 1 : 255 * i / t->r->iter;
	if (t->r->pint == 1)
		c = i * 0x1000000;
	i = i * t->r->color + c;
	return (i);
}

int			fun(t_tool *t)
{
	t_v2	pt;
	t_v2	diff;
	float	dist;
	float	condition;

	pt.x = -0.6;
	pt.y = 0.4;
	condition = 0.3;
	diff = (t_v2){t->new_r_i[0] - pt.x, t->new_r_i[1] - pt.y};
	dist = sqrt(diff.x * diff.x + diff.y * diff.y);
	if (fabs(diff.x) < 0.08 && fabs(diff.y) < 0.08)
		return ((dist / condition) * t->r->iter);
	return (0);
}

int			funny_func(t_kit *k)
{
	static int		j = 20;

	if (k->r.boing == 1)
	{
		if (k->r.iter > j)
			k->r.iter -= 2;
		if (k->r.iter < j)
			k->r.iter += 2;
		if (k->r.iter == j)
			j = j == 20 ? 130 : 20;
	}
	print_again(k);
	return (0);
}
