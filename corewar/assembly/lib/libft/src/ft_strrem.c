/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 02:28:43 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 21:30:07 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrem(char *str, int from, int len)
{
	char *tmp;

	tmp = ft_strnew(ft_strlen(str) - len);
	ft_strncpy(tmp, str, from);
	ft_strcat(tmp, (str + (from + len)));
	ft_bzero(str, ft_strlen(str));
	ft_strcpy(str, tmp);
	return (str);
}
