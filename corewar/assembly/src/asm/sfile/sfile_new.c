/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfile_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:03:03 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 00:03:15 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_sfile	*sfile_new(void)
{
	t_sfile *file;

	if (!(file = (t_sfile*)malloc(sizeof(t_sfile))))
		return (NULL);
	sfile_init(file);
	return (file);
}
