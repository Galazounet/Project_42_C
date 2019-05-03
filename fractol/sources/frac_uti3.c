/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_uti3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:00:14 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/22 10:05:21 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		child_process(char **argv, int argc)
{
	pid_t			pid;

	if (argc > 2)
	{
		if ((pid = fork()) == -1)
			return (-1);
		else if (pid == 0)
		{
			if (execve("./fractol", &argv[1], NULL) == -1)
				return (-1);
		}
	}
	return (0);
}

int		change_frac(int key, t_kit *k)
{
	if (key == 83)
	{
		k->r.fractal = 0;
		init(k);
	}
	if (key == 84)
	{
		k->r.fractal = 1;
		init(k);
	}
	if (key == 85)
	{
		k->r.fractal = 2;
		init(k);
	}
	return (0);
}

int		color_key(int key, t_kit *k)
{
	if (key == 18)
		k->r.color = 0x10101;
	if (key == 19)
		k->r.color = 0x00101;
	if (key == 20)
		k->r.color = 0x10001;
	if (key == 21)
		k->r.color = 0x10000;
	if (key == 23)
		k->r.color = 0x11101;
	if (key == 22)
		k->r.color = 0x11111;
	if (key == 86)
		k->r.color += 0x10;
	if (key == 87)
		k->r.color -= 0x10;
	return (0);
}

int		all_move(int key, t_kit *k)
{
	if (key == 31)
		k->r.iter += 4;
	if (key == 35 && k->r.iter != 0)
		k->r.iter -= 4;
	if (key == 123)
		k->r.inc_x += 0.05 / k->r.zoom;
	if (key == 124)
		k->r.inc_x -= 0.05 / k->r.zoom;
	if (key == 125)
		k->r.inc_y -= 0.05 / k->r.zoom;
	if (key == 126)
		k->r.inc_y += 0.05 / k->r.zoom;
	if (key == 78)
		k->r.zoom -= 0.05 * k->r.zoom;
	if (key == 69)
		k->r.zoom += 0.05 * k->r.zoom;
	color_key(key, k);
	return (0);
}
