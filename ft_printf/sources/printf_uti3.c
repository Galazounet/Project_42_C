/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uti3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:45:00 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 16:38:25 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		count_wcharl(wchar_t *s, t_tool *tl)
{
	int		i;

	i = 0;
	while (*s > 0)
	{
		if (tl->precision > -1 && i + count_wcharlen(*s) > tl->precision)
			return (i);
		i += count_wcharlen(*s);
		s++;
	}
	return (i);
}

int		printf_strwchar(wchar_t *s, t_tool *tl)
{
	int		ret;
	int		save;

	ret = 0;
	save = 0;
	if (tl->precision > -1)
		tl->wcharlen = tl->precision;
	while (*s > 0 && ret < tl->wcharlen)
	{
		expuls_force(tl, 4);
		ret = flag_l_c(&tl->buffer[tl->i_buf], *s);
		save += ret;
		if (save > tl->wcharlen)
			return (save - ret);
		tl->i_buf += ret;
		s++;
	}
	return (save);
}

int		count_b(intmax_t i)
{
	int		len;

	len = 0;
	while (i > 0)
	{
		i = i >> 1;
		len++;
	}
	len = len > 31 ? 63 : 31;
	return (len);
}

int		printf_b(intmax_t i, t_tool *tl)
{
	intmax_t	save;
	int			on;

	on = count_b(i);
	save = on;
	while (on >= 0)
	{
		expuls_force(tl, 2);
		tl->buffer[tl->i_buf++] = (((intmax_t)1 << on) & i) == 0 ? '0' : '1';
		if (on != 0 && (on % 8) == 0)
			tl->buffer[tl->i_buf++] = ' ';
		on--;
	}
	return (save == 63 ? 64 + 7 : 32 + 3);
}
