/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_uti2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:43:15 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/22 10:00:15 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init(t_kit *k)
{
	k->m.img_ptr = NULL;
	k->r.space = 0;
	k->r.iter = 50;
	k->r.zoom = 1;
	k->r.inc_x = k->r.fractal == 1 || k->r.fractal == 2 ? -0.5 : 0;
	k->r.inc_y = k->r.fractal == 2 ? -0.5 : 0;
	k->r.c_re_im[0] = -0.6;
	k->r.c_re_im[1] = 0.27015;
	k->r.fun_mod = 0;
	k->r.boing = 0;
	k->r.pint = 0;
}

void		reinit(t_tool *t)
{
	t->new_r_i[0] = 0;
	t->new_r_i[1] = 0;
	t->old_re_im[0] = 0;
	t->old_re_im[1] = 0;
}

void		init_all(t_kit *k)
{
	int		i;

	i = 0;
	while (i < HEIGHT)
	{
		k->t[i].r = &k->r;
		k->t[i].m = &k->m;
		++i;
	}
	init(k);
}

void		thread_pos(t_kit *k)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i < HEIGHT)
	{
		k->t[i].startx = 0;
		k->t[i].starty = y;
		y += 1;
		k->t[i].endx = WIDTH;
		k->t[i].endy = y;
		++i;
	}
}
