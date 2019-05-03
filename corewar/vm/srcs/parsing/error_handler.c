/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 03:05:56 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/27 22:59:24 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static t_elist	*get_error_list(void)
{
	static t_elist error_list[ERROR_LEN];

	error_list[WRONG_MAGIC] = wrong_magic;
	error_list[BIG_INSTRUCTION] = big_instruction;
	error_list[TOO_MANY_WARRIORS] = too_many_warriors;
	error_list[USAGE] = show_usage;
	error_list[WRONG_EXTENTION] = wrong_extention;
	error_list[ERRNO_CODE] = errno_error;
	error_list[DOUBLE_ASSIGN] = double_assign;
	error_list[NEGATIVE_OR_ZERO] = neg_or_zero;
	return (error_list);
}

int				errorhandler_parser(int error_code)
{
	t_elist *error_list;

	error_list = get_error_list();
	if (error_code > 0 && error_code < ERROR_LEN)
		error_list[error_code]();
	else if (error_code < 0)
		ft_putendl_fd("error: unknown option.", 2);
	else if (error_code != 0)
		ft_putendl_fd("error.", 2);
	return (error_code);
}
