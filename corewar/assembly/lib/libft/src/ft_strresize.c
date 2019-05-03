/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strresize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 00:01:28 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 21:29:40 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strresize(char *str, size_t size)
{
	char *tmp;

	tmp = ft_strdup(str);
	free(str);
	str = ft_strnew(size);
	if (ft_strlen(tmp) > size)
		ft_strncpy(str, tmp, size);
	else
		ft_strcpy(str, tmp);
	free(tmp);
	return (str);
}
