/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:13:51 by afrangio          #+#    #+#             */
/*   Updated: 2017/11/22 18:48:38 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i] != '\0' && n)
	{
		s1[len] = s2[i];
		len++;
		i++;
		n--;
	}
	s1[len] = '\0';
	return (s1);
}
