/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:00:45 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/10 17:24:04 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_print_words_tables(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[j] != '\0')
	{
		ft_putstr(tab[j]);
		ft_putchar('\n');
		j++;
	}
}
