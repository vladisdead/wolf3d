/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:43:55 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/17 09:54:35 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	quit(t_sdl *q)
{
	SDL_DestroyWindow(q->win);
	SDL_Quit();
}

int	main(void)
{
	t_sdl			*sdl;

	sdl = sdl_init();
	load_texture(sdl);
	sdl->point.x = 200;
	sdl->point.y = 1000;
	sdl->r.x = sdl->point.x;
	sdl->r.y = sdl->point.y;
	sdl->q = 0;
	while (sdl->q != 1)
	{
		while (SDL_PollEvent(&sdl->ev))
		{
			if (sdl->ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				sdl->q = 1;
			if (sdl->ev.type == SDL_KEYDOWN)
			{
				if (sdl->ev.key.keysym.sym == SDLK_UP)
					sdl->point.y -= 10;
			}
		}
		sdl->r.x = sdl->point.x;
		sdl->r.y = sdl->point.y;
		SDL_FillRect(sdl->screen_surface, NULL,
		SDL_MapRGB(sdl->screen_surface->format, 128, 255, 255));
		SDL_BlitSurface(sdl->anime, NULL, sdl->screen_surface, &sdl->r);
		SDL_UpdateWindowSurface(sdl->win);
	}
	quit(sdl);
	return (1);
}
