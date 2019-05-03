/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:59:57 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/13 03:28:40 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		chiffre;
	int		i;
	int		signe;

	i = 0;
	chiffre = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	signe = 1;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		chiffre = chiffre * 10 + (str[i] - '0');
		i++;
	}
	chiffre = chiffre * signe;
	return (int)(chiffre);
}

long	ft_atol(const char *str)
{
	long	chiffre;
	long	i;
	long	signe;

	i = 0;
	chiffre = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	signe = 1;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		chiffre = chiffre * 10 + (str[i] - '0');
		i++;
	}
	chiffre = chiffre * signe;
	return (chiffre);
}
