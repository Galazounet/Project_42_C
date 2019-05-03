/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_register.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 02:04:17 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 02:04:48 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	verify_register(t_asm *asmb, t_lexobj *lex, char *str)
{
	int val;

	if (!str)
		return (ERROR);
	val = ft_atol(str);
	if (val < 1 || val > 16)
		return (pars_error(asmb, \
"Unsupported register number, bust be between 1 to 16. (r1-r16)", lex, ERROR));
		return (SUCCESS);
}
