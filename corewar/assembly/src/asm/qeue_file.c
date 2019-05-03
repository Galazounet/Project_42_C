/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qeue_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:32:13 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:01:53 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			qeue_file(t_asm *asmb)
{
	t_sfile	*file;
	t_fname	*name;

	file = NULL;
	name = asmb->fname;
	if (!asmb)
		return (ERROR);
	if (asmb->fname_len == 0)
	{
		ft_printf("/* Show error report and show usage */");
	}
	while (name)
	{
		file = sfile_new();
		if (sfile_stat(name->name, file) == ERROR)
			sfile_close(file);
		else
		{
			push_file_q(asmb, file);
		}
		name = name->next;
	}
	free_fname(asmb);
	return (SUCCESS);
}
