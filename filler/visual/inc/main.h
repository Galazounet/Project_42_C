/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:16:13 by ksoulard          #+#    #+#             */
/*   Updated: 2018/03/02 13:37:18 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define HEIGHT 1080
# define WIDTH 1920
# define RED 0
# define BLUE 1
# define END 2
# define ABS(x) (x > 0 ? x : -x)

# include <stdlib.h>
# include <stdio.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include <string.h>
# include "../../libft/libft.h"
# include "../../libft/get_next_line.h"
# include <signal.h>
# include <curse.h>

enum				e_speed
{
	GREEN,
	GRAY,
};

typedef struct		s_interface
{
	char			*p1;
	char			*p2;
	unsigned int	speed;
	enum e_speed	color;
	int				run;
}					t_interface;

typedef struct		s_map
{
	float			scale;
	float			map_h;
	float			map_w;
	float			rectsize;
	int				size_x;
	int				size_y;
	char			**map;
}					t_map;

typedef struct		s_textures
{
	SDL_Texture		*pb;
	SDL_Texture		*pbgreen;
	SDL_Texture		*pausebutton;
	SDL_Texture		*playbutton;
	SDL_Texture		*rightbutton;
	SDL_Texture		*rightgbutton;
	SDL_Texture		*leftbutton;
	SDL_Texture		*leftgbutton;
	SDL_Texture		*stopbutton;
	SDL_Texture		*stoprbutton;
	SDL_Texture		*fond;
	SDL_Texture		*friend;
	SDL_Texture		*ennemy;
	SDL_Texture		*fondtransp;
	SDL_Texture		*background;
	SDL_Texture		*backgroundvs;
	SDL_Texture		*p1texture;
	SDL_Texture		*p2texture;
	SDL_Texture		*vmessage;
	SDL_Texture		*ksign;
	SDL_Texture		*dsign;
	SDL_Texture		*win;
}					t_textures;

typedef struct		s_rect
{
	SDL_Rect		p2message_rect;
	SDL_Rect		vmessage_rect;
	SDL_Rect		fondvs;
	SDL_Rect		fondvs2;
	SDL_Rect		fondversion;
	SDL_Rect		myp2message;
	SDL_Rect		pausebutt;
	SDL_Rect		playbutt;
	SDL_Rect		leftbutt;
	SDL_Rect		rightbutt;
	SDL_Rect		stopbutt;
	SDL_Rect		sign1;
	SDL_Rect		sign2;
	SDL_Rect		progressb;
	SDL_Rect		progressbgreen;
	SDL_Rect		fondtrans;
	SDL_Rect		pf;
	SDL_Rect		fond;
	SDL_Rect		winner;
	SDL_Rect		fwin;
}					t_rect;

typedef struct		s_font
{
	TTF_Font*		font;
	TTF_Font*		sign;
	TTF_Font*		speedvisu;
}					t_font;

typedef struct		s_surface
{
	SDL_Surface*	p1message;
	SDL_Surface*	p2message;
	SDL_Surface*	s1;
	SDL_Surface*	s2;
	SDL_Surface*	vsmess;
}					t_surface;

typedef struct		s_win
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}					t_win;

typedef struct		s_all
{
	t_interface		i;
	t_map			m;
	t_textures		t;
	t_rect			r;
	t_font			f;
	t_surface		s;
	t_win			w;
	int				in;
}					t_all;

void				waitforstart(t_all *a);
int					event(t_interface *i, t_map m, t_win w, t_rect r);
void				mousebigwidth(t_interface *i, t_rect r, SDL_Event ev);
void				mouselittlewidth(t_interface *i, t_rect r, SDL_Event ev);
void				printinterfacexl(t_win w);
void				printinterfacexm(t_win w);
int					print_rect(SDL_Window *w, SDL_Renderer *renderer,
					SDL_Rect r, SDL_Color color);
int					render_progressbar(t_all *a);
int					update(t_all *a);
int					render_map(t_all *a);
int					init_render(t_all *a, char **argv, char **env);
int					inittexturesfromsurfaces(t_textures *t, t_surface s,
					t_win w);
int					initsurfaces(t_surface *s, t_interface i, t_font f);
int					initfonts(t_font *f);
int					initwindow(t_win *w);
int					inittextures(t_textures *t, t_win w);
int					inittextures2(t_textures *t, t_win w);
int					initmap(t_map *m, int fd);
int					initinterface(t_interface *i, int fd);
int					init_render(t_all *a, char **argv, char **env);
int					fillrects(t_rect *r, t_map m, t_interface i);
void				fillrectsxm(t_rect *r, int p1size, int p2size);
void				fillrectsxl(t_rect *r, int p1size, int p2size);
SDL_Rect			fillrect(int x, int y, int width, int height);
void				setrenders(t_interface i, t_win w, t_textures t, t_rect r);
void				free_all(t_all *a);
int					free_sdl(t_all *a);
int					getplayerinfos(t_interface *i, int fd);
int					getmapsize(t_map *m, int fd);
int					lennbr(int n);
int					fillmap(char *line, char **map, int size_max);
int					getmap(t_map *m, int fd);
void				progress_bar(SDL_Rect r, float percent,
					SDL_Color color, t_all *a);
float				getpercent(int color, char **map);
void				signal_handler(int signal);
int					init_sdl(t_all *a);

#endif
