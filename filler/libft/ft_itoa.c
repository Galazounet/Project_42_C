/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:54:19 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 12:44:56 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static void	ft_remplissage(char *str, int save, int i, int j)
{
	while (i > 0)
	{
		str[j] = (save / i % 10) + 48;
		i /= 10;
		j++;
	}
	str[j] = '\0';
}

static void	ft_calc(char *str, int save, int i)
{
	int		j;

	j = 0;
	if (save < 0)
	{
		if (save == -2147483648)
		{
			str[0] = '-';
			str[1] = '2';
			j = 2;
			i = i / 10;
			save = 147483648;
		}
		else
		{
			str[0] = '-';
			j = 1;
			save = save * -1;
		}
	}
	ft_remplissage(str, save, i, j);
}

char		*ft_itoa(int n)
{
	int		i;
	int		save;
	char	*str;
	int		k;

	k = 1;
	i = 1;
	save = n;
	while ((n /= 10) != 0)
	{
		k++;
		i = i * 10;
	}
	if (save < 0)
		k++;
	if (!(str = malloc(sizeof(char) * k + 1)))
		return (NULL);
	ft_calc(str, save, i);
	return (str);
}
