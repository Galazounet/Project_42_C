/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:34:18 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 10:29:15 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		conv_s_with_sub(t_tool *tl, int i)
{
	int		ret;

	ret = 0;
	if (tl->data.wildchars == NULL || tl->data.string == NULL)
		ret += printf_strnull(tl);
	else if (tl->mask & OPT_L || tl->format[tl->i] == 'S')
		ret += printf_strwchar(tl->data.wildchars, tl);
	else
		ret += printf_str(tl);
	if (tl->precision > i)
		tl->precision = i;
	if (tl->champs > 0)
	{
		tl->champs -= ret;
		ret += put_champ(tl);
	}
	return (ret);
}

int		conv_s_without_sub(t_tool *tl, int i)
{
	int		ret;

	ret = 0;
	if (tl->precision > i)
		tl->precision = i;
	if (tl->champs > 0)
	{
		tl->champs -= i;
		ret += put_champ(tl);
	}
	if (tl->data.wildchars == NULL || tl->data.string == NULL)
		ret += printf_strnull(tl);
	else if (tl->mask & OPT_L || tl->format[tl->i] == 'S')
		ret += printf_strwchar(tl->data.wildchars, tl);
	else
		ret += printf_str(tl);
	return (ret);
}

int		conv_s(t_tool *tl)
{
	int		ret;
	int		len;

	ret = 0;
	if (tl->mask & OPT_L)
		return (conv_big_s(tl));
	else
		tl->data.string = va_arg(tl->list, char*);
	len = tl->data.string == NULL ? 6 : ft_strlen(tl->data.string);
	if (tl->precision > -1 && tl->precision < len)
		len = tl->precision;
	if (tl->mask & OPT_NEG)
		ret += conv_s_with_sub(tl, len);
	else
		ret += conv_s_without_sub(tl, len);
	tl->i++;
	return (ret);
}

int		conv_big_s(t_tool *tl)
{
	int		ret;
	int		len;

	ret = 0;
	tl->data.wildchars = va_arg(tl->list, wchar_t*);
	len = tl->data.wildchars == NULL ? 6 : count_wcharl(tl->data.wildchars, tl);
	if (tl->precision > -1 && tl->precision < len)
		len = tl->precision;
	tl->wcharlen = len;
	if (tl->mask & OPT_NEG)
		ret += conv_s_with_sub(tl, len);
	else
		ret += conv_s_without_sub(tl, len);
	tl->i++;
	return (ret);
}
