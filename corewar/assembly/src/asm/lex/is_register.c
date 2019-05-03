/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_register.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:44:55 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:41 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_register(char *str)
{
	int i;

	if (!str)
		return (ERROR);
	i = 0;
	if (str[i] == 'r')
		i++;
	else
		return (ERROR);
	while (str[i] && is_lex_spearator(str[i]) == 0)
	{
		if (ft_isdigit(str[i]) != 1)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
