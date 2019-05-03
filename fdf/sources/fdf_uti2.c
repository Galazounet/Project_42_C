/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_uti2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:07:45 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/07 11:52:39 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_key2(int key, t_tool *t)
{
	if (key == 6)
		t->color[0] = R1;
	if (key == 7)
		t->color[0] = R2;
	if (key == 8)
		t->color[0] = R3;
	if (key == 9)
		t->color[0] = R4;
	if (key == 11)
		t->color[0] = R5;
	if (key == 45)
		t->color[0] = R6;
	if (key == 46)
		t->color[0] = R7;
	if (key == 15)
		t->rainbow = t->rainbow == 0 ? 1 : 0;
}

void	color_key(int key, t_tool *t)
{
	if (key == 18 || key == 83)
		t->color[0] = WHITE;
	if (key == 19 || key == 84)
		t->color[0] = CYAN;
	if (key == 20 || key == 85)
		t->color[0] = TUR;
	if (key == 21 || key == 86)
		t->color[0] = RED;
	if (key == 69)
		++t->nbpix;
	if (key == 78)
		--t->nbpix;
	if (key == 124)
		++t->inc;
	if (key == 123)
		--t->inc;
	if (key == 0)
		t->pos[0] -= 10;
	if (key == 2)
		t->pos[0] += 10;
	if (key == 13)
		t->pos[1] -= 10;
	if (key == 1)
		t->pos[1] += 10;
	color_key2(key, t);
}

int		funny_func2(t_tool *t)
{
	static int x = 0;

	if (t->rainbow == 1)
	{
		if (x == 0)
			t->color[0] = R1;
		if (x == 1)
			t->color[0] = R2;
		if (x == 2)
			t->color[0] = R3;
		if (x == 3)
			t->color[0] = R4;
		if (x == 4)
			t->color[0] = R5;
		if (x == 5)
			t->color[0] = R6;
		if (x == 6)
			t->color[0] = R7;
		++x;
		if (x == 7)
			x = 0;
	}
	print_again(t);
	return (0);
}

void	key_bronx(int key, t_tool *t)
{
	if (key == 31)
	{
		++t->inc;
		t->nbpix += 1;
	}
	if (key == 35)
	{
		--t->inc;
		t->nbpix -= 1;
	}
	if (key == 48)
		t->fun = t->fun == 0 ? 1 : 0;
}

int		funny_func(t_tool *t)
{
	if (t->spacekey == 1)
	{
		if (t->savedepth != t->depth * -1 && t->savedepth < t->depth * -1)
			t->depth++;
		if (t->savedepth == t->depth * -1)
			t->savedepth = t->savedepth * -1;
		if (t->savedepth != t->depth * -1 && t->savedepth > t->depth * -1)
			t->depth--;
		if (t->savedepth == t->depth * -1)
			t->savedepth = t->savedepth * -1;
	}
	funny_func2(t);
	print_again(t);
	return (0);
}
