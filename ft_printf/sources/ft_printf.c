/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:23:13 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 12:47:55 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_conv	g_conv[17] = {
	{'x', conv_x},
	{'X', conv_big_x},
	{'d', conv_d},
	{'D', conv_big_d},
	{'i', conv_i},
	{'o', conv_o},
	{'O', conv_big_o},
	{'u', conv_u},
	{'U', conv_big_u},
	{'p', conv_p},
	{'s', conv_s},
	{'S', conv_big_s},
	{'c', conv_c},
	{'C', conv_big_c},
	{'b', conv_b},
	{'%', conv_percent},
	{'\0', conv_nothing}
};

t_opts	g_option[13] = {
	{'h', set_flag},
	{'l', set_flag},
	{'j', set_flag},
	{'z', set_flag},
	{'#', set_hashtag},
	{'0', set_zero},
	{'-', set_sub},
	{'+', set_add},
	{' ', set_space},
	{'.', set_point},
	{'\0', set_field}
};

int		printf_string(t_tool *tl)
{
	int	ret;

	ret = 0;
	while (tl->format[tl->i] != '%' && tl->format[tl->i] != '\0')
	{
		expuls_force(tl, 1);
		tl->buffer[tl->i_buf++] = tl->format[tl->i++];
		if (tl->i_buf >= BUFF_SIZE)
			write_buff(tl);
		++ret;
	}
	if (tl->format[tl->i] == '\0')
		write_buff(tl);
	return (ret);
}

int		do_conversion(t_tool *tl)
{
	static char		*conv = "xXdDioOuUpsScCb%";
	int				i;
	int				ret;

	i = 0;
	while (conv[i] != '\0')
	{
		if (conv[i] == tl->format[tl->i])
			break ;
		++i;
	}
	ret = g_conv[i].func(tl);
	return (ret);
}

int		printf_conv(t_tool *tl)
{
	static char		*opt = "hljz#0-+ .";
	int				i;

	i = 0;
	while (i < 10)
	{
		i = 0;
		while (opt[i] != '\0')
		{
			if (opt[i] == tl->format[tl->i])
			{
				g_option[i].func(tl);
				break ;
			}
			++i;
		}
		if (ISDIGIT(tl->format[tl->i]))
		{
			g_option[i].func(tl);
			i = 0;
		}
	}
	return (do_conversion(tl));
}

void	init(t_tool *tl)
{
	tl->sign = 0;
	tl->fill = ' ';
	tl->mask = 0;
	tl->champs = -1;
	tl->precision = -1;
}

int		ft_printf(const char *format, ...)
{
	t_tool			tl;
	unsigned int	ret;

	if (!format)
		return (0);
	ret = 0;
	init(&tl);
	va_start(tl.list, format);
	tl.format = format;
	tl.i = 0;
	tl.i_buf = 0;
	while (tl.format[tl.i])
	{
		if (tl.format[tl.i] == '%')
		{
			++tl.i;
			ret += printf_conv(&tl);
			init(&tl);
		}
		ret += printf_string(&tl);
	}
	return (ret);
}
