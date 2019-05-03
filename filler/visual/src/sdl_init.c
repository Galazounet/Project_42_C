/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:58:27 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 12:58:28 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int		inittextures(t_textures *t, t_win w)
{
	if (!(t->pausebutton = IMG_LoadTexture(w.renderer, "../dep/pbut.png")))
		return (-1);
	if (!(t->playbutton = IMG_LoadTexture(w.renderer, "../dep/playbut.png")))
		return (-1);
	if (!(t->rightbutton = IMG_LoadTexture(w.renderer, "../dep/rbut.png")))
		return (-1);
	if (!(t->rightgbutton = IMG_LoadTexture(w.renderer, "../dep/rgbutt.png")))
		return (-1);
	if (!(t->leftbutton = IMG_LoadTexture(w.renderer, "../dep/lbut.png")))
		return (-1);
	if (!(t->leftgbutton = IMG_LoadTexture(w.renderer, "../dep/lgbutt.png")))
		return (-1);
	if (!(t->stopbutton = IMG_LoadTexture(w.renderer, "../dep/sbut.png")))
		return (-1);
	if (!(t->stoprbutton = IMG_LoadTexture(w.renderer, "../dep/sbutred.png")))
		return (-1);
	inittextures2(t, w);
	return (0);
}

int		initwindow(t_win *w)
{
	w->window = SDL_CreateWindow("filler", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	w->renderer = SDL_CreateRenderer(w->window, -1, SDL_RENDERER_ACCELERATED);
	if (w->window == NULL || w->renderer == NULL)
		return (-1);
	return (0);
}

int		initfonts(t_font *f)
{
	if (!(f->font = TTF_OpenFont("../dep/QueenInlineGrunge.ttf", 1000)))
		return (-1);
	if (!(f->sign = TTF_OpenFont("../dep/Signature of the Ancient.ttf", 1000)))
		return (-1);
	return (0);
}

int		initsurfaces(t_surface *s, t_interface i, t_font f)
{
	static SDL_Color colorwhite = {255, 255, 255};
	static SDL_Color colorgreen = {66, 237, 227};
	static SDL_Color colorblue = {71, 219, 251};
	static SDL_Color colorred = {255, 0, 0};
	static SDL_Color colorgrey = {93, 93, 93};

	if ((s->p1message = TTF_RenderText_Solid(f.font, i.p1, colorblue)) == NULL)
		return (-1);
	if ((s->p2message = TTF_RenderText_Solid(f.font, i.p2, colorred)) == NULL)
		return (-1);
	if (!(s->s1 = TTF_RenderText_Solid(f.sign, "By Ksoulard", colorwhite)))
		return (-1);
	if (!(s->s2 = TTF_RenderText_Solid(f.sign, "and Dygouasd", colorwhite)))
		return (-1);
	if (!(s->vsmess = TTF_RenderText_Solid(f.font, "Filler 1.8.6", colorwhite)))
		return (-1);
	return (0);
}

int		inittexturesfromsurfaces(t_textures *t, t_surface s, t_win w)
{
	if (!(t->p1texture = SDL_CreateTextureFromSurface(w.renderer, s.p1message)))
		return (-1);
	if (!(t->p2texture = SDL_CreateTextureFromSurface(w.renderer, s.p2message)))
		return (-1);
	if (!(t->vmessage = SDL_CreateTextureFromSurface(w.renderer, s.vsmess)))
		return (-1);
	if (!(t->ksign = SDL_CreateTextureFromSurface(w.renderer, s.s1)))
		return (-1);
	if (!(t->dsign = SDL_CreateTextureFromSurface(w.renderer, s.s2)))
		return (-1);
	return (0);
}
