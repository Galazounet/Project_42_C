/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_numer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:34:11 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:01:59 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		str_is_numer(char *str)
{
	int	i;
	int	len;

	if (!str)
		return (ERROR);
	i = 0;
	len = ft_strlen(str);
	if (str[i] == '-')
	{
		i++;
		if (len == 1)
			return (ERROR);
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (ERROR);
		i++;
	}
	return ((len == 0) ? ERROR : SUCCESS);
}
