/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_int_indirect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 02:05:53 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 02:08:36 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	verify_int_indirect(t_asm *asmb, t_lexobj *lex, char *value)
{
	int val;

	val = 0;
	if (ft_strlen(value) < 13)
	{
		val = ft_atoi(value);
		if (val > INT_MAX)
			return (pars_error(asmb, \
"Value of `indirect` type too big, expected integer range.", lex, WARNING));
			if (val < INT_MIN)
			return (pars_error(asmb,\
"Value of `indirect` type too small, expected integer range.", lex, WARNING));
			return (SUCCESS);
	}
	else if (value[0] == '-')
		return (pars_error(asmb, \
					"Value of `indirect` type too small.", lex, WARNING));
	else
		return (pars_error(asmb, \
					"Value of `indirect` type too big.", lex, WARNING));
			return (SUCCESS);
}
