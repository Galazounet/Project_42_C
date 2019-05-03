/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:21:37 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/20 19:40:28 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

uint8_t		read_8(t_cv *env, unsigned n)
{
	return (env->vm.memory[n % MEM_SIZE]);
}

uint16_t	read_16(t_cv *env, unsigned n)
{
	uint16_t	content;
	uint8_t		*content_ptr;

	content_ptr = (uint8_t*)&content;
	content_ptr[1] = read_8(env, n);
	content_ptr[0] = read_8(env, n + 1);
	return (content);
}

uint32_t	read_32(t_cv *env, unsigned n)
{
	uint32_t	content;
	uint16_t	*content_ptr;

	content_ptr = (uint16_t*)&content;
	content_ptr[1] = read_16(env, n);
	content_ptr[0] = read_16(env, n + 2);
	return (content);
}
