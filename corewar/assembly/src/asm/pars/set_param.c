/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:22:25 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:01:55 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	set_label(t_asm *asmb, t_lexobj **param, t_pars *pars,
		t_inst *inst)
{
	int		p;
	int		par_n;

	if (!asmb || !param || !pars || !inst)
		return (ERROR);
	p = pars->tmp_param_nb;
	par_n = pars->tmp_param_curr;
	if ((inst->arg[p] = get_label_by_name(pars,\
					&(param[par_n]->value[1]))) == ERROR)
	{
		return (pars_error(asmb, "Unknown `label` call",
					param[par_n], ERROR));
	}
	inst->arg_type[p] = ASM_LEBEL_INDIRECT;
	pars->tmp_param_nb++;
	return (SUCCESS);
}

static int	set_direct(t_asm *asmb, t_lexobj **param, \
		t_pars *pars, t_inst *inst)
{
	int		p;
	int		par_n;

	if (!asmb || !param || !pars || !inst)
		return (ERROR);
	p = pars->tmp_param_nb;
	par_n = pars->tmp_param_curr;
	if (param[par_n]->value[1] == LEBEL_LIMIT_CHAR)
	{
		if ((inst->arg[p] = get_label_by_name(pars,
						&(param[par_n]->value[2]))) == ERROR)
			return (pars_error(asmb, "Unknown `label` call", param[par_n], -1));
		inst->arg_type[p] = ASM_LEBEL_DIRECT;
	}
	else
	{
		if (verify_int_direct(asmb, param[par_n], \
					&(param[par_n]->value[1])) == ERROR)
			return (ERROR);
		inst->arg[p] = ft_atoi(&(param[par_n]->value[1]));
		inst->arg_type[p] = ASM_DIRECT;
	}
	pars->tmp_param_nb++;
	return (SUCCESS);
}

static int	set_indirect(t_asm *asmb, t_lexobj **param, \
		t_pars *pars, t_inst *inst)
{
	int		p;
	int		par_n;

	if (!asmb || !param || !pars || !inst)
		return (ERROR);
	p = pars->tmp_param_nb;
	par_n = pars->tmp_param_curr;
	if (verify_int_indirect(asmb, param[par_n], \
				&(param[par_n]->value[0])) == ERROR)
		return (ERROR);
	inst->arg[p] = ft_atoi(&(param[par_n]->value[0]));
	inst->arg_type[p] = ASM_INDIRECT;
	pars->tmp_param_nb++;
	return (SUCCESS);
}

static int	set_register(t_asm *asmb, t_lexobj **param, \
		t_pars *pars, t_inst *inst)
{
	int		p;
	int		par_n;

	if (!asmb || !param || !pars || !inst)
		return (ERROR);
	p = pars->tmp_param_nb;
	par_n = pars->tmp_param_curr;
	if (verify_register(asmb, param[par_n], &(param[par_n]->value[1]))
			== ERROR)
		return (ERROR);
	inst->arg[p] = ft_atoi(&(param[par_n]->value[1]));
	inst->arg_type[p] = ASM_REGISTER;
	pars->tmp_param_nb++;
	return (SUCCESS);
}

int			set_param(t_asm *asmb, t_lexobj **param, t_pars *pars,
		t_inst *inst)
{
	int		par_n;

	if (!asmb || !param || !pars || !inst)
		return (ERROR);
	if (pars->tmp_param_count == 0)
		return (SUCCESS);
	par_n = pars->tmp_param_curr;
	if ((param[par_n]->type == ASM_LEBEL_CALL) && (set_label(asmb, param,
					pars, inst) == ERROR))
		return (ERROR);
	else if ((param[par_n]->type == ASM_DIRECT) && (set_direct(asmb, param,
					pars, inst) == ERROR))
		return (ERROR);
	else if ((param[par_n]->type == ASM_INDIRECT) && (set_indirect(asmb,
					param, pars, inst) == ERROR))
		return (ERROR);
	else if ((param[par_n]->type == ASM_REGISTER) && (set_register(asmb,
					param, pars, inst) == ERROR))
		return (ERROR);
	pars->tmp_param_count--;
	pars->tmp_param_curr++;
	return (set_param(asmb, param, pars, inst));
}
