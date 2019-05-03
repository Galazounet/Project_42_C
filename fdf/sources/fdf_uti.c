/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_uti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:23:28 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/07 12:47:25 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				count_words(char *s, char c)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j = 1;
		if (s[i] != c && j != 2)
		{
			k++;
			j = 2;
		}
		i++;
	}
	return (k);
}

int				n_length(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		++i;
	while (n != 0)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

void			init(t_tool *t)
{
	t->map = NULL;
	t->lenx = 0;
	t->leny = 0;
	t->depth = 3;
	t->nbpix = 10;
	t->spacekey = 0;
	t->color[0] = WHITE;
	t->color[1] = RED;
	t->inc = 10;
	t->img_ptr = NULL;
	t->rainbow = 0;
}

void			print_again(t_tool *t)
{
	int		bpp;
	int		size_line;
	int		endia;

	if (t->img_ptr != NULL)
		mlx_destroy_image(t->mlx_ptr, t->img_ptr);
	t->img_ptr = mlx_new_image(t->mlx_ptr, WIDTH, HEIGHT);
	t->img_data = (int*)mlx_get_data_addr(t->img_ptr, &bpp, &size_line, &endia);
	print_quadri(t);
	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr, t->img_ptr, 0, 0);
}
