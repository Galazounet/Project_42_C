/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv_noth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 08:42:36 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 09:18:05 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		put_print_no(t_tool *tl)
{
	expuls_force(tl, 1);
	tl->buffer[tl->i_buf++] = tl->format[tl->i];
	return (1);
}

int		conv_no_with_sub(t_tool *tl, int i)
{
	int		ret;

	ret = 0;
	if (tl->precision > 0)
		ret += put_precision(tl, i);
	ret += put_print_no(tl);
	if (tl->champs > 0)
	{
		tl->champs -= tl->precision > ret ? tl->precision : ret;
		ret += put_champ(tl);
	}
	return (ret);
}

int		conv_no_without_sub(t_tool *tl, int len)
{
	int		ret;

	ret = 0;
	if (tl->precision > len)
		tl->precision = len;
	if (tl->champs > 0)
	{
		tl->champs -= len;
		ret += put_champ(tl);
	}
	if (tl->precision > 0)
		ret += put_precision(tl, len);
	ret += put_print_no(tl);
	return (ret);
}

int		conv_nothing(t_tool *tl)
{
	int		ret;

	ret = 0;
	if (tl->format[tl->i] != '\0')
	{
		if (tl->mask & OPT_NEG)
			ret += conv_no_with_sub(tl, 1);
		else
			ret += conv_no_without_sub(tl, 1);
		tl->i++;
	}
	return (ret);
}
