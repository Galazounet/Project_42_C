/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:09:31 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:01:25 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			compile_file_q(t_asm *asmb)
{
	t_sfile		*file;
	t_lexobj	*lex;
	t_pars		*pars;

	lex = NULL;
	pars = NULL;
	file = asmb->file_q;
	while (file)
	{
		asmb->curr_file = file;
		if (sfile_read(file) != NULL)
		{
			lex = asm_lex(file->tab, 0, 0, 0);
			if (check_lexobj_tree(asmb, lex) != ERROR)
			{
				if ((pars = pars_lexobj(asmb, file->tab, lex)))
					if (pars_to_binary(asmb, pars) != ERROR)
						write_binary(asmb, pars);
			}
		}
		free_pars(&pars);
		clear_lexchain(&lex);
		file = file->next;
	}
}

int				show_usage(void)
{
	ft_printf("\e[93mExpected at least one file name to compile!\e[39m\n");
	ft_printf("./asm [option] [file1] [file2] [directory] [...]\n");
	ft_printf("\t\e[2mTry the option -h or ");
	ft_printf("--help for more information.\e[8m\n");
	return (1);
}

int				show_help(void)
{
	ft_printf("./asm [option] [file1] [file2] [directory] [...]\n");
	ft_printf("The asm is a program that compiles corewar source file,");
	ft_printf("where\n");
	ft_printf("a abstract asmbly language is used called Redcode, for more\n");
	ft_printf("information please visit the following url.\n");
	ft_printf("https://docs.google.com/document/d/");
	ft_printf("1DT_47inyTLDEUMevdmsA4jqr3_FXGvgKhzpGv_rtuOo/edit?usp=sharing");
	ft_printf("\n\n");
	ft_printf("The asm program takes options, regular file and directory ");
	ft_printf("as it's parameter.\n");
	ft_printf("When a directory is given in the parameter then the program\n");
	ft_printf("will try to compile any regular files found in directory ");
	ft_printf("that has a `.s` extention.\n");
	ft_printf("Any file with error will not be compiled.\n\n");
	ft_printf("Options:\n");
	ft_printf("\t -s, --strict : Consider any warning as error\n");
	ft_printf("\t -q, --quiet  : Do not show warning and write output\n");
	ft_printf("\t -h, --help   : Show this menu\n");
	return (0);
}

int				main(int argc, char **argv)
{
	t_asm asmb;

	if (argc < 2)
		return (show_usage());
	init_asm(&asmb);
	if (get_argv(&asmb, argc, argv) == ERROR)
	{
		if ((asmb.flag & FLAG_H) != 0)
			return (show_help());
		else if (asmb.arg_name_len == 0)
			show_usage();
		return (1);
	}
	compile_file_q(&asmb);
	free_asm(&asmb);
	return (0);
}
