/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_champ_preci.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:19:11 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 07:39:36 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		set_point(t_tool *tl)
{
	tl->mask |= OPT_PRECI;
	while (tl->format[tl->i] == '.')
		++tl->i;
	tl->precision = my_atoi(tl);
	tl->mask |= OPT_PRECI;
	return (0);
}

int		set_field(t_tool *tl)
{
	if (!(tl->format[tl->i] >= '1' && tl->format[tl->i] <= '9'))
		return (-1);
	tl->champs = my_atoi(tl);
	tl->mask |= OPT_FIELD;
	return (0);
}
