/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_len_verify.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:35:14 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 00:42:03 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline int	diff_para_nb(int nb)
{
	int count;

	count = 0;
	if ((nb & DI) != 0)
		count++;
	if ((nb & IN) != 0)
		count++;
	if ((nb & RE) != 0)
		count++;
	return (count);
}

static inline int	var_xor(int *a, int b)
{
	*a ^= b;
	return (1);
}

static inline void	set_param_type(char *msg, t_inst_meta *meta)
{
	int r;
	int type;
	int type_nb;

	r = -1;
	while (++r < meta->max_param)
	{
		type_nb = diff_para_nb(meta->param_type[r]);
		type = meta->param_type[r];
		while (type_nb > 0)
		{
			if ((type & DI) != 0 && var_xor(&type, DI) == 1)
				ft_strcat(msg, "`Direct`");
			else if ((type & IN) != 0 && var_xor(&type, IN) == 1)
				ft_strcat(msg, "`Indirect`");
			else if ((type & RE) != 0 && var_xor(&type, RE) == 1)
				ft_strcat(msg, "`Register`");
			if ((type_nb - 1) > 0)
				ft_strcat(msg, " | ");
			type_nb--;
		}
		if ((r + 1) < meta->max_param)
			ft_strcat(msg, ", ");
	}
}

static inline char	*param_len_verify_msg(t_inst_meta *meta, int flag)
{
	static char msg[100];

	ft_memset(msg, 0, 70);
	if (flag == 0)
		ft_strcpy(msg, "Not enough parameter for nstruction `");
	else if (flag == 1)
		ft_strcpy(msg, "Too many parameters for instruction `");
	ft_strcat(msg, meta->name);
	ft_strcat(msg, "`. ");
	ft_strcat(msg, "Expected ");
	ft_strcat(msg, ft_static_itoa(meta->max_param));
	if (meta->max_param > 1)
		ft_strcat(msg, " parameters: [");
	else if (meta->max_param == 1)
		ft_strcat(msg, " parameter: [");
	set_param_type(msg, meta);
	ft_strcat(msg, "] types.");
	return (msg);
}

int					param_len_verify(t_asm *asmb, \
		t_lexobj *lex, t_inst_meta *meta)
{
	int obj_len;
	int expt;

	obj_len = 0;
	expt = meta->max_param + (meta->max_param - 1);
	obj_len = count_lexobj(lex) - 1;
	if (obj_len < expt)
		return (pars_error(asmb, param_len_verify_msg(meta, 0), lex, ERROR));
	else if (obj_len > expt)
		return (pars_error(asmb, param_len_verify_msg(meta, 1), lex, ERROR));
	return (obj_len);
}
