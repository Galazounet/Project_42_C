/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:47:37 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 09:14:03 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		conv_c_with_sub(t_tool *tl)
{
	int		ret;

	ret = 1;
	if (tl->mask & OPT_L)
	{
		ret = flag_l_c(&tl->buffer[tl->i_buf], tl->data.wildcharc);
		tl->i_buf += ret;
	}
	else
		tl->buffer[tl->i_buf++] = tl->data.uinteger;
	if (tl->champs > 0)
	{
		tl->champs -= tl->precision > ret ? tl->precision : ret;
		ret += put_champ(tl);
	}
	return (ret);
}

int		conv_c_without_sub(t_tool *tl, int i)
{
	int		ret;
	int		save;

	ret = 1;
	if (tl->precision > i)
		tl->precision = i;
	if (tl->champs > 0)
	{
		tl->champs -= i;
		ret += put_champ(tl);
	}
	if (tl->mask & OPT_L || tl->format[tl->i] == 'C')
	{
		save = flag_l_c(&tl->buffer[tl->i_buf], tl->data.wildcharc);
		ret += save - 1;
		tl->i_buf += save;
	}
	else
		tl->buffer[tl->i_buf++] = tl->data.uinteger;
	return (ret);
}

int		conv_c(t_tool *tl)
{
	int		ret;

	ret = 0;
	if (tl->mask & OPT_L)
		return (conv_big_c(tl));
	else
		tl->data.uinteger = va_arg(tl->list, int);
	expuls_force(tl, 1);
	if (tl->mask & OPT_NEG)
		ret += conv_c_with_sub(tl);
	else
		ret += conv_c_without_sub(tl, 1);
	tl->i++;
	return (ret);
}

int		conv_big_c(t_tool *tl)
{
	int		ret;

	ret = 0;
	tl->data.wildcharc = va_arg(tl->list, wchar_t);
	expuls_force(tl, 4);
	if (tl->mask & OPT_NEG)
		ret += conv_c_with_sub(tl);
	else
		ret += conv_c_without_sub(tl, count_wcharlen(tl->data.wildcharc));
	tl->i++;
	return (ret);
}
