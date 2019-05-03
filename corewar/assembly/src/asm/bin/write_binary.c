/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:52:27 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:00:36 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "add.h"

static inline void		open_error_msg(char *msg, char *name)
{
	ft_strcpy(msg, "Opening / Creating file ");
	ft_strcat(msg, name);
	ft_strcat(msg, ": ");
	ft_strcat(msg, strerror(errno));
}

static inline void		write_error_msg(char *msg, t_pars *pars, char *name,
		int rd)
{
	ft_strcpy(msg, "Writing binary data to ");
	ft_strcat(msg, name);
	ft_strcat(msg, ". Wrote ");
	ft_strcat(msg, ft_static_itoa(rd));
	ft_strcat(msg, "/");
	ft_strcat(msg, ft_static_itoa(pars->bin_len));
	ft_strcat(msg, ". ");
	ft_strcat(msg, strerror(errno));
}

void					write_binary(t_asm *asmb, t_pars *pars)
{
	int					fd;
	int					rd;
	char				*name;
	char				msg[200];

	if (!asmb || !pars)
		return ;
	rd = 0;
	name = asmb->curr_file->file_name_cor;
	fd = open(name, O_WRONLY | O_CREAT, S_IRWXO | S_IRWXU);
	if (fd < 0)
	{
		open_error_msg(msg, name);
		pars_error(asmb, msg, NULL, ERROR);
		return ;
	}
	if ((rd = write(fd, pars->bin, pars->bin_len)) < pars->bin_len)
	{
		write_error_msg(msg, pars, name, rd);
		pars_error(asmb, msg, NULL, ERROR);
		return ;
	}
	if ((asmb->flag & FLAG_Q) == 0)
		ft_printf("\e[92mCompiled `%s`, writing binary data to `%s`.\e[39m\n",\
				asmb->curr_file->file_name, name);
}
