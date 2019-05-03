/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uti1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:37:43 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 10:05:44 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		write_buff(t_tool *tl)
{
	expuls_force(tl, 1);
	write(STDOUT_FILENO, tl->buffer, tl->i_buf);
	tl->i_buf = 0;
	return (0);
}

int		put_neg(t_tool *tl)
{
	expuls_force(tl, 1);
	tl->buffer[tl->i_buf] = tl->sign;
	++tl->i_buf;
	return (1);
}

int		n_length(unsigned long long n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
		++i;
	while (n != 0)
	{
		n = n / base;
		++i;
	}
	return (i);
}

int		my_atoi(t_tool *tl)
{
	int		j;

	j = 0;
	while (tl->format[tl->i] >= '0' && tl->format[tl->i] <= '9')
	{
		j = j * 10 + (tl->format[tl->i] - 48);
		++tl->i;
	}
	return (j);
}

int		itoa_base_spec(t_tool *tl, intmax_t n, int len, int un)
{
	int					i;
	unsigned long long	nm;
	char				*b;
	static char			*basex = "0123456789abcdef";
	static char			*base_big_x = "0123456789ABCDEF";

	b = tl->format[tl->i] != 'X' ? basex : base_big_x;
	nm = n < 0 && un == 0 ? n * -1 : n;
	i = 1;
	expuls_force(tl, len);
	tl->i_buf += len;
	if (nm == 0 && len != 0)
	{
		tl->buffer[tl->i_buf - 1] = '0';
		return (len);
	}
	while (nm != 0)
	{
		tl->buffer[tl->i_buf - i] = b[nm % tl->base];
		nm = nm / tl->base;
		++i;
	}
	return (len);
}
