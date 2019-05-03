/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lexobj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:28:56 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 00:29:03 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_lexobj	*get_next_lexobj(t_lexobj *lex)
{
	if (!lex)
		return (NULL);
	if (lex->next_obj)
		return (lex->next_obj);
	else
		return (lex->next_line);
}
