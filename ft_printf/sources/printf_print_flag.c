/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:21:25 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 08:26:18 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			put_champ(t_tool *tl)
{
	int		tmp;

	tmp = tl->champs;
	if (tl->precision > 0 || (tl->mask & OPT_NEG))
		tl->fill = ' ';
	while (tmp > 0)
	{
		expuls_force(tl, 1);
		tl->buffer[tl->i_buf] = tl->fill;
		++tl->i_buf;
		--tmp;
	}
	return (tl->champs < 0 ? 0 : tl->champs);
}

int			put_precision(t_tool *tl, int len)
{
	int		tmp;

	tmp = tl->precision - len;
	while (tmp > 0)
	{
		expuls_force(tl, 1);
		tl->buffer[tl->i_buf] = '0';
		++tl->i_buf;
		--tmp;
	}
	return (tmp < 0 ? 0 : tl->precision - len);
}

int			put_space(t_tool *tl)
{
	expuls_force(tl, 1);
	if (tl->data.integer >= 0)
		tl->buffer[tl->i_buf] = ' ';
	++tl->i_buf;
	return (1);
}
