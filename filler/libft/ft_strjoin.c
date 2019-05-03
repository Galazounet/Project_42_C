/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:47:30 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 10:39:52 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (s1 != NULL && s2 != NULL)
	{
		if (!(join = malloc(sizeof(char) * DOUBLE_LEN(s1, s2) + 1)))
			return (0);
		ft_strcpy((char*)join, s1);
		ft_strcat((char*)join, s2);
		return (join);
	}
	return (NULL);
}
