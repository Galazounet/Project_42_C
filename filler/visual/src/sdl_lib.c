/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:58:17 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 12:58:19 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int			fillmap(char *line, char **map, int size_max)
{
	static int i;

	ft_strcpy(map[i], &line[4]);
	if (i == size_max - 1)
		i = 0;
	else
		++i;
	return (0);
}

int			lennbr(int n)
{
	int ret;

	ret = 0;
	while (n / 10 > 0)
	{
		ret += 1;
		n = n / 10;
	}
	return (ret + 1);
}
