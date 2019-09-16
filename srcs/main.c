/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:43:55 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/16 14:09:41 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	quit(t_sdl q)
{
	q.q = 1;
	SDL_DestroyWindow(q.win);
	SDL_Quit();
	return (q.q);
}

int	main(void)
{
	t_sdl			sdl;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		ft_putendl("Error");
		return (0);
	}
	sdl.q = 0;
	sdl.win = SDL_CreateWindow("Wolf3D", 0, 0, 1000,
	1000, SDL_WINDOW_FULLSCREEN);
	if (sdl.win == NULL)
	{
		ft_putendl("Error Win");
		return (0);
	}
	sdl.ren = SDL_CreateRenderer(sdl.win, -1, SDL_RENDERER_ACCELERATED
	| SDL_RENDERER_PRESENTVSYNC);
	while (quit(sdl) != 1)
	{
		while (SDL_PollEvent(&sdl.ev))
		{
			if (sdl.ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				quit(sdl);
			}
		}
	}
	return (1);
}
