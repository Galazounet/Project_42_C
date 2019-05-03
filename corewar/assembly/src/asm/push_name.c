/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:31:46 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:01:51 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			push_name(t_asm *asmb, char *name)
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
	if (!(asmb->fname))
		asmb->fname = nm;
	else
	{
		tmp = asmb->fname;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = nm;
	}
	asmb->fname_len++;
}
