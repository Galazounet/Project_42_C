/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 09:56:33 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 13:09:29 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	fl_init(t_fill *fl)
{
	fl->round = 0;
	fl->m[1] = 0;
	fl->m[0] = 0;
	fl->p[1] = 0;
	fl->p[0] = 0;
	fl->a = 0;
	fl->h = 0;
	fl->realenpx = 0;
	fl->realenpy = 0;
	fl->map = NULL;
	fl->piece = NULL;
}

int		pars_stock_map(t_fill *fl, char *line)
{
	static int		i = 0;
	int				j;
	int				k;

	j = 0;
	k = 0;
	if (i == fl->m[1])
		i = 0;
	if (fl->round == 0 && !(fl->map[i] = malloc(sizeof(char) * fl->m[0])))
		return (0);
	while (line[j] != '\0')
	{
		if (PARSMAP(line[j]))
		{
			fl->map[i][k] = line[j];
			++k;
		}
		++j;
	}
	if (k > fl->m[0])
		return (0);
	fl->map[i][k] = '\0';
	++i;
	return (0);
}

void	size_map_piece(char *line, t_fill *fl)
{
	if (line[0] == '$' && ft_strstr(line, "dygouasd.filler") != NULL)
	{
		fl->player = line[10] - 48;
		fl->a = fl->player == 1 ? 'O' : 'X';
		fl->h = fl->player == 1 ? 'X' : 'O';
	}
	if (line[0] >= '0' && line[0] <= '9' && VALID(fl->m[0], fl->m[1]))
		pars_stock_map(fl, line);
	if (line[0] == 'P' && line[1] == 'l')
	{
		fl->m[1] = ft_atoi(&line[8]);
		if (fl->round == 0 && !(fl->map = malloc(sizeof(char*) * fl->m[1] + 1)))
			return ;
		fl->map[fl->m[1]] = NULL;
		fl->m[0] = ft_atoi(&line[8 + len_nbr(fl->m[1])]);
	}
	else if (line[0] == 'P' && line[1] == 'i')
	{
		fl->p[1] = ft_atoi(&line[6]);
		if (GS(fl->p[1]) || !(fl->piece = malloc(sizeof(char*) * fl->p[1] + 1)))
			return ;
		fl->piece[fl->p[1]] = NULL;
		fl->p[0] = ft_atoi(&line[6 + len_nbr(fl->p[1])]);
	}
}

int		read_all(t_fill *fl)
{
	char	*line;
	int		j;

	line = NULL;
	j = 0;
	while (get_next_line(0, &line) > 0)
	{
		size_map_piece(line, fl);
		if (PARSPIECE(line[0]) && VALID(fl->p[0], fl->p[1]))
			fl->piece[j++] = ft_strdup(line);
		if (j == fl->p[1] && VALID(fl->m[0], fl->m[1]) &&
			VALID(fl->p[0], fl->p[1]))
		{
			if (check_all(fl) != -1)
				take_place(fl);
			want_free(fl, 1);
			fl->round = 1;
			j = 0;
		}
		free(line);
		line = NULL;
	}
	return (0);
}

int		main(void)
{
	t_fill		fl;

	fl_init(&fl);
	read_all(&fl);
	want_free(&fl, 2);
	return (0);
}
