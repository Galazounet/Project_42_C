/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:58:39 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 12:58:40 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void		waitforstart(t_all *a)
{
	SDL_Event ev;

	SDL_FlushEvent(SDL_MOUSEBUTTONDOWN);
	SDL_FlushEvent(SDL_KEYDOWN);
	while (42)
	{
		SDL_WaitEvent(&ev);
		if (ev.type == SDL_KEYDOWN)
		{
			if (ev.key.keysym.sym == SDLK_RETURN)
				return ;
			if (ev.key.keysym.sym == SDLK_ESCAPE)
			{
				a->i.run = END;
				return ;
			}
		}
		if (ev.type == SDL_MOUSEBUTTONDOWN &&
			(ev.button.x >= a->r.stopbutt.x + 23 &&
			ev.button.x <= a->r.stopbutt.x + a->r.stopbutt.w - 20) &&
			(ev.button.y >= a->r.stopbutt.y + 22 &&
			ev.button.y <= a->r.stopbutt.y - 16 + a->r.stopbutt.h))
			break ;
	}
}

void		mouselittlewidth(t_interface *i, t_rect r, SDL_Event ev)
{
	if ((ev.button.x >= r.pausebutt.x + 15 && ev.button.x <= r.pausebutt.x +
		r.pausebutt.w - 13) && (ev.button.y >= r.pausebutt.y + 16 &&
		ev.button.y <= r.pausebutt.y - 11 + r.pausebutt.h))
		i->run = i->run == 1 ? 0 : 1;
	if ((ev.button.x >= r.rightbutt.x + 15 && ev.button.x <= r.rightbutt.x +
		r.rightbutt.w - 13) && (ev.button.y >= r.rightbutt.y + 16 &&
		ev.button.y <= r.rightbutt.y - 11 + r.rightbutt.h))
		i->speed = i->speed == 0 ? 0 : i->speed - 1;
	if ((ev.button.x >= r.leftbutt.x + 15 && ev.button.x <= r.leftbutt.x +
		r.leftbutt.w - 13) && (ev.button.y >= r.leftbutt.y + 16 &&
		ev.button.y <= r.leftbutt.y - 11 + r.leftbutt.h))
		i->speed = i->speed == 0 ? 0 : i->speed + 1;
	if ((ev.button.x >= r.stopbutt.x + 15 && ev.button.x <= r.stopbutt.x +
		r.stopbutt.w - 13) && (ev.button.y >= r.stopbutt.y + 16 &&
		ev.button.y <= r.stopbutt.y - 11 + r.stopbutt.h))
		i->run = -1;
}

void		mousebigwidth(t_interface *i, t_rect r, SDL_Event ev)
{
	if ((ev.button.x >= r.pausebutt.x + 23 && ev.button.x <= r.pausebutt.x +
		r.pausebutt.w - 20) && (ev.button.y >= r.pausebutt.y + 22 &&
		ev.button.y <= r.pausebutt.y - 16 + r.pausebutt.h))
		i->run = i->run == 1 ? 0 : 1;
	if ((ev.button.x >= r.rightbutt.x + 23 && ev.button.x <= r.rightbutt.x +
		r.rightbutt.w - 20) && (ev.button.y >= r.rightbutt.y + 22 &&
		ev.button.y <= r.rightbutt.y - 16 + r.rightbutt.h))
		i->speed = i->speed == 0 ? 0 : i->speed - 1;
	if ((ev.button.x >= r.leftbutt.x + 23 && ev.button.x <= r.leftbutt.x +
		r.leftbutt.w - 20) && (ev.button.y >= r.leftbutt.y + 22 &&
		ev.button.y <= r.leftbutt.y - 16 + r.leftbutt.h))
		i->speed = i->speed == 0 ? 0 : i->speed + 1;
	if ((ev.button.x >= r.stopbutt.x + 23 && ev.button.x <= r.stopbutt.x +
		r.stopbutt.w - 20) && (ev.button.y >= r.stopbutt.y + 22 &&
		ev.button.y <= r.stopbutt.y - 16 + r.stopbutt.h))
		i->run = -1;
}

static void	event2(t_interface *i, SDL_Event ev)
{
	if (ev.key.keysym.sym == SDLK_RETURN)
		i->run = -1;
	else if (ev.key.keysym.sym == SDLK_SPACE)
		i->run = i->run == 1 ? 0 : 1;
	else if (ev.key.keysym.sym == SDLK_LEFT)
		i->speed = i->speed == 10 ? 10 : i->speed + 1;
	else if (ev.key.keysym.sym == SDLK_RIGHT)
		i->speed = i->speed == 0 ? 0 : i->speed - 1;
}

int			event(t_interface *i, t_map m, t_win w, t_rect r)
{
	SDL_Event	ev;

	if (SDL_PollEvent(&ev) != 1)
		return (0);
	if (ev.type == SDL_KEYDOWN)
	{
		if (ev.key.keysym.sym == SDLK_ESCAPE)
		{
			SDL_DestroyWindow(w.window);
			SDL_DestroyRenderer(w.renderer);
			SDL_Quit();
			i->run = END;
		}
		event2(i, ev);
	}
	else if (ev.type == SDL_MOUSEBUTTONDOWN)
		WIDTH == 1920 ? mousebigwidth(i, r, ev) : mouselittlewidth(i, r, ev);
	if (i->speed < 5 || i->speed > 5 || i->run == -1)
		i->color = GREEN;
	else
		i->color = GRAY;
	return (0);
}
