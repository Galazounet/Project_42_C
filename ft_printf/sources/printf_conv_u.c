/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:34:20 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 08:28:47 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		conv_with_sub(t_tool *tl, int i)
{
	int		ret;

	ret = 0;
	if (tl->precision > 0)
		ret += put_precision(tl, i);
	ret += itoa_base_spec(tl, tl->data.uinteger, i, 1);
	if (tl->champs > 0)
	{
		tl->champs -= ret;
		ret += put_champ(tl);
	}
	return (ret);
}

int		conv_without_sub(t_tool *tl, int len, int sub)
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
	ret += itoa_base_spec(tl, tl->data.uinteger, len, 1);
	return (ret);
}

int		conv_u(t_tool *tl)
{
	int		ret;
	int		i;
	int		sub;

	tl->base = 10;
	ret = 0;
	if (tl->mask & 0x3F)
		my_args(tl, UNSIGNED);
	else
		tl->data.uinteger = va_arg(tl->list, unsigned int);
	i = n_length(tl->data.uinteger, tl->base);
	if (tl->data.uinteger == 0 && tl->precision == 0)
		i = 0;
	if (tl->precision > -1 && tl->mask & OPT_0)
		tl->fill = ' ';
	sub = tl->precision > i ? tl->precision : i;
	if (tl->mask & OPT_NEG)
		ret += conv_with_sub(tl, i);
	else
		ret += conv_without_sub(tl, i, sub);
	++tl->i;
	return (ret);
}

int		conv_big_u(t_tool *tl)
{
	int		ret;
	int		i;
	int		sub;

	tl->base = 10;
	ret = 0;
	if (tl->mask & 0x3C)
		my_args(tl, UNSIGNED);
	else
		tl->data.uinteger = va_arg(tl->list, unsigned long);
	i = n_length(tl->data.uinteger, tl->base);
	if (tl->data.uinteger == 0 && tl->precision == 0)
		i = 0;
	if (tl->precision > -1 && tl->mask & OPT_0)
		tl->fill = ' ';
	sub = tl->precision > i ? tl->precision : i;
	if (tl->mask & OPT_NEG)
		ret += conv_with_sub(tl, i);
	else
		ret += conv_without_sub(tl, i, sub);
	++tl->i;
	return (ret);
}
