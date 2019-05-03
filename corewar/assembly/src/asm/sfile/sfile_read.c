/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfile_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:43:32 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:02:52 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_integrity(t_sfile *file)
{
	if (!file)
		return (1);
	if (file->file_fd < 0 || file->file_size == 0
		|| file->file_type != TYPE_REG)
		return (1);
	return (0);
}

static void	display_msg(t_sfile *file)
{
	ft_printf_err("\e[91mError:\e[39m in `%s`, ", file->file_name);
	ft_printf_err("data might not be in ASCII format, ");
	ft_printf_err("or might be some other error. \\_(ʘ_ʘ)_/\n");
}

char		**sfile_read(t_sfile *file)
{
	char	**tab;
	char	*buff;
	int		rd;

	if (!(buff = ft_strnew(file->file_size + 1)) || check_integrity(file) == 1)
		return (NULL);
	rd = 0;
	tab = NULL;
	rd = read(file->file_fd, buff, file->file_size);
	if (rd < 0 || rd != (int)file->file_size)
	{
		ft_memdel((void*)&buff);
		ft_printf_err("\e[91mError:\e[39m Reading `%s`.", file->file_name);
		if (errno != 0)
			ft_printf_err(" %s.", strerror(errno));
		ft_printf_err("\n", file->file_name);
		return (NULL);
	}
	buff[rd] = 0;
	if (!(tab = ft_strsplitn(buff, '\n')))
		display_msg(file);
	tab_replace(tab, '\n', 0);
	ft_memdel((void*)&buff);
	file->tab = tab;
	return (tab);
}
