/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_interface.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 21:54:10 by pavaucha          #+#    #+#             */
/*   Updated: 2019/02/26 21:44:09 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICAL_INTERFACE_H
# define GRAPHICAL_INTERFACE_H

# include <unistd.h>
# include <stdlib.h>
# include <ncurses.h>
# include "corewar.h"
# include "libft.h"

typedef	struct		s_visur
{
	unsigned int	speed;
	int				running;
	int				key;
}					t_visur;

void				ncurses_init(void);
void				modif_speed(t_visur *cmd);
void				ncurses_writevm(t_vm *vm, t_cv *env);
void				ncurses_dump(t_vm *vm, t_cv env, t_visur *cmd);
void				write_winner(t_cv *env);
void				create_window(void);
void				write_winner(t_cv *env);
void				print_command(void);
int					count_processes(t_proc *queue);
int					count_speed(unsigned int speed);
void				set_index(t_vm *vm);
int					nb_life(t_proc *queue, int i);
void				window_caracteristique(t_cv env, t_visur *cmd);
void				print_end(t_cv *env);

#endif
