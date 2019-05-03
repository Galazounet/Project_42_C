/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_indirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:29:01 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:39 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_indirect(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ERROR);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && is_lex_spearator(str[i]) == 0)
	{
		if (ft_isdigit(str[i]) == 0)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
