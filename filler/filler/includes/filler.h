/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 09:57:07 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 13:44:38 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H
# define PARSMAP(x) (x == '.' || x == 'O' || x == 'X')
# define PARSPIECE(x) (x == '*' || x == '.')
# define INMAP(x, y, a, b) (x >= 0 && y >= 0 && x < a && y < b)
# define VALID(x, y) (x > 0 && y > 0)
# define ABS(x) (x > 0 ? x : -x)
# define GS(x) (x < 0 || x > 100000)
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../libft/libft.h"

typedef struct	s_fill
{
	char		**map;
	char		**piece;
	int			round;
	int			player;
	char		a;
	char		h;
	int			m[2];
	int			p[2];
	int			realenpx;
	int			realenpy;
	int			sub_pos_x;
	int			sub_pos_y;
	int			pos[2];
}				t_fill;

int				len_nbr(intmax_t i);
int				read_all(t_fill *t);
int				take_place(t_fill *fl);
int				get_pos(t_fill *fl);
void			want_free(t_fill *fl, int j);
int				piece_data3(t_fill *fl);
void			piece_data2(t_fill *fl, int i, int j);
void			piece_data(t_fill *fl);
int				check_all(t_fill *fl);

#endif
