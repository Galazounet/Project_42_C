/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 00:48:43 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/21 04:49:50 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static int	check_dotcor(char *s)
{
	size_t	len;
	int		ret;

	len = ft_strlen(s);
	if (ft_strcmp(&s[len - 4], ".cor"))
		return (WRONG_EXTENTION);
	ret = open(s, O_RDONLY);
	if (ret < 0)
		return (ERRNO_CODE);
	close(ret);
	return (SUCCESS);
}

int			verify_extention(char *s, t_cv *env)
{
	int ret;

	if (env->nb_warriors > 3)
		return (TOO_MANY_WARRIORS);
	if ((ret = check_dotcor(s)) != 0)
		return (ret);
	env->warrior[env->nb_warriors].file_name = s;
	env->warrior[env->nb_warriors].warrior_number = 0;
	++(env->nb_warriors);
	return (SUCCESS);
}
