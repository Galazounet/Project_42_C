/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arg_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:14:28 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:00:38 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			free_arg_name(t_asm *asmb)
{
	t_fname		*name;

	if (!asmb || !(asmb->arg_name))
		return ;
	while (asmb->arg_name)
	{
		name = asmb->arg_name->next;
		ft_memdel((void*)&(asmb->arg_name->name));
		ft_memdel((void*)&(asmb->arg_name));
		asmb->arg_name = name;
	}
	asmb->arg_name = NULL;
	asmb->arg_name_len = 0;
}
