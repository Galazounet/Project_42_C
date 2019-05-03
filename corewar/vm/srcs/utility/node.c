/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:16:27 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/20 04:49:40 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

t_proc		*create_list(void)
{
	t_proc *node;

	if (!(node = (t_proc*)ft_memalloc(sizeof(t_proc))))
		return (NULL);
	else
	{
		node->next = NULL;
		return (node);
	}
}

void		add_process(t_proc **begin_node)
{
	t_proc	*tmp;

	tmp = *begin_node;
	if (!*begin_node)
		*begin_node = create_list();
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_list();
	}
}

void		push_process(t_proc **begin_node)
{
	t_proc *tmp;

	if (!*begin_node)
		*begin_node = create_list();
	else
	{
		tmp = create_list();
		tmp->next = *begin_node;
		*begin_node = tmp;
	}
}

void		kill_process(t_proc **process, unsigned id)
{
	t_proc *current;
	t_proc *tmp;

	while (*process)
	{
		current = *process;
		if (current->id == id)
		{
			tmp = current->next;
			free(current);
			*process = tmp;
			return ;
		}
		process = &(*process)->next;
	}
}
