/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:26:52 by afrangio          #+#    #+#             */
/*   Updated: 2018/05/04 04:05:45 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_capslock(int capslock)
{
	char	*digits;

	digits = ft_memalloc(sizeof(char) * 16);
	if (!digits)
		return (NULL);
	if (capslock)
		ft_strncpy(digits, "0123456789ABCDEF", 16);
	else
		ft_strncpy(digits, "0123456789abcdef", 16);
	return (digits);
}

char			*ft_itoa_base(intmax_t n, int b, int capslock)
{
	int				neg;
	intmax_t		i;
	char			*digits;
	char			*str;

	digits = ft_capslock(capslock);
	neg = -1 * (n >> 31);
	n = (neg ? -n : n);
	i = ft_log(n, b) + 1 + neg;
	str = (char*)ft_memalloc((--i - 1) * sizeof(char));
	if (!str)
		return (str);
	str[i--] = '\0';
	if (n == 0)
		return (ft_strcpy(str, "0"));
	while (n > 0)
	{
		str[i--] = digits[n % b];
		n = n / b;
	}
	free(digits);
	str[0] = (neg ? '-' : str[0]);
	return (str);
}

char			*ft_uitoa_base(uintmax_t n, int b, int capslock)
{
	int		i;
	char	*digits;
	char	*str;

	digits = ft_capslock(capslock);
	i = ft_ulog(n, b) + 1;
	str = ft_memalloc((--i - 1) * sizeof(char));
	if (!str)
		return (str);
	str[i--] = '\0';
	while (n > 0)
	{
		str[i--] = digits[n % b];
		n = n / b;
	}
	free(digits);
	return (str);
}
