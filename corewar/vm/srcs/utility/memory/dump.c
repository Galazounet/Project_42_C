/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:55:39 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/26 21:22:07 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static unsigned	n_length(intmax_t n, int base)
{
	unsigned		i;

	i = 0;
	if (n == 0)
		++i;
	while (n != 0)
	{
		n = n / (intmax_t)base;
		++i;
	}
	return (i);
}

static char		*itoa_base_spec(char *str, intmax_t n)
{
	int					i;
	unsigned			len;
	char				*b;
	static char			*basex = "0123456789abcdef";

	n = n < 0 ? n * -1 : n;
	i = 1;
	b = basex;
	len = n_length(n, 16);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[len - (unsigned)i] = b[n % 16];
		n = n / 16;
		++i;
	}
	str[len] = '\0';
	return (str);
}

static void		colors(unsigned color)
{
	if (color == 1)
		ft_putstr(ANSI_COLOR_BRIGHT_GREEN);
	else if (color == 2)
		ft_putstr(ANSI_COLOR_BRIGHT_BLUE);
	else if (color == 3)
		ft_putstr(ANSI_COLOR_BRIGHT_RED);
	else if (color == 4)
		ft_putstr(ANSI_COLOR_BRIGHT_YELLOW);
	else if (color == 10)
		ft_putstr(ANSI_BG_GREEN);
	else if (color == 20)
		ft_putstr(ANSI_BG_BLUE);
	else if (color == 30)
		ft_putstr(ANSI_BG_RED);
	else if (color == 40)
		ft_putstr(ANSI_BG_YELLOW);
	else
		ft_putstr(ANSI_COLOR_RESET);
}

int				dump(t_cv *env)
{
	char			*str;
	unsigned		i;
	unsigned		j;

	i = 0;
	str = NULL;
	while (i < MEM_SIZE)
	{
		colors(env->vm.parent[i]);
		if (i % 64 == 0 && i != 0)
			ft_putstr(" \n");
		if ((j = ((env->vm.memory[i]))) < 16)
			ft_putstr("0");
		ft_putstr(str = itoa_base_spec(str, env->vm.memory[i]));
		free(str);
		str = NULL;
		if ((i + 1) % 64 != 0)
			ft_putstr(" ");
		++i;
	}
	ft_putendl("\n");
	return (SUCCESS);
}
