/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_uti1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:45:53 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/21 14:20:27 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		join_thread(pthread_t *myfrac)
{
	int		i;

	i = 0;
	while (i < HEIGHT)
	{
		pthread_join(myfrac[i], NULL);
		++i;
	}
}

void		create_j_thread(void *(*func)(void *), pthread_t *myfrac, t_kit *k)
{
	int		i;

	i = 0;
	while (i < HEIGHT)
	{
		pthread_create(&myfrac[i], NULL, func, (void*)&k->t[i]);
		++i;
	}
	join_thread(&myfrac[0]);
}

void		putstr(t_kit *k)
{
	char	*pre;
	char	*zoom;

	pre = ft_itoa(k->r.iter);
	zoom = ft_itoa(k->r.zoom);
	if (!pre || !zoom)
		return ;
	mlx_string_put(k->m.mlx_ptr, k->m.win_ptr, WIDTH - 170, HEIGHT - 30,
		0xFFFFFF, "Zoom : ");
	mlx_string_put(k->m.mlx_ptr, k->m.win_ptr, WIDTH - 100, HEIGHT - 30,
		0xFFFFFF, zoom);
	mlx_string_put(k->m.mlx_ptr, k->m.win_ptr, WIDTH - 170, HEIGHT - 50,
		0xFFFFFF, "Precision : ");
	mlx_string_put(k->m.mlx_ptr, k->m.win_ptr, WIDTH - 50, HEIGHT - 50,
		0xFFFFFF, pre);
	free(pre);
	free(zoom);
}

void		print_again(t_kit *k)
{
	int				bpp;
	int				size_line;
	int				endia;
	pthread_t		myfrac[HEIGHT + 1];

	if (k->m.img_ptr != NULL)
		mlx_destroy_image(k->m.mlx_ptr, k->m.img_ptr);
	k->m.img_ptr = mlx_new_image(k->m.mlx_ptr, WIDTH, HEIGHT);
	k->m.img_data = (int*)mlx_get_data_addr(k->m.img_ptr, &bpp, &size_line,
		&endia);
	if (k->r.fractal == 0)
		create_j_thread(frac_julia, &myfrac[0], k);
	else if (k->r.fractal == 1)
		create_j_thread(frac_mandel, &myfrac[0], k);
	else if (k->r.fractal == 2)
		create_j_thread(frac_burn, &myfrac[0], k);
	mlx_put_image_to_window(k->m.mlx_ptr, k->m.win_ptr, k->m.img_ptr, 0, 0);
	putstr(k);
}
