/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:29:50 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/25 18:02:21 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		(*g_conv_flag[7])(t_tool *t, int sign) = {
	flag_h,
	flag_hh,
	flag_l,
	flag_ll,
	flag_j,
	flag_z,
	NULL
};

int				my_args(t_tool *tl, int sign)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		if ((tl->mask & 0x3F) & (1 << i))
		{
			g_conv_flag[i](tl, sign);
			return (0);
		}
		++i;
	}
	return (0);
}

void			flag_z(t_tool *t, int is_unsigned)
{
	if (is_unsigned == SIGNED)
		t->data.integer = va_arg(t->list, size_t);
	else
		t->data.uinteger = va_arg(t->list, ssize_t);
}
