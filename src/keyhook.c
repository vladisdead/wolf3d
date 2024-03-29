/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:05:08 by cmicha            #+#    #+#             */
/*   Updated: 2019/12/15 17:45:33 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_key_up(t_wolf *wolf)
{
	if ((wolf->map->map[(int)(wolf->ray.posx + wolf->ray.dirx *
	wolf->ray.ms)][(int)wolf->ray.posy]) != 1)
	{
		wolf->ray.posx += (wolf->ray.dirx * 0.1);
	}
	if (wolf->map->map[(int)wolf->ray.posx][(int)(wolf->ray.posy
	+ wolf->ray.diry * wolf->ray.ms)] != 1)
	{
		wolf->ray.posy += (wolf->ray.diry * 0.1);
	}
}

void	wolf3d_key_down(t_wolf *wolf)
{
	if (wolf->map->map[(int)(wolf->ray.posx - wolf->ray.dirx *
	wolf->ray.ms)][(int)wolf->ray.posy] != 1)
		wolf->ray.posx -= wolf->ray.dirx * 0.1;
	if (wolf->map->map[(int)wolf->ray.posx][(int)(wolf->ray.posy -
	wolf->ray.diry * wolf->ray.ms)] != 1)
		wolf->ray.posy -= wolf->ray.diry * 0.1;
}

void	wolf3d_key_left(t_wolf *wolf)
{
	wolf->ray.olddirx = wolf->ray.dirx;
	wolf->ray.dirx = wolf->ray.dirx * cos(wolf->ray.rs) -
			wolf->ray.diry * sin(wolf->ray.rs);
	wolf->ray.diry = wolf->ray.olddirx * sin(wolf->ray.rs) +
			wolf->ray.diry * cos(wolf->ray.rs);
	wolf->ray.oldplanex = wolf->ray.planex;
	wolf->ray.planex = wolf->ray.planex * cos(wolf->ray.rs) -
			wolf->ray.planey * sin(wolf->ray.rs);
	wolf->ray.planey = wolf->ray.oldplanex * sin(wolf->ray.rs)
			+ wolf->ray.planey * cos(wolf->ray.rs);
}

void	wolf3d_key_right(t_wolf *wolf)
{
	wolf->ray.olddirx = wolf->ray.dirx;
	wolf->ray.dirx = wolf->ray.dirx * cos(wolf->ray.rs * -1)
			- wolf->ray.diry * sin(wolf->ray.rs * -1);
	wolf->ray.diry = wolf->ray.olddirx * sin(wolf->ray.rs *
			-1) + wolf->ray.diry * cos(wolf->ray.rs * -1);
	wolf->ray.oldplanex = wolf->ray.planex;
	wolf->ray.planex = wolf->ray.planex * cos(wolf->ray.rs *
			-1) - wolf->ray.planey * sin(wolf->ray.rs * -1);
	wolf->ray.planey = wolf->ray.oldplanex * sin(wolf->ray.rs
			* -1) + wolf->ray.planey * cos(wolf->ray.rs * -1);
}

void	wolf3d_inputs(const unsigned char *keystate, t_wolf *wolf)
{
	if (keystate[SDL_SCANCODE_ESCAPE])
		wolf->quit = 0;
	if (keystate[SDL_SCANCODE_UP])
		wolf3d_key_up(wolf);
	if (keystate[SDL_SCANCODE_DOWN])
		wolf3d_key_down(wolf);
	if (keystate[SDL_SCANCODE_RIGHT])
		wolf3d_key_right(wolf);
	if (keystate[SDL_SCANCODE_LEFT])
		wolf3d_key_left(wolf);
	raycast(wolf);
}
