/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:21:38 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:00:34 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_fname(t_asm *asmb)
{
	t_fname		*name;

	if (!asmb || !(asmb->fname))
		return ;
	while (asmb->fname)
	{
		name = asmb->fname->next;
		ft_memdel((void*)&(asmb->fname->name));
		ft_memdel((void*)&(asmb->fname));
		asmb->fname = name;
	}
	asmb->fname = NULL;
	asmb->fname_len = 0;
}
