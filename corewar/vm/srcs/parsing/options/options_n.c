/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 04:45:07 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/26 21:32:23 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"
#include "limits.h"

static int	check_duplicate_number(t_cv *env, unsigned nb)
{
	int i;

	i = 0;
	if (nb <= 0)
		return (NEGATIVE_OR_ZERO);
	while (i < env->nb_warriors - 1)
	{
		if (env->warrior[i].warrior_number == nb)
			return (DOUBLE_ASSIGN);
		++i;
	}
	return (SUCCESS);
}

int			option_n(int *i, t_args *args, t_cv *env)
{
	long	tmp;
	int		ret;

	if (args->av[*i][2])
		return (USAGE);
	++(*i);
	if (!args->av[(*i)])
		return (USAGE);
	if (!args->av[(*i)] && ft_strlen(args->av[*i]) > 10)
		return (USAGE);
	if ((*i) + 1 >= args->ac || !ft_isnumber(args->av[*i]))
		return (USAGE);
	tmp = ft_atol(args->av[*i]);
	if (tmp <= 0 || tmp > UINT32_MAX)
		return (USAGE);
	++(*i);
	if ((ret = verify_extention(args->av[*i], env)) != 0)
		return (ret);
	if ((ret = check_duplicate_number(env, (unsigned)tmp)) != 0)
		return (ret);
	env->warrior[env->nb_warriors - 1].warrior_number = (unsigned)tmp;
	return (SUCCESS);
}
