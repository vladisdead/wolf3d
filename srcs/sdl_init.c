/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:18:54 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/17 09:53:20 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_sdl	*sdl_init(void)
{
	t_sdl *sdl;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		ft_putendl("Error");
		return (0);
	}
	if (!(sdl = (t_sdl*)ft_memalloc(sizeof(t_sdl))))
		return (0);
	sdl->win = SDL_CreateWindow("Wolf3D", 0, 0, 1000, 1000,
	SDL_WINDOW_SHOWN);
	sdl->screen_surface = SDL_GetWindowSurface(sdl->win);
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
