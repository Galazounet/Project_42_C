/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warrior.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 04:47:54 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/20 05:53:04 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"
#include "limits.h"

int	arg_champ(int *i, t_args *args, t_cv *env)
{
	int ret;

	if (((ret = verify_extention(args->av[*i], env)) != 0))
		return (ret);
	return (SUCCESS);
}
