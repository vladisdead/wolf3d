/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:18:54 by cmicha            #+#    #+#             */
/*   Updated: 2019/10/14 11:09:24 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	sdl_loop(t_sdl *sdl)
{
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
	}
}

t_sdl	sdl_init(void)
{
	t_sdl sdl;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_putendl("Error_INIT");
	if (!(sdl.win = SDL_CreateWindow("wolf3D",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WIDTH, HEIGHT,
			SDL_WINDOW_SHOWN)))
		ft_putendl("Error_WIN");
	if (!(sdl.ren = SDL_CreateRenderer(sdl.win, -1, SDL_RENDERER_SOFTWARE)))
		ft_putendl("Error!");
	return (sdl);
}

void	load_texture(t_sdl *sdl)
{
	sdl->anime = SDL_LoadBMP("anime.bmp");

	if (sdl->anime == NULL)
	{
		ft_putendl("Can't load anime :c");
		return ;
	}
}
