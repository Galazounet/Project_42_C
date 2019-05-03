/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:22:43 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/07 13:18:01 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		nbr_line(t_tool *t, char **argv)
{
	int		fd;
	int		ret;
	char	*line;

	line = NULL;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		++t->leny;
		free(line);
		line = NULL;
	}
	close(fd);
	return (ret);
}

int		fill_number(t_tool *t, char *line, int j)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (j == 0)
		t->lenx = count_words(line, ' ');
	if (t->lenx < count_words(line, ' '))
		return (-1);
	if ((t->map[j] = malloc(sizeof(int) * t->lenx + 1)) == NULL)
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i] == '-' || (line[i] >= '0' && line[i] <= '9'))
		{
			t->map[j][k] = ft_atoi(&line[i]);
			while (line[i] != ' ' && line[i + 1] != '\0')
				++i;
			++k;
		}
		++i;
	}
	return (0);
}

int		get_map(t_tool *t, char **argv)
{
	int		j;
	int		fd;
	int		ret;
	char	*line;

	j = 0;
	line = NULL;
	if (nbr_line(t, argv) == -1)
		return (-1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	if ((t->map = malloc(sizeof(int *) * t->leny + 1)) == NULL)
		return (-1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (fill_number(t, line, j++) == -1)
			return (-1);
		free(line);
		line = NULL;
	}
	close(fd);
	return (ret);
}

int		press_key(int key, void *param)
{
	t_tool	*t;

	t = param;
	if (key == 53)
		exit(EXIT_FAILURE);
	if (key == 126)
		++t->depth;
	if (key == 125)
		--t->depth;
	if (key == 49)
	{
		t->spacekey = t->spacekey == 0 ? 1 : 0;
		t->savedepth = t->depth;
	}
	key_bronx(key, t);
	color_key(key, t);
	print_again(t);
	return (0);
}

int		main(int argc, char **argv)
{
	t_tool	t;
	int		xpixel;
	int		ypixel;

	init(&t);
	if (argc != 2)
		return (-1);
	if (get_map(&t, argv) == -1)
		return (0);
	if (t.lenx * 2 > 0)
		t.nbpix = WIDTH / (t.lenx * 2);
	t.inc = 3 * (t.nbpix / 5) + 1;
	xpixel = t.nbpix * (t.lenx - 1);
	ypixel = t.nbpix * (t.leny - 1);
	t.pos[0] = WIDTH / 2;
	t.pos[1] = HEIGHT / 2 - ypixel / 2;
	t.mlx_ptr = mlx_init();
	t.win_ptr = mlx_new_window(t.mlx_ptr, WIDTH, HEIGHT, "~L'X~");
	mlx_hook(t.win_ptr, 2, 5, press_key, (void *)&t);
	mlx_loop_hook(t.mlx_ptr, funny_func, (void *)&t);
	print_again(&t);
	mlx_loop(t.mlx_ptr);
	return (0);
}
