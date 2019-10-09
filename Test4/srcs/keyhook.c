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

void    hook_keydown(t_wolf *wolf, SDL_Event event)
{
    if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
        quit(wolf);
}