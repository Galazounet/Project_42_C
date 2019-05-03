/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:22:43 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/21 14:36:33 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_press(int x, int y, void *param)
{
	t_kit *k;

	k = param;
	if (k->r.fractal == 0 && k->r.space == 0)
	{
		k->r.c_re_im[0] = -0.6 - x * 0.0005;
		k->r.c_re_im[1] = 0.27015 - y * 0.0015;
		print_again(k);
	}
	return (0);
}

int		mouse_roll(int button, int x, int y, void *param)
{
	t_kit	*k;

	k = param;
	if (button == 1)
	{
		if (x <= WIDTH / 2)
			k->r.inc_x -= 0.02;
		else
			k->r.inc_x += 0.02;
		if (y <= HEIGHT / 2)
			k->r.inc_y -= 0.02;
		else
			k->r.inc_y += 0.02;
		k->r.zoom += 0.05 * k->r.zoom;
	}
	if (button == 4)
		k->r.zoom += 0.05 * k->r.zoom;
	if (button == 5)
		k->r.zoom -= 0.05 * k->r.zoom;
	return (0);
}

int		press_key(int key, void *param)
{
	t_kit	*k;

	k = param;
	if (key == 53)
		exit(EXIT_FAILURE);
	if (key == 49)
		k->r.space = k->r.space == 1 ? 0 : 1;
	if (key == 11)
	{
		k->r.saveiter = k->r.iter;
		k->r.boing = k->r.boing == 0 ? 1 : 0;
	}
	if (key == 3)
		k->r.fun_mod = k->r.fun_mod == 0 ? 1 : 0;
	if (key == 8)
		k->r.pint = k->r.pint == 0 ? 1 : 0;
	if (key == 36)
		init(k);
	all_move(key, k);
	change_frac(key, k);
	print_again(k);
	return (0);
}

int		frac_finded(t_kit *k, char **argv, int argc)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp("julia", argv[i]) == 0)
			k->r.fractal = i == 1 ? 0 : k->r.fractal;
		else if (ft_strcmp("mandelbrot", argv[i]) == 0)
			k->r.fractal = i == 1 ? 1 : k->r.fractal;
		else if (ft_strcmp("burningship", argv[i]) == 0)
			k->r.fractal = i == 1 ? 2 : k->r.fractal;
		else
		{
			k->r.fractal = -1;
			return (-1);
		}
		++i;
	}
	k->r.color = 0x10101;
	return (0);
}

int		main(int argc, char **argv)
{
	t_kit			k;

	if (argc < 2 || frac_finded(&k, argv, argc) == -1)
	{
		ft_putstr("It's not okay baby\n");
		return (-1);
	}
	init_all(&k);
	thread_pos(&k);
	k.m.mlx_ptr = mlx_init();
	k.m.win_ptr = mlx_new_window(k.m.mlx_ptr, WIDTH, HEIGHT, "~L'X~");
	mlx_hook(k.m.win_ptr, 2, 5, press_key, (void *)&k);
	mlx_hook(k.m.win_ptr, 6, 64, mouse_press, (void *)&k);
	mlx_mouse_hook(k.m.win_ptr, mouse_roll, (void *)&k);
	mlx_loop_hook(k.m.mlx_ptr, funny_func, (void *)&k);
	child_process(argv, argc);
	print_again(&k);
	mlx_loop(k.m.mlx_ptr);
	return (0);
}
