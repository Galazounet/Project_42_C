/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 06:05:05 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/21 04:52:34 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

void	wrong_magic(void)
{
	ft_putstr_fd("error: wrong file format. only corewar warriors w/ ",
					STDERR_FILENO);
	ft_putendl_fd("valid headers are working", STDERR_FILENO);
}

void	big_instruction(void)
{
	ft_putendl_fd("error: too much instructions in this file.", STDERR_FILENO);
}

void	too_many_warriors(void)
{
	ft_putendl_fd("error: too many warriors specified. max allowed are 4",
				STDERR_FILENO);
}

void	wrong_extention(void)
{
	ft_putendl_fd("error: wrong file extention.", STDERR_FILENO);
}

void	errno_error(void)
{
	ft_putstr_fd("error: ", STDERR_FILENO);
	perror(NULL);
}
