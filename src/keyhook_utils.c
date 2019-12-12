/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:07:07 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/12 21:07:32 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	key_hook(SDL_Event *ev, t_wolf *wolf)
{
	if (ev->key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		wolf->quit = 1;
}

void	event(SDL_Event *ev, t_wolf *wolf)
{
	if (ev->type == SDL_KEYDOWN)
		key_hook(ev, wolf);
	if (ev->type == SDL_QUIT)
		wolf->quit = 1;
}
