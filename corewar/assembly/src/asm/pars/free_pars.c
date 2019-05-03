/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:23:20 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 00:23:47 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_pars(t_pars **pars)
{
	if (!*pars)
		return ;
	if ((*pars)->name)
		ft_memdel((void*)&((*pars)->name));
	if ((*pars)->comment)
		ft_memdel((void*)&((*pars)->comment));
	if ((*pars)->label_name)
		free_tab((*pars)->label_name);
	if ((*pars)->label_tab)
		ft_memdel((void*)&((*pars)->label_tab));
	if ((*pars)->inst_table)
		ft_memdel((void*)&((*pars)->inst_table));
	if ((*pars)->bin)
		ft_memdel((void*)&((*pars)->bin));
	ft_memdel((void*)&((*pars)));
}
