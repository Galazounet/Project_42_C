/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:46:00 by dygouasd          #+#    #+#             */
/*   Updated: 2017/12/06 14:33:58 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int		parse_one(t_data *t, char *str)
{
	static char	p[4] = {33, 22, 11, 0};
	int			i;
	int			j;

	i = TETRA_SIZE - 2;
	j = 0;
	while (i >= 0)
	{
		if (str[i] != '.' && str[i] != '#' && (i + 1) % 5 != 0)
			return (-1);
		else if (i != 0 && i + 1 % 5 == 0 && str[i] != '\n')
			return (-1);
		if (str[i] == '\n' && i != TETRA_SIZE - 2)
			++j;
		if (str[i] == '#')
			t->tetras = t->tetras + ((long)1 << (p[j] + i % 5));
		--i;
	}
	if (t->tetras == 0)
		die("error", NULL);
	while ((t->tetras & 0xF) == 0)
		t->tetras = t->tetras >> 11;
	while ((t->tetras & 0x200400801) == 0)
		t->tetras = t->tetras >> 1;
	return (match(t) == -1 || i != -1 ? -1 : 0);
}

int		parse_all(int fd, t_data *t)
{
	int			ret;
	char		str[BUFFSIZE];
	int			i;
	int			j;

	i = 0;
	j = 0;
	ret = read(fd, str, BUFFSIZE);
	if (ret <= 0 || ret > BUFFSIZE - 1)
		die("error", NULL);
	str[ret] = '\0';
	while (i < ret)
	{
		if (parse_one(&t[j], &str[i]) == -1)
			return (-1);
		i = i + TETRA_SIZE;
		++j;
	}
	if (str[ret - 2] != '.' && str[ret - 2] != '#')
		return (-1);
	return (0);
}
