/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:29:01 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:31 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "add.h"

int					is_s_file(char *str)
{
	int				len;

	if (!str)
		return (ERROR);
	len = ft_strlen(str);
	if (len > 2 && ft_strcmp(&(str[len - 2]), ".s") == 0)
		return (SUCCESS);
	return (ERROR);
}

char				*join_dir_name(char *dir, char *file)
{
	int				len;
	char			*path;

	if (!dir || !file)
		return (NULL);
	len = ft_strlen(dir) + ft_strlen(file) + 1;
	if (!(path = ft_strnew(len)))
		return (NULL);
	ft_strcpy(path, dir);
	ft_strcat(path, "/");
	ft_strcat(path, file);
	return (path);
}
