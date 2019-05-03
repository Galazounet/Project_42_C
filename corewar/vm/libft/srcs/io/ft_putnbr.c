/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:36:39 by afrangio          #+#    #+#             */
/*   Updated: 2018/04/20 14:07:32 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(intmax_t n)
{
	ft_putnbr_fd(n, 1);
}

void	ft_putunbr(uintmax_t n)
{
	ft_putunbr_fd(n, 1);
}
