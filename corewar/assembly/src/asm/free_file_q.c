/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file_q.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:10:55 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:02:14 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		free_file_q(t_asm *asmb)
{
	t_sfile	*file;

	if (!asmb || !(asmb->file_q))
		return ;
	while (asmb->file_q)
	{
		file = asmb->file_q->next;
		sfile_close(asmb->file_q);
		asmb->file_q = file;
	}
	asmb->file_q = NULL;
	asmb->file_q_len = 0;
}
