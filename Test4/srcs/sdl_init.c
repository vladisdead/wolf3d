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

t_sdl	sdl_init(void)
{
    t_sdl sdl;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        ft_putendl("Error");
    }
    if (!(sdl.win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED, 1000, 800,
                                     SDL_WINDOW_SHOWN)))
        ft_putendl("Error WIN");
    return (sdl);
}

