/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:12:40 by suddin            #+#    #+#             */
/*   Updated: 2019/03/16 14:45:05 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "add.h"

void				init_read_directory_vat(char **path, t_sfile **file,
		struct dirent **rd, int *count_elem)
{
	*path = NULL;
	*file = NULL;
	*rd = NULL;
	*count_elem = 0;
}

int					read_directory(t_asm *asmb, DIR *dir, int *count_dot_s,
		char *str)
{
	char			*path;
	t_sfile			*file;
	struct dirent	*rd;
	int				count_elem;

	init_read_directory_vat(&path, &file, &rd, &count_elem);
	while ((rd = readdir(dir)))
	{
		if (is_s_file(rd->d_name) == SUCCESS)
		{
			path = join_dir_name(str, rd->d_name);
			file = sfile_new();
			if (sfile_stat(path, file) == ERROR || file->file_type != TYPE_REG)
				sfile_close(file);
			else if (file && file->file_type == TYPE_REG)
			{
				push_file_q(asmb, file);
				(*count_dot_s)++;
			}
			ft_memdel((void *)&path);
		}
		(count_elem)++;
	}
	return (count_elem);
}

int					manage_dir(t_asm *asmb, char *str)
{
	DIR				*dir;
	int				count_elem;
	int				count_dot_s;

	dir = NULL;
	count_elem = 0;
	count_dot_s = 0;
	if (!(dir = opendir(str)))
	{
		ft_printf_err("Error : opening %s. %s", str, strerror(errno));
		return (ERROR);
	}
	count_elem = read_directory(asmb, dir, &count_dot_s, str);
	closedir(dir);
	if (count_elem == 0)
		ft_printf("No file in directory %s\n", str);
	else if (count_dot_s == 0)
		ft_printf("No source file found in directory %s\n", str);
	return (SUCCESS);
}

int					sort_arg_name(t_asm *asmb)
{
	t_sfile			*file;
	t_fname			*name;

	name = asmb->arg_name;
	if (!asmb || asmb->arg_name_len == 0)
		return (ERROR);
	while (name)
	{
		file = sfile_new();
		if (sfile_stat(name->name, file) == ERROR)
			sfile_close(file);
		else
		{
			if (file->file_type == TYPE_REG)
				push_file_q(asmb, file);
			else if (file->file_type == TYPE_DIR)
			{
				manage_dir(asmb, name->name);
				sfile_close(file);
			}
		}
		name = name->next;
	}
	free_arg_name(asmb);
	return (SUCCESS);
}

int					get_argv(t_asm *asmb, int argc, char **argv)
{
	int				i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], FLAG_NAME_STRICT) == 0)
			asmb->flag |= FLAG_STRICT;
		else if (ft_strcmp(argv[i], FLAG_NAME_H) == 0 || ft_strcmp(argv[i],
					FLAG_NAME_HELP) == 0)
			asmb->flag |= FLAG_H;
		else if (ft_strcmp(argv[i], FLAG_NAME_Q) == 0 || ft_strcmp(argv[i],
					FLAG_NAME_QUIET) == 0)
			asmb->flag |= FLAG_Q;
		else
			push_arg_name(asmb, argv[i]);
		i++;
	}
	sort_arg_name(asmb);
	free_arg_name(asmb);
	return (SUCCESS);
}
