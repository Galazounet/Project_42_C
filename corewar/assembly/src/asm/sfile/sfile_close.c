/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfile_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:00:41 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 00:00:42 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	sfile_close(t_sfile *file)
{
	if (!file)
		return ;
	if (file->file_name)
		ft_memdel((void*)&(file->file_name));
	if (file->file_name_cor)
		ft_memdel((void*)&(file->file_name_cor));
	if (file->path_name)
		ft_memdel((void*)&(file->path_name));
	if (file->tab)
		free_tab(file->tab);
	if (file->file_fd > -1)
		close(file->file_fd);
	free(file);
}
