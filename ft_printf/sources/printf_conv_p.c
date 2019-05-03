/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:34:16 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 15:21:28 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		put_ash_p(t_tool *tl)
{
	expuls_force(tl, 2);
	tl->buffer[tl->i_buf++] = '0';
	tl->buffer[tl->i_buf++] = 'x';
	return (2);
}

int		conv_p_with_sub(t_tool *tl, int i)
{
	int		ret;

	ret = 0;
	ret += put_ash_p(tl);
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

int		conv_p_without_sub(t_tool *tl, int len, int sub)
{
	int		ret;

	ret = 0;
	if (tl->champs > 0)
	{
		tl->champs -= sub + 2;
		ret += put_champ(tl);
	}
	ret += put_ash_p(tl);
	if (tl->precision > 0)
		ret += put_precision(tl, len);
	ret += itoa_base_spec(tl, tl->data.uinteger, len, 1);
	return (ret);
}

int		conv_p(t_tool *tl)
{
	int		ret;
	int		i;
	int		sub;

	tl->base = 16;
	ret = 0;
	tl->data.uinteger = (long)va_arg(tl->list, void*);
	i = n_length(ABS(tl->data.uinteger), tl->base);
	if (tl->data.uinteger == 0 && tl->precision == 0)
		i = 0;
	if (tl->precision > -1 && tl->mask & OPT_0)
		tl->fill = ' ';
	sub = tl->precision > i ? tl->precision : i;
	if (tl->mask & OPT_NEG || tl->fill == '0')
		ret += conv_p_with_sub(tl, i);
	else
		ret += conv_p_without_sub(tl, i, sub);
	++tl->i;
	return (ret);
}
