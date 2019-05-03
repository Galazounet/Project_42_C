/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfile_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:02:28 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 00:02:49 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	sfile_init(t_sfile *file)
{
	if (!file)
		return ;
	file->file_name = NULL;
	file->file_name_cor = NULL;
	file->path_name = NULL;
	file->file_type = 0;
	file->file_fd = -1;
	file->file_size = 0;
	file->tab = NULL;
	file->next = NULL;
}
