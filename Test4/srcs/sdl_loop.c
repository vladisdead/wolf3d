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

#include "../includes/wolf3d.h"

void    eventintg(t_wolf *wolf, SDL_Event event)
{
    if (event.type == SDL_KEYDOWN)
        hook_keydown(wolf, event);
}

void    sdl_loop(t_wolf*wolf)
{
    SDL_Event event;

    while(wolf->sdl.q != 1)
    {
        while (SDL_PollEvent(&event))
            eventintg(wolf, event);
        if (event.type == SDL_QUIT)
            break;
    }
}
