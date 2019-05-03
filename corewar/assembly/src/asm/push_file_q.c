/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_file_q.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:30:41 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:00:17 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			push_file_q(t_asm *asmb, t_sfile *file)
{
	t_sfile		*fl;

	if (!asmb || !file)
		return ;
	if (asmb->file_q == NULL)
		asmb->file_q = file;
	else
	{
		fl = asmb->file_q;
		while (fl && fl->next)
			fl = fl->next;
		fl->next = file;
	}
	asmb->file_q_len++;
}
