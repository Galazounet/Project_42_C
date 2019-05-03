/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:42:25 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:02:02 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_label(char *str)
{
	int	i;

	if (!str)
		return (ERROR);
	i = 0;
	while (str[i] && is_lex_spearator(str[i]) == 0)
		i++;
	if (str[i] && str[i] == LEBEL_LIMIT_CHAR)
		return (SUCCESS);
	return (ERROR);
}
