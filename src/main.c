/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:23:36 by cmicha            #+#    #+#             */
/*   Updated: 2019/12/13 18:19:42 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	update(t_wolf *wolf)
{
	wolf->texture = SDL_CreateTextureFromSurface(wolf->renderer, wolf->surf);
	SDL_RenderCopy(wolf->renderer, wolf->texture, NULL, NULL);
	SDL_DestroyTexture(wolf->texture);
	SDL_RenderPresent(wolf->renderer);
}

void	wolf3d_destroy_graphics(t_wolf *wolf)
{
	SDL_DestroyTexture(wolf->texture);
	wolf->texture = NULL;
	SDL_DestroyRenderer(wolf->renderer);
	SDL_DestroyWindow(wolf->pwindow);
	wolf->pwindow = NULL;
	wolf->renderer = NULL;
	SDL_CloseAudioDevice(wolf->device_id);
	SDL_FreeWAV(wolf->wav_buffer);
	SDL_Quit();
}

void	loop_hook(t_wolf *wolf)
{
	SDL_Event	ev;
	Uint8		*key;

	key = (Uint8 *)SDL_GetKeyboardState(NULL);
	while (wolf->quit != 0)
	{
		while (SDL_PollEvent(&ev))
			event(&ev, wolf);
		raycast(wolf);
		wolf3d_inputs(key, wolf);
		update(wolf);
		if (ev.type == SDL_QUIT)
			wolf->quit = 0;
		fps(wolf);
	}
}

int		main(int argc, char **argv)
{
	t_wolf sdl;
	t_wmap *map;

	map = run_map(argc, argv);
	sdl = init_sdl(map);
	init_params_wolf(&sdl);
	get_texture(&sdl);
	init_music(&sdl);
	loop_hook(&sdl);
	wolf3d_destroy_graphics(&sdl);
	return (0);
}
