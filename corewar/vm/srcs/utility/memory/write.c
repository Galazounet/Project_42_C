/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:31:13 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/20 19:40:32 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

void	write_8(t_cv *env, unsigned n, uint8_t content, int parent)
{
	env->vm.parent[n % MEM_SIZE] = (unsigned)parent + 1;
	env->vm.memory[n % MEM_SIZE] = content;
}

void	write_16(t_cv *env, unsigned n, uint16_t content, int parent)
{
	uint8_t *content_ptr;

	content_ptr = (uint8_t*)&content;
	write_8(env, n, content_ptr[1], parent);
	write_8(env, n + 1, content_ptr[0], parent);
}

void	write_32(t_cv *env, unsigned n, uint32_t content, int parent)
{
	uint16_t *content_ptr;

	content_ptr = (uint16_t*)&content;
	write_16(env, n, content_ptr[1], parent);
	write_16(env, n + 2, content_ptr[0], parent);
}
