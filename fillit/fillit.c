/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:51:21 by dygouasd          #+#    #+#             */
/*   Updated: 2017/12/06 14:52:43 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_data	g_global[19] = {
	{A1, 2, 2, {{1, 1, 0, 0}, {1, 1, 0, 0}, {0}, {0}}, 0, 0},
	{B1, 1, 4, {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}}, 0, 0},
	{B2, 4, 1, {{1, 1, 1, 1}, {0}, {0}, {0}}, 0, 0},
	{C1, 2, 3, {{1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {0}}, 0, 0},
	{C2, 3, 2, {{1, 0, 0, 0}, {1, 1, 1, 0}, {0}, {0}}, 0, 0},
	{C3, 2, 3, {{0, 1, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}, {0}}, 0, 0},
	{C4, 3, 2, {{1, 1, 1, 0}, {0, 0, 1, 0}, {0}, {0}}, 0, 0},
	{D1, 2, 3, {{1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0}}, 0, 0},
	{D2, 3, 2, {{0, 0, 1, 0}, {1, 1, 1, 0}, {0}, {0}}, 0, 0},
	{D3, 2, 3, {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}, {0}}, 0, 0},
	{D4, 3, 2, {{1, 1, 1, 0}, {1, 0, 0, 0}, {0}, {0}}, 0, 0},
	{E1, 3, 2, {{0, 1, 1, 0}, {1, 1, 0, 0}, {0}, {0}}, 0, 0},
	{E2, 2, 3, {{1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0}}, 0, 0},
	{F1, 3, 2, {{1, 1, 0, 0}, {0, 1, 1, 0}, {0}, {0}}, 0, 0},
	{F2, 2, 3, {{0, 1, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}, {0}}, 0, 0},
	{G1, 3, 2, {{0, 1, 0, 0}, {1, 1, 1, 0}, {0}, {0}}, 0, 0},
	{G2, 3, 2, {{1, 1, 1, 0}, {0, 1, 0, 0}, {0}, {0}}, 0, 0},
	{G3, 2, 3, {{0, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0}}, 0, 0},
	{G4, 2, 3, {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}, {0}}, 0, 0}
};

void	die(char *type, char *arg)
{
	if (ft_strcmp(type, "usage") == 0)
	{
		ft_putstr("Usage: ");
		ft_putstr(arg);
		ft_putendl(" [ file ]");
	}
	else
		ft_putendl("error");
	exit(EXIT_FAILURE);
}

void	replace(t_data *t, t_data g_tetra, int letter)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (g_tetra.tetrachar[i][j] == 1)
				t->tetrachar[i][j] = letter;
			else
				t->tetrachar[i][j] = 0;
			++j;
		}
		++i;
	}
}

int		match(t_data *t)
{
	int			j;
	static char alpha[26] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	static int	p = 0;
	int			l;

	j = 0;
	l = 0;
	while (j < N_TETRIMINOS)
	{
		if (t->tetras == g_global[j].tetras)
		{
			t->size_x = g_global[j].size_x;
			t->size_y = g_global[j].size_y;
			t->letter = alpha[p++];
			replace(t, g_global[j], t->letter);
			break ;
		}
		++j;
	}
	if (j == N_TETRIMINOS)
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		map[16];
	char		out[12 * 12];
	int			size;

	size = 2;
	ft_memset(map, 0, sizeof(map));
	ft_memset(g_t, 0, sizeof(g_t));
	if (argc != 2)
		die("usage", argv[0]);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		die("error", NULL);
	if (parse_all(fd, g_t) == -1)
		die("error", NULL);
	while (backtracker(map, 0, 0, size) == -1 && size < 12)
		++size;
	print_map(size, g_t, SIZE_MAPSTR(size), out);
	write(1, out, SIZE_MAPSTR(size));
	close(fd);
	return (EXIT_SUCCESS);
}
