/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:34:22 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 08:29:04 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		put_ash(t_tool *tl)
{
	expuls_force(tl, 2);
	tl->buffer[tl->i_buf++] = '0';
	if (tl->format[tl->i] == 'x')
		tl->buffer[tl->i_buf++] = 'x';
	else
		tl->buffer[tl->i_buf++] = 'X';
	return (2);
}

int		conv_x_with_sub(t_tool *tl, int i)
{
	int		ret;

	ret = 0;
	if (tl->mask & OPT_ASH && tl->data.uinteger != 0)
		ret += put_ash(tl);
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

int		conv_x_without_sub(t_tool *tl, int len, int sub)
{
	int		ret;

	ret = 0;
	if (tl->champs > 0)
	{
		tl->champs -= sub;
		if (tl->fill == ' ')
		{
			ret += put_champ(tl);
			if (tl->mask & OPT_ASH && tl->data.uinteger != 0)
				ret += put_ash(tl);
		}
		else if (tl->fill == '0')
		{
			if (tl->mask & OPT_ASH && tl->data.uinteger != 0)
				ret += put_ash(tl);
			ret += put_champ(tl);
		}
	}
	else if (tl->mask & OPT_ASH && tl->data.uinteger != 0)
		ret += put_ash(tl);
	if (tl->precision > 0)
		ret += put_precision(tl, len);
	ret += itoa_base_spec(tl, tl->data.uinteger, len, 1);
	return (ret);
}

int		conv_x(t_tool *tl)
{
	int		ret;
	int		i;
	int		sub;

	tl->base = 16;
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
	sub += (tl->mask & OPT_ASH) == 0 ? 0 : 2;
	if (tl->mask & OPT_NEG)
		ret += conv_x_with_sub(tl, i);
	else
		ret += conv_x_without_sub(tl, i, sub);
	++tl->i;
	return (ret);
}

int		conv_big_x(t_tool *tl)
{
	int		ret;
	int		i;
	int		sub;

	tl->base = 16;
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
	sub += (tl->mask & OPT_ASH) == 0 ? 0 : 2;
	if (tl->mask & OPT_NEG)
		ret += conv_x_with_sub(tl, i);
	else
		ret += conv_x_without_sub(tl, i, sub);
	++tl->i;
	return (ret);
}
