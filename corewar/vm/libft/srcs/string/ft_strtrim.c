/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:21:09 by afrangio          #+#    #+#             */
/*   Updated: 2017/11/22 18:48:44 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_ifunderzero(int *len)
{
	if (*len < 0)
		(*len) = 0;
}

static	void	ft_blanktop(char *s, int *i)
{
	while (s[*i] == '\n' || s[*i] == ' ' || s[*i] == '\t')
		(*i)++;
}

static	void	ft_blankbottom(char *s, int *len)
{
	while (s[*len] == '\n' || s[*len] == ' ' || s[*len] == '\t')
		(*len)--;
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		len;
	int		j;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	i = 0;
	j = -1;
	ft_blanktop((char*)s, &i);
	if (i >= len)
		return (ft_strdup(""));
	ft_blankbottom((char*)s, &len);
	ft_ifunderzero(&len);
	str = ft_memalloc(sizeof(char) * (len - i + 2));
	if (str == NULL)
		return (NULL);
	while (i <= len)
	{
		str[++j] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
