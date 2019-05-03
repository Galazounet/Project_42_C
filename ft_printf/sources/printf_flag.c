/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:10:04 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 07:46:21 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		set_flag(t_tool *tl)
{
	if (tl->format[tl->i] == 'j')
		tl->mask = (tl->mask & 0x1FC0) | OPT_J;
	else if (tl->format[tl->i] == 'z')
		tl->mask = (tl->mask & 0x1FC0) | OPT_Z;
	else if (tl->format[tl->i] == 'h' && (tl->mask & 0x30) == 0)
	{
		if ((tl->mask & OPT_H) && (tl->mask & OPT_HH) == 0)
			tl->mask = (tl->mask & 0x1FC0) | OPT_HH;
		else
			tl->mask = (tl->mask & 0x1FC0) | OPT_H;
	}
	else if (tl->format[tl->i] == 'l' && (tl->mask & 0x30) == 0)
	{
		if ((tl->mask & OPT_L) && (tl->mask & OPT_LL) == 0)
			tl->mask = (tl->mask & 0x1FC0) | OPT_LL;
		else
			tl->mask = (tl->mask & 0x1FC0) | OPT_L;
	}
	++tl->i;
	return (0);
}
