/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:34:14 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 09:45:12 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		put_ash_o(t_tool *tl)
{
	expuls_force(tl, 1);
	tl->buffer[tl->i_buf++] = '0';
	return (1);
}

int		conv_o_with_sub(t_tool *tl, int i)
{
	int		ret;

	ret = 0;
	if (tl->mask & OPT_ASH && tl->data.uinteger != 0)
		ret += put_ash_o(tl);
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

int		conv_o_without_sub(t_tool *tl, int len, int sub)
{
	int		ret;

	ret = 0;
	if (tl->champs > 0)
	{
		tl->champs -= sub;
		if (tl->fill == ' ')
		{
			ret += put_champ(tl);
			if (tl->mask & OPT_ASH && (tl->data.uinteger != 0 || len == 0))
				ret += put_ash_o(tl);
		}
		else if (tl->fill == '0')
		{
			if (tl->mask & OPT_ASH && (tl->data.uinteger != 0 || len == 0))
				ret += put_ash_o(tl);
			ret += put_champ(tl);
		}
	}
	else if (tl->mask & OPT_ASH && (tl->data.uinteger != 0 || len == 0))
		ret += put_ash_o(tl);
	if (tl->precision > 0)
		ret += put_precision(tl, (tl->mask & OPT_ASH) ? len + 1 : len);
	ret += itoa_base_spec(tl, tl->data.uinteger, len, 1);
	return (ret);
}

int		conv_o(t_tool *tl)
{
	int		ret;
	int		i;
	int		sub;

	tl->base = 8;
	ret = 0;
	if (tl->mask & 0x3F)
		my_args(tl, UNSIGNED);
	else
		tl->data.uinteger = va_arg(tl->list, unsigned int);
	i = n_length(ABS(tl->data.uinteger), tl->base);
	if (tl->data.uinteger == 0 && tl->precision == 0)
		i = 0;
	if (tl->precision > -1 && tl->mask & OPT_0)
		tl->fill = ' ';
	sub = tl->precision > i ? tl->precision : i;
	sub += (tl->mask & OPT_ASH) == 0 ? 0 : 1;
	if (tl->mask & OPT_NEG)
		ret += conv_o_with_sub(tl, i);
	else
		ret += conv_o_without_sub(tl, i, sub);
	++tl->i;
	return (ret);
}

int		conv_big_o(t_tool *tl)
{
	int		ret;
	int		i;
	int		sub;

	tl->base = 8;
	ret = 0;
	if (tl->mask & 0x3C)
		my_args(tl, UNSIGNED);
	else
		tl->data.uinteger = va_arg(tl->list, unsigned long);
	i = n_length(ABS(tl->data.uinteger), tl->base);
	if (tl->data.uinteger == 0 && tl->precision == 0)
		i = 0;
	if (tl->precision > -1 && tl->mask & OPT_0)
		tl->fill = ' ';
	sub = tl->precision > i ? tl->precision : i;
	sub += (tl->mask & OPT_ASH) == 0 ? 0 : 1;
	if (tl->mask & OPT_NEG)
		ret += conv_o_with_sub(tl, i);
	else
		ret += conv_o_without_sub(tl, i, sub);
	++tl->i;
	return (ret);
}
