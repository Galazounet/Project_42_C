/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexobj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:28:14 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:02:03 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_lexobj(t_lexobj **lex)
{
	if (!lex || !*lex)
		return ;
	if ((*lex)->value)
		ft_memdel((void*)&((*lex)->value));
	ft_memdel((void*)&lex);
}
