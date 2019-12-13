/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:17:36 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/13 18:20:28 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Surface		*load_texture(char *path, t_wolf *wolf)
{
	SDL_Surface		*stock;
	SDL_Surface		*surface;

	stock = SDL_LoadBMP(path);
	if (stock == NULL)
	{
		ft_putstr("Error while loading a texture file\n");
		exit(1);
	}
	surface = SDL_ConvertSurfaceFormat(stock, wolf->surf->format->format, 0);
	SDL_FreeSurface(stock);
	return (surface);
}

t_wolf			init_sdl(t_wmap *map)
{
	t_wolf sdl;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		exit(11);
	if (!(sdl.pwindow = SDL_CreateWindow("Wolf3D",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, W_W, W_H, SDL_WINDOW_SHOWN)))
		exit(22);
	if (!(sdl.renderer = SDL_CreateRenderer(sdl.pwindow, -1, 0)))
		exit(33);
	if (!(sdl.surf = SDL_CreateRGBSurface(0, W_W, W_H, 32, 0, 0, 0, 0)))
		exit(55);
	sdl.map = map;
	return (sdl);
}

void			get_texture(t_wolf *wolf)
{
	if (!(wolf->brick = load_texture("../wall.bmp", wolf)))
		exit(66);
	if (!(wolf->floor = load_texture("../floor.bmp", wolf)))
		exit(77);
	if (!(wolf->ceil = load_texture("../ceil.bmp", wolf)))
		exit(88);
}

void			init_params_wolf(t_wolf *wolf)
{
	wolf->ray.posx = wolf->map->start_y + 0.5;
	wolf->ray.posy = wolf->map->start_x + 0.5;
	wolf->ray.dirx = -1;
	wolf->ray.diry = 0;
	wolf->ray.planex = 0;
	wolf->ray.planey = 0.66;
	wolf->ray.ms = 0.1;
	wolf->ray.rs = 0.1;
	wolf->ray.w_w = W_W;
	wolf->ray.w_h = W_H;
	wolf->quit = 1;
	wolf->framenum = 0;
}

int				init_music(t_wolf *wolf)
{
	SDL_AudioSpec	wav_spec;
	Uint32			wav_length;

	SDL_LoadWAV("../resources/wolves.wav", &wav_spec,
			&wolf->wav_buffer, &wav_length);
	wolf->device_id = SDL_OpenAudioDevice(NULL, 0, &wav_spec, NULL, 0);
	SDL_QueueAudio(wolf->device_id, wolf->wav_buffer, wav_length);
	SDL_PauseAudioDevice(wolf->device_id, 0);
	return (0);
}
