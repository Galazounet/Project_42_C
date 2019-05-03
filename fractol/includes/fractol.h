/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:58:51 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/21 14:38:11 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# define WIDTH 720
# define HEIGHT 480
# define ABS(x) (x > 0 ? x : -x)

# include "mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <sys/types.h>
# include <errno.h>

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*win_ptr2;
	void		*img_ptr;
	int			*img_data;
}				t_mlx;

typedef	struct	s_inter
{
	int			color;
	int			pint;
	int			inc_color;
	int			fun_mod;
	int			boing;
	int			iter;
	int			space;
	int			fractal;
	double		inc_x;
	double		inc_y;
	double		zoom;
	double		c_re_im[2];
	double		saveiter;
}				t_inter;

typedef struct	s_tool
{
	double		new_r_i[2];
	double		old_re_im[2];
	double		p_r_i[2];
	int			x;
	int			y;
	int			startx;
	int			starty;
	int			endx;
	int			endy;
	int			color;
	t_inter		*r;
	t_mlx		*m;
}				t_tool;

typedef	struct	s_v2
{
	float		x;
	float		y;
}				t_v2;

typedef	struct	s_struct
{
	t_tool		t[HEIGHT + 1];
	t_mlx		m;
	t_inter		r;
}				t_kit;

void			print_again(t_kit *k);
void			init(t_kit *t);
void			init2(t_kit *k);
void			reinit(t_tool *k);
void			*frac_julia(void *u);
void			*frac_mandel(void *u);
void			*frac_burn(void *u);
void			init(t_kit *k);
void			reinit(t_tool *t);
void			init_all(t_kit *k);
void			thread_pos(t_kit *k);
int				color(int i, t_tool *t, int iter);
pid_t			create_process(void);
int				child_process(char **argv, int argc);
int				change_frac(int key, t_kit *k);
int				all_move(int key, t_kit *k);
int				fun(t_tool *t);
int				funny_func(t_kit *k);

#endif
