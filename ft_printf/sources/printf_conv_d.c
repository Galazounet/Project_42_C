/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:34:10 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 10:04:23 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		conv_d_with_sub(t_tool *tl, int i)
{
	int		ret;

	ret = 0;
	if (tl->sign != 0)
		ret += put_neg(tl);
	if (tl->precision > 0)
		ret += put_precision(tl, i);
	ret += itoa_base_spec(tl, tl->data.integer, i, 0);
	if (tl->champs > 0)
	{
		tl->champs -= ret;
		ret += put_champ(tl);
	}
	return (ret);
}

int		conv_d_without_sub(t_tool *tl, int len, int sub)
{
	int		ret;

	ret = 0;
	if (tl->champs > 0)
	{
		tl->champs -= sub;
		if (tl->fill == ' ')
		{
			ret += put_champ(tl);
			if (tl->sign != 0)
				ret += put_neg(tl);
		}
		else if (tl->fill == '0')
		{
			if (tl->sign != 0)
				ret += put_neg(tl);
			ret += put_champ(tl);
		}
	}
	else if (tl->sign != 0)
		ret += put_neg(tl);
	if (tl->precision > 0)
		ret += put_precision(tl, len);
	ret += itoa_base_spec(tl, tl->data.integer, len, 0);
	return (ret);
}

int		conv_d(t_tool *tl)
{
	int		ret;
	int		i;
	int		sub;

	tl->base = 10;
	ret = 0;
	if (tl->mask & 0x3F)
		my_args(tl, SIGNED);
	else
		tl->data.integer = va_arg(tl->list, int);
	i = n_length(ABS(tl->data.integer), tl->base);
	if (tl->data.integer == 0 && tl->precision == 0)
		i = 0;
	if (tl->precision > -1 && tl->mask & OPT_0)
		tl->fill = ' ';
	if (tl->data.integer < 0)
		tl->sign = '-';
	sub = tl->precision > i ? tl->precision : i;
	sub += tl->sign == 0 ? 0 : 1;
	if (tl->mask & OPT_NEG)
		ret += conv_d_with_sub(tl, i);
	else
		ret += conv_d_without_sub(tl, i, sub);
	++tl->i;
	return (ret);
}

int		conv_big_d(t_tool *tl)
{
	int		ret;
	int		i;
	int		sub;

	tl->base = 10;
	ret = 0;
	if (tl->mask & 0x3C)
		my_args(tl, SIGNED);
	else
		tl->data.integer = va_arg(tl->list, long);
	i = n_length(ABS(tl->data.integer), tl->base);
	if (tl->data.integer == 0 && tl->precision == 0)
		i = 0;
	if (tl->precision > -1 && tl->mask & OPT_0)
		tl->fill = ' ';
	if (tl->data.integer < 0)
		tl->sign = '-';
	sub = tl->precision > i ? tl->precision : i;
	sub += tl->sign == 0 ? 0 : 1;
	if (tl->mask & OPT_NEG)
		ret += conv_d_with_sub(tl, i);
	else
		ret += conv_d_without_sub(tl, i, sub);
	++tl->i;
	return (ret);
}
