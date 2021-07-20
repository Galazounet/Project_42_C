/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:19:17 by dygouasd          #+#    #+#             */
/*   Updated: 2017/12/06 14:50:27 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <libft.h>

# define TETRA_SIZE 21
# define BUFFSIZE 546
# define N_TETRIMINOS 19
# define UNUSED(x) ((void)x)
# define PARSER_LINE(c, i) (c != 46 && c != 35) && i && !(i + 1 % 5) && c != 10
# define GETDIFF(x) (5 - (i % 5) - 2)
# define COLLISION_Y(p, size, size_y) ((p / 11 + size_y) <= size ? 1 : 0)
# define COLLISION_X(p, size, size_x) ((p % 11 + size_x) <= size ? 1 : 0)
# define COLLISION_T(fill, tetras, p) ((fill & tetras << p) == 0 ? 1 : 0)
# define SIZE_MAPSTR(x) (x * x + x)
# define A1 0x1803

/*
** ##
** ##
*/
# define B1 0x200400801
# define B2 0x0F

/*
** 1: # 2: ####
**    #
**    #
**    #
*/
# define C1 0x400803
# define C2 0x3801
# define C3 0xC01002
# define C4 0x2007

/*
** 1: ## 2: #   3:  # 4: ###
**    #     ###     #      #
**    #            ##
*/
# define D1 0x801003
# define D2 0x3804
# define D3 0xC00801
# define D4 0x807

/*
** 1: ## 2:   # 3: # 4: ###
**     #    ###    #    #
**     #           ##
*/
# define E1 0x1806
# define E2 0x801801

/*
** 1: ##  2: #
**   ##      ##
**            #
*/
# define F1 0x3003
# define F2 0x401802

/*
** 1: ##  2:  #
**     ##    ##
**           #
*/
# define G1 0x3802
# define G2 0x1007
# define G3 0x801802
# define G4 0x401801

/*
** 1:  #  2: ###  3: # 4: #
**    ###     #     ##    ##
**                   #    #
*/

typedef struct		s_struct
{
	long			tetras;
	int				size_x;
	int				size_y;
	char			tetrachar[4][4];
	int				p;
	char			letter;
}					t_data;

t_data				g_t[27];

int					backtracker(char *map, int p, int n, int size);
void				print_map(int height, t_data *t, int size, char *out);
int					parse_one(t_data *t, char *str);
int					parse_all(int fd, t_data *t);
void				die(char *type, char *arg);
int					match(t_data *t);

#endif

