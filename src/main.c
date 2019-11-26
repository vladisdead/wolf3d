/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:23:36 by cmicha            #+#    #+#             */
/*   Updated: 2019/11/26 18:36:54 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		wolf3d_destroy_graphics(t_wolf *wolf)
{
    //SDL_DestroyTexture(wolf->skybox);
    SDL_DestroyTexture(wolf->texture);
    wolf->skybox = NULL;
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
    }
}

int main(int argc, char **argv)
{
    t_wolf sdl;
    argc = 1;

    sdl = init_sdl();
    sdl.map = init_map(argv[argc]);

    init_params_wolf(&sdl);
    loop_hook(&sdl);
    wolf3d_destroy_graphics(&sdl);
    return 0;
}