/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 10:15:59 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/21 14:19:23 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			frac_mandel2(t_tool *t, int i)
{
	while (i < t->r->iter)
	{
		t->old_re_im[0] = t->new_r_i[0];
		t->old_re_im[1] = t->new_r_i[1];
		t->new_r_i[0] = t->old_re_im[0] * t->old_re_im[0] -
			t->old_re_im[1] * t->old_re_im[1] + t->p_r_i[0];
		t->new_r_i[1] = 2 * t->old_re_im[0] * t->old_re_im[1]
			+ t->p_r_i[1];
		if ((t->new_r_i[0] * t->new_r_i[0] + t->new_r_i[1] *
			t->new_r_i[1]) > 4)
			break ;
		++i;
	}
	return (i);
}

void		*frac_mandel(void *u)
{
	int			i;
	t_tool		*t;

	t = u;
	t->y = t->starty;
	while (t->y < t->endy)
	{
		t->x = t->startx;
		while (t->x < t->endx)
		{
			t->p_r_i[0] = 1.5 * (t->x - WIDTH / 2) / (0.5 * t->r->zoom * WIDTH)
				+ t->r->inc_x;
			t->p_r_i[1] = (t->y - HEIGHT / 2) / (0.5 * t->r->zoom * HEIGHT)
				+ t->r->inc_y;
			reinit(t);
			i = 0;
			i = frac_mandel2(t, i);
			t->color = color(i, t, t->r->iter);
			t->m->img_data[t->y * WIDTH + t->x] = t->color;
			++t->x;
		}
		++t->y;
	}
	return (0);
}
