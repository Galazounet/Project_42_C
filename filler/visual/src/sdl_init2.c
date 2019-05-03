/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:58:22 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 12:58:23 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int			init_render(t_all *a, char **argv, char **env)
{
	int			child;
	int			pipefd[2];

	if (pipe(pipefd) == -1 || (child = fork()) == -1)
		return (-1);
	if (child == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		execve("../resources/filler_vm", argv, env);
	}
	a->in = pipefd[0];
	close(pipefd[1]);
	if (initinterface(&a->i, a->in) == -1)
		return (-1);
	if (initmap(&a->m, a->in) == -1)
		return (-1);
	if (initsurfaces(&a->s, a->i, a->f) == -1)
		return (-1);
	if (inittexturesfromsurfaces(&a->t, a->s, a->w) == -1)
		return (-1);
	WIDTH == 1920 ? printinterfacexl(a->w) : printinterfacexm(a->w);
	fillrects(&a->r, a->m, a->i);
	return (child);
}

int			initinterface(t_interface *i, int fd)
{
	if (getplayerinfos(i, fd) == -1)
		return (-1);
	i->speed = 5;
	i->run = 1;
	i->color = GRAY;
	return (0);
}

int			initmap(t_map *m, int fd)
{
	int		i;

	i = 0;
	if (getmapsize(m, fd) == -1)
		return (-1);
	m->scale = m->size_y + 1 >= m->size_x ? 0.95 :
			(float)m->size_y / (float)m->size_x;
	m->map_h = HEIGHT * m->scale;
	m->map_w = WIDTH * m->scale;
	if (m->map_w / m->size_x > m->map_h / m->size_y)
		m->rectsize = m->map_h / m->size_y;
	else
		m->rectsize = m->map_w / m->size_x;
	if ((m->map = malloc(sizeof(*m->map) * m->size_y + 1)) == NULL)
		return (-1);
	while (i < m->size_y)
	{
		if ((m->map[i] = malloc(sizeof(**m->map) * m->size_x + 1)) == NULL)
			return (-1);
		++i;
	}
	m->map[i] = NULL;
	return (0);
}

int			inittextures2(t_textures *t, t_win w)
{
	if (!(t->pb = IMG_LoadTexture(w.renderer, "../dep/p.png")))
		return (-1);
	if (!(t->pbgreen = IMG_LoadTexture(w.renderer, "../dep/pred.png")))
		return (-1);
	if (!(t->fondtransp = IMG_LoadTexture(w.renderer, "../dep/transp.png")))
		return (-1);
	if (!(t->backgroundvs = IMG_LoadTexture(w.renderer, "../dep/bvs.png")))
		return (-1);
	if (!(t->fond = IMG_LoadTexture(w.renderer, "../dep/fond.png")))
		return (-1);
	if (!(t->friend = IMG_LoadTexture(w.renderer, "../dep/Sqr2.png")))
		return (-1);
	if (!(t->ennemy = IMG_LoadTexture(w.renderer, "../dep/Sqr1.png")))
		return (-1);
	if (!(t->background = IMG_LoadTexture(w.renderer, "../dep/b.png")))
		return (-1);
	if (!(t->win = IMG_LoadTexture(w.renderer, "../dep/Win.png")))
		return (-1);
	return (0);
}

int			init_sdl(t_all *a)
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		return (-1);
	if (IMG_Init(IMG_INIT_PNG) == -1)
		return (-1);
	if (TTF_Init() == -1)
		return (-1);
	if (initwindow(&a->w) == -1)
		return (-1);
	if (inittextures(&a->t, a->w) == -1)
		return (-1);
	if (initfonts(&a->f) == -1)
		return (-1);
	return (0);
}
