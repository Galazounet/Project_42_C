/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_all_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:41:37 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/25 17:58:06 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			flag_h(t_tool *tl, int is_unsigned)
{
	if (is_unsigned == SIGNED)
		tl->data.integer = (short)va_arg(tl->list, intmax_t);
	else
		tl->data.uinteger = (unsigned short)va_arg(tl->list, unsigned int);
}

void			flag_l(t_tool *tl, int is_unsigned)
{
	if (is_unsigned == SIGNED)
		tl->data.integer = va_arg(tl->list, long);
	else
		tl->data.uinteger = va_arg(tl->list, unsigned long);
}

void			flag_hh(t_tool *tl, int is_unsigned)
{
	if (is_unsigned == SIGNED)
		tl->data.integer = (char)va_arg(tl->list, intmax_t);
	else
		tl->data.uinteger = (unsigned char)va_arg(tl->list, uintmax_t);
}

void			flag_ll(t_tool *tl, int is_unsigned)
{
	if (is_unsigned == SIGNED)
		tl->data.integer = va_arg(tl->list, long long);
	else
		tl->data.uinteger = va_arg(tl->list, unsigned long long);
}

void			flag_j(t_tool *tl, int is_unsigned)
{
	if (is_unsigned == SIGNED)
		tl->data.integer = va_arg(tl->list, intmax_t);
	else
		tl->data.uinteger = va_arg(tl->list, uintmax_t);
}
