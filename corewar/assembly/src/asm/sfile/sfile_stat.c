/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfile_stat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:20:39 by suddin            #+#    #+#             */
/*   Updated: 2018/10/07 23:25:23 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline char	*set_cor_extension(char *str)
{
	int		str_len;
	char	*cor;
	int		to_cpy;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	to_cpy = str_len;
	cor = ft_strnew(str_len + 3);
	if (ft_strlen(str) > 2)
		if (ft_strcmp(&(str[str_len - 2]), ".s") == 0)
			to_cpy = str_len - 2;
	ft_strncpy(cor, str, to_cpy);
	ft_strcat(cor, ".cor");
	return (cor);
}

static inline int	set_file_type(t_sfile *file, char *fname)
{
	if (S_ISREG(file->st.st_mode) == 1)
	{
		file->file_type |= TYPE_REG;
		file->file_name = ft_strdup(fname);
		file->file_name_cor = set_cor_extension(fname);
	}
	else if (S_ISDIR(file->st.st_mode) == 1)
	{
		file->file_type |= TYPE_DIR;
		file->path_name = ft_strdup(fname);
	}
	else
	{
		ft_printf_err("\e[91mError:\e[39m the file type of `%s` ", fname);
		ft_printf_err("is not supported, only regular files or directories ");
		ft_printf_err("are expected.\n");
		return (ERROR);
	}
	return (SUCCESS);
}

static inline int	set_size_check(t_sfile *file, char *name)
{
	if (file->st.st_size == 0)
	{
		ft_printf_err("\e[91mError:\e[39m `%s` is empty\n", name);
		return (ERROR);
	}
	else if (file->st.st_size > MAX_FILE_SIZE)
	{
		ft_printf_err("\e[91mError:\e[39m `%s` is too big ", name);
		ft_printf_err("(%d), Maximum size accepted is ", file->st.st_size);
		ft_printf_err("%d\n", MAX_FILE_SIZE);
		return (ERROR);
	}
	file->file_size = file->st.st_size;
	return (SUCCESS);
}

int					sfile_stat(char *fname, t_sfile *file)
{
	if (!fname || !file || ft_strlen(fname) == 0)
		return (ERROR);
	if (stat(fname, &(file->st)) < 0)
	{
		ft_printf_err("\e[91mError:\e[39m `%s` : %s\n", fname, strerror(errno));
		return (ERROR);
	}
	if (set_file_type(file, fname) == ERROR)
		return (ERROR);
	set_size_check(file, fname);
	if ((file->file_type & TYPE_REG) != 0)
	{
		if ((file->file_fd = open(fname, O_RDONLY)) < 0)
		{
			ft_printf_err("\e[91mError:\e[39m Opening file `%s` : ", fname);
			ft_printf_err("%s\n", strerror(errno));
			return (ERROR);
		}
	}
	return (SUCCESS);
}
