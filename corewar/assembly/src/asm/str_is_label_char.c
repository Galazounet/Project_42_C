/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_label_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:33:45 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:02:00 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		str_is_label_char(char *str)
{
	int	i;
	int	len;

	if (!str)
		return (ERROR);
	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (is_labelchar(str[i]) != 1)
			return (ERROR);
		i++;
	}
	return ((len == 0) ? ERROR : SUCCESS);
}
