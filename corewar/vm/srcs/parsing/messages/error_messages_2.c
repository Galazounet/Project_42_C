/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 06:05:05 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/21 03:56:36 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

void	double_assign(void)
{
	ft_putendl_fd("error: warrior must have umique number.", STDERR_FILENO);
}

void	neg_or_zero(void)
{
	ft_putendl_fd("error: warrior number must be positive and above 0",
				STDERR_FILENO);
}
