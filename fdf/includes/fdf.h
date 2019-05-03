/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:33:56 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/07 13:08:20 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define BUF 4096
# define WIDTH 800
# define HEIGHT 800
# define ABS(x) (x > 0 ? x : -x)
# define RANGE(x1, y1) (y1 < HEIGHT && x1 < WIDTH && y1 > 0 && x1 > 0)
# define RED 0xDC143C
# define WHITE 0xFFFFFF
# define CYAN 0x00FFFF
# define TUR 0x40E0D0
# define R1 0x9400D3
# define R2 0x4B0082
# define R3 0x0000FF
# define R4 0x00FF00
# define R5 0xFFFF00
# define R6 0xFF7F00
# define R7 0xFF0000

typedef struct	s_tool
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			**map;
	float		pos[2];
	float		in[2];
	int			lenx;
	int			leny;
	int			d[2];
	int			s[2];
	int			er[2];
	int			nbpix;
	int			depth;
	int			spacekey;
	int			savedepth;
	int			color[2];
	float		inc;
	int			fun;
	int			rainbow;
}				t_tool;

int				count_words(char *s, char c);
int				n_length(int n);
void			init(t_tool *t);
int				print_quadri(t_tool *t);
void			print_again(t_tool *t);
void			color_key(int key, t_tool *t);
int				funny_func(t_tool *t);
int				funny_func2(t_tool *t);
void			key_bronx(int key, t_tool *t);

#endif
