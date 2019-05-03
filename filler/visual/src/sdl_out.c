/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:58:12 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 12:58:13 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	printinterfacexl(t_win w)
{
	print_rect(w.window, w.renderer, (SDL_Rect){96, 234, 576, 2},
		(SDL_Color){0, 0, 0, 0});
	print_rect(w.window, w.renderer, (SDL_Rect){96, 234, 2, 656},
		(SDL_Color){0, 0, 0, 0});
	print_rect(w.window, w.renderer, (SDL_Rect){96, 890, 576, 2},
		(SDL_Color){0, 0, 0, 0});
	print_rect(w.window, w.renderer, (SDL_Rect){96 + 576, 234, 2, 656},
		(SDL_Color){0, 0, 0, 0});
	print_rect(w.window, w.renderer, (SDL_Rect){96, 234, 576, 2},
		(SDL_Color){0, 0, 0, 0});
}

void	printinterfacexm(t_win w)
{
	print_rect(w.window, w.renderer, (SDL_Rect){64, 155, 384, 2},
		(SDL_Color){0, 0, 0, 0});
	print_rect(w.window, w.renderer, (SDL_Rect){64, 155, 2, 429},
		(SDL_Color){0, 0, 0, 0});
	print_rect(w.window, w.renderer, (SDL_Rect){64, 584, 384, 2},
		(SDL_Color){0, 0, 0, 0});
	print_rect(w.window, w.renderer, (SDL_Rect){64 + 384, 155, 2, 429},
		(SDL_Color){0, 0, 0, 0});
	print_rect(w.window, w.renderer, (SDL_Rect){64, 155, 384, 2},
		(SDL_Color){0, 0, 0, 0});
}

int		print_rect(SDL_Window *w, SDL_Renderer *renderer, SDL_Rect r,
	SDL_Color color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &r);
	return (0);
}
