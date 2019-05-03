/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:10:43 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:00:39 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_asm(t_asm *asmb)
{
	if (asmb->file_q)
		free_file_q(asmb);
	if (asmb->fname)
		free_fname(asmb);
	if (asmb->arg_name)
		free_arg_name(asmb);
}
