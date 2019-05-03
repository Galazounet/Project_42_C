/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:45:44 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 00:48:07 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline void	print_flesh(t_asm *asmb, t_lexobj *lex, int err_n)
{
	char	**tab;
	int		v_len;
	int		i;

	if (!asmb || !lex || !asmb->curr_file->tab)
		return ;
	i = -1;
	v_len = 0;
	tab = asmb->curr_file->tab;
	while (++i < lex->start_index)
		ft_printf_err("%c", (tab[lex->line][i] == '\t') ? '\t' : ' ');
	ft_printf_err("%s^\e[39m", (err_n == ERROR) ? "\e[91m" : "\e[93m");
	if (lex->value)
	{
		i = -1;
		v_len = ft_strlen(lex->value) - 1;
		while (++i < v_len)
			ft_printf_err("%s~\e[39m", (err_n == ERROR) ? "\e[91m" : "\e[93m");
	}
	ft_printf_err("\n");
}

static inline void	print_line(t_asm *asmb, t_lexobj *lex, int err_n)
{
	int v_len;
	int i;

	v_len = 0;
	i = -1;
	if (!lex || !asmb->curr_file)
		return ;
	if (lex->value == NULL)
		ft_printf_err("%s\n", asmb->curr_file->tab[lex->line]);
	else if (lex->value != NULL)
	{
		v_len = ft_strlen(lex->value);
		while (++i < lex->start_index)
			ft_printf_err("%c", asmb->curr_file->tab[lex->line][i]);
		while (i < lex->start_index + v_len)
			ft_printf_err("%s%c\e[39m", (err_n == ERROR) ? "\e[91m" : "\e[93m",\
					asmb->curr_file->tab[lex->line][i++]);
		ft_printf_err("%s\n", &(asmb->curr_file->tab[lex->line][i]));
	}
	print_flesh(asmb, lex, err_n);
}

int					pars_error(t_asm *asmb, char *msg, t_lexobj *lex, int err_n)
{
	int er;

	er = err_n;
	if (err_n == SUCCESS)
		return (SUCCESS);
	if ((asmb->flag & FLAG_STRICT) != 0)
		err_n = ERROR;
	if ((asmb->flag & FLAG_Q) != 0 && err_n == WARNING)
		return (err_n);
	if (asmb->curr_file)
		ft_printf_err("%s:", asmb->curr_file->file_name);
	if (lex)
		ft_printf_err("%d:%d:", lex->line + 1, lex->start_index + 1);
	if (err_n == WARNING)
		ft_printf_err("\e[93m warning:\e[39m ");
	else if (err_n == ERROR)
		ft_printf_err("\e[91m error:\e[39m ");
	if (msg)
		ft_printf_err("%s %s\n", msg, ((asmb->flag & FLAG_STRICT) != 0 \
					&& er == WARNING) ? "[\e[91m--strict\e[39m]" : "");
	print_line(asmb, lex, err_n);
	return (err_n);
}
