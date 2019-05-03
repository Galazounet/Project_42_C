/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lex_spearator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:43:37 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:33 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	is_lex_spearator(char c)
{
	if (is_space(c) == 1 || c == SEPARATOR_CHAR \
		|| c == STRING_CHAR || c == LEBEL_LIMIT_CHAR \
		|| c == DIRECT_CHAR || c == COMMENT_CHAR_1 \
		|| c == COMMENT_CHAR_2)
		return (1);
	return (0);
}
