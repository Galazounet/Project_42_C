/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 02:13:07 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/20 20:37:44 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static t_arglist	*get_arglist(void)
{
	static t_arglist arglist[NB_ARGS];

	arglist[0] = option_n;
	arglist[1] = option_d;
	arglist[2] = option_i;
	arglist[3] = option_v;
	return (arglist);
}

static int			check_current(t_args *args, t_cv *env, t_arglist *alist)
{
	int i;
	int ret;

	i = 1;
	while (i < (args->ac))
	{
		if (args->av[i][0] == '-')
		{
			if (args->av[i][1] && ft_indexof(ARGS, args->av[i][1]) >= 0)
			{
				if ((ret = alist[ft_indexof(ARGS, args->av[i][1])](&i, args,
						env)))
					return (ret);
			}
			else
				return (-1);
		}
		else if ((ret = arg_champ(&i, args, env)) != 0)
			return (ret);
		++i;
	}
	return (SUCCESS);
}

static void			warrior_number(unsigned *i, unsigned *j, unsigned
	*assign, t_cv *env)
{
	if (env->warrior[*j].warrior_number != *assign && *j
			== env->nb_warriors - 1u)
	{
		env->warrior[*i].warrior_number = *assign;
		++(*assign);
	}
	else if (env->warrior[*j].warrior_number == *assign)
	{
		++assign;
		*j = 0;
	}
	++(*j);
}

static int			complete_warrior_number(t_cv *env)
{
	unsigned i;
	unsigned j;
	unsigned assign;

	i = 0;
	assign = 1;
	while (i < env->nb_warriors)
	{
		if (env->warrior[i].warrior_number)
		{
			++i;
			continue ;
		}
		j = 0;
		while (j < env->nb_warriors)
			warrior_number(&i, &j, &assign, env);
		++i;
	}
	return (SUCCESS);
}

int					arguments_parser(t_args *args, t_cv *env)
{
	int			ret;
	t_arglist	*alist;

	alist = get_arglist();
	if (args->ac < 2)
		return (USAGE);
	else if ((ret = check_current(args, env, alist)) != 0)
		return (ret);
	else if (!env->nb_warriors)
		return (USAGE);
	else if ((ret = complete_warrior_number(env)) != 0)
		return (ret);
	else if ((ret = set_mempointer(env)) != 0)
		return (ret);
	else if ((ret = complete_structures(env)) != 0)
		return (ret);
	else
		return (SUCCESS);
}
