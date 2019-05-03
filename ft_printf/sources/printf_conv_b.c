/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 11:23:21 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 15:22:14 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		conv_b_with_sub(t_tool *tl, int i)
{
	int		ret;

	ret = 0;
	if (tl->precision > 0)
		ret += put_precision(tl, i);
	ret += printf_b(tl->data.integer, tl);
	if (tl->champs > 0)
	{
		tl->champs -= ret;
		ret += put_champ(tl);
	}
	return (ret);
}

int		conv_b_without_sub(t_tool *tl, int len, int sub)
{
	int		ret;

	ret = 0;
	if (tl->champs > 0)
	{
		tl->champs -= sub;
		ret += put_champ(tl);
	}
	if (tl->precision > 0)
		ret += put_precision(tl, len);
	ret += printf_b(tl->data.integer, tl);
	return (ret);
}

int		conv_b(t_tool *tl)
{
	int		ret;
	int		i;
	int		sub;

	tl->base = 10;
	ret = 0;
	tl->data.integer = va_arg(tl->list, intmax_t);
	i = count_b(tl->data.integer) == 31 ? 35 : 71;
	if (tl->data.uinteger == 0 && tl->precision == 0)
		i = 0;
	if (tl->precision > -1 && tl->mask & OPT_0)
		tl->fill = ' ';
	sub = tl->precision > i ? tl->precision : i;
	if (tl->mask & OPT_NEG)
		ret += conv_b_with_sub(tl, i);
	else
		ret += conv_b_without_sub(tl, i, sub);
	++tl->i;
	return (ret);
}
