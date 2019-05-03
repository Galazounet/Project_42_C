/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 01:50:11 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/21 03:17:14 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

static void	free_queue(t_proc **queue)
{
	t_proc *tmp;

	while (*queue)
	{
		tmp = (*queue)->next;
		free(*queue);
		*queue = tmp;
	}
}

int			main(int ac, char **av)
{
	t_args		args;
	t_cv		env;

	ft_bzero(&args, sizeof(t_args));
	ft_bzero(&env, sizeof(t_cv));
	args.ac = ac;
	args.av = av;
	env.dump = -1;
	if (errorhandler_parser(arguments_parser(&args, &env)) != 0)
		return (1);
	else if (errorhandler_parser(initiate_proc(&env)) != 0)
		return (1);
	else if (errorhandler_parser(run(&env)) != 0)
		return (1);
	if (env.vm.queue)
		free_queue(&env.vm.queue);
	return (0);
}
