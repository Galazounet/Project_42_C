/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:58:00 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 12:58:02 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int		render_progressbar(t_all *a)
{
	if (WIDTH == 1920)
	{
		progress_bar((SDL_Rect){384 / 1.65, 386, 65, 350},
			getpercent(BLUE, a->m.map), (SDL_Color){71, 219, 251},
			a);
		progress_bar((SDL_Rect){384 * 1.23, 386, 65, 350},
			getpercent(RED, a->m.map), (SDL_Color){255, 0, 0},
			a);
	}
	else if (WIDTH == 1280)
	{
		progress_bar((SDL_Rect){384 / 2.51, 257, 43, 227},
			getpercent(BLUE, a->m.map), (SDL_Color){71, 219, 251},
			a);
		progress_bar((SDL_Rect){384 / 1.17, 257, 43, 227},
			getpercent(RED, a->m.map), (SDL_Color){255, 0, 0},
			a);
	}
	return (0);
}

int		update(t_all *a)
{
	SDL_RenderPresent(a->w.renderer);
	SDL_RenderClear(a->w.renderer);
	return (0);
}

int		render_map(t_all *a)
{
	int i;
	int	j;
	int x;
	int y;

	y = (HEIGHT - (a->m.rectsize * a->m.size_y)) / 2;
	x = (int)(WIDTH * 0.40);
	i = 0;
	while (i < a->m.size_y)
	{
		j = 0;
		while (j < a->m.size_x)
		{
			a->r.pf.x = x + (j * (int)a->m.rectsize) + 1;
			a->r.pf.y = y + (i * (int)a->m.rectsize) + 1;
			if (a->m.map[i][j] == 'X' || a->m.map[i][j] == 'x')
				SDL_RenderCopy(a->w.renderer, a->t.friend, NULL, &a->r.pf);
			else if (a->m.map[i][j] == 'O' || a->m.map[i][j] == 'o')
				SDL_RenderCopy(a->w.renderer, a->t.ennemy, NULL, &a->r.pf);
			++j;
		}
		++i;
	}
	return (0);
}

void	setrenders(t_interface i, t_win w, t_textures t, t_rect r)
{
	SDL_RenderCopy(w.renderer, t.background, NULL, &r.fond);
	SDL_RenderCopy(w.renderer, t.fondtransp, NULL, &r.fondtrans);
	SDL_RenderCopy(w.renderer, t.backgroundvs, NULL, &r.fondvs2);
	SDL_RenderCopy(w.renderer, t.fondtransp, NULL, &r.fondvs);
	SDL_RenderCopy(w.renderer, t.pb, NULL, &r.progressb);
	SDL_RenderCopy(w.renderer, t.pbgreen, NULL, &r.progressbgreen);
	SDL_RenderCopy(w.renderer, t.p1texture, NULL, &r.p2message_rect);
	SDL_RenderCopy(w.renderer, t.p2texture, NULL, &r.myp2message);
	if (i.run == 0)
		SDL_RenderCopy(w.renderer, t.playbutton, NULL, &r.playbutt);
	else if (i.run == 1)
		SDL_RenderCopy(w.renderer, t.pausebutton, NULL, &r.pausebutt);
	if (i.color == GREEN && i.speed < 5)
		SDL_RenderCopy(w.renderer, t.rightgbutton, NULL, &r.rightbutt);
	else
		SDL_RenderCopy(w.renderer, t.rightbutton, NULL, &r.rightbutt);
	if (i.color == GREEN && i.speed > 5)
		SDL_RenderCopy(w.renderer, t.leftgbutton, NULL, &r.leftbutt);
	else
		SDL_RenderCopy(w.renderer, t.leftbutton, NULL, &r.leftbutt);
	SDL_RenderCopy(w.renderer, t.stopbutton, NULL, &r.stopbutt);
	SDL_RenderCopy(w.renderer, t.ksign, NULL, &r.sign1);
	SDL_RenderCopy(w.renderer, t.dsign, NULL, &r.sign2);
	SDL_RenderCopy(w.renderer, t.vmessage, NULL, &r.vmessage_rect);
}

void	progress_bar(SDL_Rect r, float percent, SDL_Color color, t_all *a)
{
	int		ph;
	int		py;

	ph = (int)((float)r.h * percent);
	py = r.y + (r.h - ph);
	print_rect(a->w.window, a->w.renderer, (SDL_Rect){r.x, py, r.w, ph},
		(SDL_Color){color.r, color.g, color.b, 0});
}
