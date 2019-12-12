/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:23:36 by cmicha            #+#    #+#             */
/*   Updated: 2019/12/08 12:56:56 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		wolf3d_destroy_graphics(t_wolf *wolf)
{
    //SDL_DestroyTexture(wolf->skybox);
    SDL_DestroyTexture(wolf->texture);

    wolf->texture = NULL;
    SDL_DestroyRenderer(wolf->renderer);
    SDL_DestroyWindow(wolf->pwindow);
    wolf->pwindow = NULL;
    wolf->renderer = NULL;
}


void    loop_hook(t_wolf *wolf)
{
    SDL_Event   ev;
    Uint8 *key;

    key = (Uint8 *)SDL_GetKeyboardState(NULL);
    while (wolf->quit != 0)
    {
        while(SDL_PollEvent(&ev))
            event(&ev, wolf);
        raycast(wolf);
        wolf3d_inputs(key, wolf);
        update(wolf);
        fps(wolf);
       // wolf->framenum++;
    }
}

int main(int argc, char **argv)
{
    t_wolf sdl;

	sdl = init_sdl();
    sdl.map = run_map(argc, argv);
	////тестим мапу йоу
	int x; int y;
	y = 0;
	while (y < sdl.map->mapHeight)
	{
		x = 0;
		while (x < sdl.map->mapWidth)
		{
			printf ("%d|", sdl.map->map[y][x]);
			x++;
		}
		printf ("\n");
		y++;
	}


	////а тут уже не тестим

    init_params_wolf(&sdl);
    get_texture(&sdl);
    loop_hook(&sdl);
    wolf3d_destroy_graphics(&sdl);
    return 0;
}