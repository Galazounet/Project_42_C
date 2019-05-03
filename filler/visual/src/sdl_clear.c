/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:58:43 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 12:58:45 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	free_all(t_all *a)
{
	int		i;

	i = 0;
	deltab(a->m.map);
	if (a->i.p1)
		free(a->i.p1);
	if (a->i.p2)
		free(a->i.p2);
}

int		free_sdl(t_all *a)
{
	SDL_FreeSurface(a->s.p1message);
	SDL_FreeSurface(a->s.p2message);
	SDL_FreeSurface(a->s.s1);
	SDL_FreeSurface(a->s.s2);
	SDL_FreeSurface(a->s.vsmess);
	SDL_DestroyTexture(a->t.p1texture);
	SDL_DestroyTexture(a->t.p2texture);
	SDL_DestroyTexture(a->t.vmessage);
	SDL_DestroyTexture(a->t.ksign);
	SDL_DestroyTexture(a->t.ksign);
	return (0);
}
