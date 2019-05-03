/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uti2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:54:47 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 10:08:16 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	expuls_force(t_tool *tl, int next)
{
	if (tl->i_buf + next > BUFF_SIZE)
	{
		write(1, tl->buffer, tl->i_buf);
		tl->i_buf = 0;
	}
}

int		printf_strnull(t_tool *tl)
{
	int			ret;
	static char *str = "(null)";

	ret = 0;
	if (tl->precision > -1)
	{
		while (str[ret] != '\0' && ret < tl->precision)
		{
			expuls_force(tl, 1);
			tl->buffer[tl->i_buf++] = str[ret++];
		}
	}
	else
	{
		while (str[ret] != '\0')
		{
			expuls_force(tl, 1);
			tl->buffer[tl->i_buf++] = str[ret++];
		}
	}
	return (ret);
}

int		printf_str(t_tool *tl)
{
	int		ret;

	ret = 0;
	if (tl->precision > -1)
	{
		while (tl->data.string[ret] != '\0' && ret < tl->precision)
		{
			expuls_force(tl, 1);
			tl->buffer[tl->i_buf++] = tl->data.string[ret++];
		}
	}
	else
	{
		while (tl->data.string[ret] != '\0')
		{
			expuls_force(tl, 1);
			tl->buffer[tl->i_buf++] = tl->data.string[ret++];
		}
	}
	return (ret);
}

int		flag_l_c(char *s, wchar_t i)
{
	if (i <= 0x7F)
		s[0] = i & 0x7F;
	else if (i <= 0x7FF)
	{
		s[0] = ((i & 0x7F0) >> 6) + 0xC0;
		s[1] = (i & 0x3F) + 0x80;
		return (2);
	}
	else if (i <= 0xFFFF)
	{
		s[0] = ((i & 0xF000) >> 12) + 0xE0;
		s[1] = ((i & 0xFC0) >> 6) + 0x80;
		s[2] = (i & 0x3F) + 0x80;
		return (3);
	}
	else if (i <= 0x10FFFF)
	{
		s[0] = ((i & 0x1C0000) >> 18) + 0xF0;
		s[1] = ((i & 0x3F000) >> 12) + 0x80;
		s[2] = ((i & 0xFC0) >> 6) + 0x80;
		s[3] = (i & 0x3F) + 0x80;
		return (4);
	}
	return (1);
}

int		count_wcharlen(wchar_t i)
{
	if (i <= 0x7F)
		return (1);
	if (i <= 0x7FF)
		return (2);
	else if (i <= 0xFFFF)
		return (3);
	else if (i <= 0x10FFFF)
		return (4);
	return (0);
}
