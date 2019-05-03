/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 06:07:35 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/23 00:14:04 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

void	show_usage(void)
{
	ft_putstr("usage: corewar [-i n] [-d N] [-n N <N.cor>] <champion1.cor> ");
	ft_putendl("<...>");
	ft_putendl("#### OPTIONS ################################################");
	ft_putstr("    -n N <N.cor> : manually set champion number (from 1 to ");
	ft_putnbr(UINT32_MAX);
	ft_putendl(")\n    -d N         : dumps memory after N cycles then exits");
	ft_putendl("    -i [n: 1..n] : ncurses output mode start at cycle n");
	ft_putendl("    -i cannot be associated with other options");
}
