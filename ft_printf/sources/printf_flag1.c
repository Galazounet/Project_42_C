/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:18:31 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 08:03:09 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		set_hashtag(t_tool *tl)
{
	tl->mask |= OPT_ASH;
	while (tl->format[tl->i] == '#')
		++tl->i;
	return (0);
}

int		set_zero(t_tool *tl)
{
	if (tl->precision == -1 && ((tl->mask & OPT_NEG) == 0))
	{
		tl->mask |= OPT_0;
		tl->fill = '0';
	}
	while (tl->format[tl->i] == '0')
		++tl->i;
	return (0);
}

int		set_sub(t_tool *tl)
{
	tl->mask |= OPT_NEG;
	while (tl->format[tl->i] == '-')
		++tl->i;
	return (0);
}

int		set_add(t_tool *tl)
{
	tl->mask |= OPT_POS;
	tl->sign = '+';
	while (tl->format[tl->i] == '+')
		++tl->i;
	return (0);
}

int		set_space(t_tool *tl)
{
	if ((tl->mask & OPT_POS) == 0)
	{
		tl->mask |= OPT_SPACE;
		tl->sign = ' ';
	}
	while (tl->format[tl->i] == ' ')
		++tl->i;
	return (0);
}
