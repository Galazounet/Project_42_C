/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_int_direct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 01:48:52 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 01:50:41 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	verify_int_direct(t_asm *asmb, t_lexobj *lex, char *value)
{
	int val;

	val = 0;
	if (ft_strlen(value) < 13)
	{
		val = ft_atoi(value);
		if (val > INT_MAX)
			return (pars_error(asmb,\
	"Value of `direct` type too big, surpasses integer range.", lex, WARNING));
			if (val < INT_MIN)
			return (pars_error(asmb,\
"Value of `direct` type too small, surpasses integer range.", lex, WARNING));
			return (SUCCESS);
	}
	else if (value[0] == '-')
		return (pars_error(asmb,\
					"Value of `direct` type too small.", lex, WARNING));
	else
		return (pars_error(asmb,\
					"Value of `direct` type too big.", lex, WARNING));
			return (SUCCESS);
}
