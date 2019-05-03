/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:58:54 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 12:58:55 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curse.h>

int		count_files(char *path)
{
	struct dirent	*files;
	DIR				*dir;
	int				i;

	i = 0;
	if ((dir = opendir(path)) == NULL)
		return (-1);
	while ((files = readdir(dir)) != NULL)
	{
		if (files->d_name[0] != '.')
			++i;
	}
	closedir(dir);
	return (i);
}

char	**getfiles(char *path)
{
	struct dirent	*files;
	DIR				*dir;
	int				i;
	char			**ret;

	i = 0;
	i = count_files(path);
	if ((ret = malloc(sizeof(*ret) * i + 1)) == NULL)
		return (NULL);
	i = 0;
	if ((dir = opendir(path)) == NULL)
		return (NULL);
	while ((files = readdir(dir)) != NULL)
	{
		if (files->d_name[0] != '.')
		{
			if ((ret[i] = ft_strdup(files->d_name)) == NULL)
				return (NULL);
			++i;
		}
	}
	ret[i] = NULL;
	closedir(dir);
	return (ret);
}

int		counttab(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		++i;
	return (i);
}

int		count_arg(t_choice_list *list)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < N_MENUSTR)
	{
		if (list[i].ret != NULL)
			++ret;
		++i;
	}
	return (ret);
}

char	**form_arg(t_curses *c)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((ret = malloc(sizeof(*ret) * (count_arg(c->list) * 2 + 2))) == NULL)
		return (NULL);
	if ((ret[j++] = ft_strdup("filler_vm")) == NULL)
		return (NULL);
	while (i < N_MENUSTR)
	{
		if (c->list[i].ret != NULL)
		{
			if ((ret[j++] = ft_strdup(c->list[i].opt)) == NULL)
				return (NULL);
			if ((ret[j++] = ft_strdup(c->list[i].ret)) == NULL)
				return (NULL);
		}
		++i;
	}
	ret[j] = NULL;
	return (ret);
}
