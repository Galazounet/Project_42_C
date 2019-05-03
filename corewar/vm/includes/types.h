/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 21:34:20 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/26 18:08:39 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "stdint.h"
# include "vm.h"

/*
** Structure visualisateur
*/

typedef struct		s_visu
{
	int		x_win;
	int		y_win;
	int		j;
	int		w_nb;
}					t_visu;

/*
** Structure des arguments
*/
typedef	struct		s_args
{
	int			ac;
	int			pad;
	char		**av;
}					t_args;

/*
** Structure des processus
*/
typedef	struct		s_proc
{
	uint32_t			reg[MAX_REG];
	uint32_t			live;
	uint32_t			id;
	int32_t				wait;
	int					op;
	uint32_t			parent;
	struct s_proc		*next;
}					t_proc;

/*
** Structure des champions
*/
typedef	struct		s_warrior
{
	char		*file_name;
	uint32_t	warrior_number;
	uint32_t	len;
	uint32_t	initial_pc;
	uint8_t		magic[4];
	uint8_t		*instructions;
	uint8_t		name[PROG_NAME_LEN + 1];
	uint8_t		comment[COMMENT_LEN + 1];
}					t_warrior;

/*
** Structure de la machine virtuelle
*/
typedef struct		s_vm
{
	uint32_t	cycle;
	int32_t		ctd;
	uint32_t	check_count;
	uint32_t	last_check;
	uint32_t	live_warrior;
	uint8_t		memory[MEM_SIZE];
	uint32_t	parent[MEM_SIZE];
	uint8_t		index[MEM_SIZE];
	unsigned	process_tc;
	t_proc		*queue;
}					t_vm;

/*
** Structure d'environnement
*/
typedef struct		s_cv
{
	t_warrior	warrior[4];
	t_vm		vm;
	uint8_t		nb_warriors;
	int32_t		dump;
	t_visu		visu;
	uint32_t	graphical_interface;
	uint32_t	verbose;
}					t_cv;

/*
** Champ de bits;
** il faut assigner cette structure de cette manière:
** o = *(t_ocp*)&ocp;
** ou o est la structure, et opc l'octet
*/
typedef	struct		s_ocp
{
	unsigned char	vide : 2;
	unsigned char	param3 : 2;
	unsigned char	param2 : 2;
	unsigned char	param1 : 2;
}					t_ocp;

/*
** Pointeur sur fonctions d'erreurs
*/
typedef void		(*t_elist)(void);

/*
** Pointeur sur fonctions de parsing d'option
*/
typedef int			(*t_arglist)(int *i, t_args *args, t_cv *env);

/*
** Pointeur sur fonctions pour les paramètres des opérations
*/
typedef int			(*t_setlist)(unsigned *param, t_cv *env, t_proc *proc,
						unsigned *pc);

/*
** Pointeur sur fonctions opcode
*/
typedef int			(*t_op)(t_cv*, t_proc*);

#endif
