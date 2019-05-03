/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_lexobj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 01:11:41 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 01:11:50 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars	*pars_lexobj(t_asm *asmb, char **tab, t_lexobj *lex)
{
	t_pars		*pars;
	t_lexobj	*lexic;

	lexic = lex;
	if ((pars = pars_new(lex)) == NULL)
		return (NULL);
	if (pars_header(asmb, tab, &(lexic), pars) == ERROR)
	{
		free_pars(&pars);
		return (NULL);
	}
	if (pars_instruction(asmb, lexic, pars) == ERROR)
	{
		free_pars(&pars);
		return (NULL);
	}
	return (pars);
}
