/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_arg_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:29:36 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:03:01 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			push_arg_name(t_asm *asmb, char *name)
{
	t_fname		*nm;
	t_fname		*tmp;

	if (!name || !asmb)
		return ;
	nm = NULL;
	if (!(nm = (t_fname*)malloc(sizeof(t_fname))))
		return ;
	nm->name = ft_strdup(name);
	nm->next = NULL;
	if (!(asmb->arg_name))
		asmb->arg_name = nm;
	else
	{
		tmp = asmb->arg_name;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = nm;
	}
	asmb->arg_name_len++;
}
