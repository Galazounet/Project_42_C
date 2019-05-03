/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:58:06 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 12:58:07 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

SDL_Rect	fillrect(int x, int y, int width, int height)
{
	SDL_Rect new;

	new.x = x;
	new.y = y;
	new.w = width;
	new.h = height;
	return (new);
}

void		fillrectsxl(t_rect *r, int p1size, int p2size)
{
	r->progressb = fillrect(576 / 3, 300, 680, 720);
	r->progressbgreen = fillrect(576 / 4 * 3, 300, 680, 720);
	r->fondvs = fillrect(98, 236, 576, 656);
	r->fondvs2 = fillrect(98, 236, 574, 70);
	r->p2message_rect = fillrect(240 - p1size * 8.5, 251, p1size * 20, 40);
	r->myp2message = fillrect(510 - p2size * 8.5, 251, p2size * 20, 40);
	r->vmessage_rect = fillrect(295, 182, 179, 37);
	r->playbutt = fillrect(278, 774, 120, 120);
	r->pausebutt = fillrect(278, 774, 120, 120);
	r->leftbutt = fillrect(188, 774, 120, 120);
	r->rightbutt = fillrect(458, 774, 120, 120);
	r->stopbutt = fillrect(368, 774, 120, 120);
	r->sign1 = fillrect(20, 1000, 150, 35);
	r->sign2 = fillrect(20, 1030, 140, 35);
	r->winner = fillrect(WIDTH / 2 - 315, HEIGHT / 2 - 315, 630, 630);
	r->fwin = fillrect(WIDTH / 2 - 140, HEIGHT / 2 - 265, 290, 530);
}

void		fillrectsxm(t_rect *r, int p1size, int p2size)
{
	r->progressb = fillrect(384 / 3, 200, 430, 480);
	r->progressbgreen = fillrect(384 / 5 * 4, 200, 430, 480);
	r->fondvs = fillrect(66, 157, 384, 429);
	r->fondvs2 = fillrect(66, 157, 382, 45);
	r->p2message_rect = fillrect(153 - p1size * 6, 164, p1size * 15, 29);
	r->myp2message = fillrect(348 - p2size * 7, 164, p2size * 15, 29);
	r->vmessage_rect = fillrect(173, 117, 167, 33);
	r->playbutt = fillrect(190, 510, 80, 80);
	r->pausebutt = fillrect(190, 510, 80, 80);
	r->leftbutt = fillrect(130, 510, 80, 80);
	r->rightbutt = fillrect(310, 510, 80, 80);
	r->stopbutt = fillrect(250, 510, 80, 80);
	r->sign1 = fillrect(10, 670, 140, 22);
	r->sign2 = fillrect(10, 690, 140, 22);
	r->winner = fillrect(WIDTH / 2 - 315, HEIGHT / 2 - 315, 630, 630);
	r->fwin = fillrect(WIDTH / 2 - 140, HEIGHT / 2 - 265, 290, 530);
}

int			fillrects(t_rect *r, t_map m, t_interface i)
{
	int p1size;
	int p2size;

	p1size = ft_strlen(i.p1);
	p2size = ft_strlen(i.p2);
	r->fond = fillrect(0, 0, WIDTH, HEIGHT);
	r->fondtrans = fillrect((int)(WIDTH * 0.40), (HEIGHT - (m.rectsize *
		m.size_y)) / 2, (int)m.rectsize * m.size_x, (int)m.rectsize * m.size_y);
	r->pf = fillrect(0, 0, m.rectsize, m.rectsize);
	if (WIDTH == 1920)
		fillrectsxl(r, p1size, p2size);
	else if (WIDTH == 1280)
		fillrectsxm(r, p1size, p2size);
	return (0);
}
