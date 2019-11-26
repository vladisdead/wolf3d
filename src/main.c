/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:23:36 by cmicha            #+#    #+#             */
/*   Updated: 2019/11/25 16:38:15 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int worldMap[mapWidth][mapHeight]=
        {
                {1,1,1,1,1,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,5,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,1,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,0,0,0,0,1},
                {1,1,1,1,1,1}
        };



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


    sdl = init_sdl();
    init_params_wolf(&sdl);
    loop_hook(&sdl);
    wolf3d_destroy_graphics(&sdl);
    return 0;
}