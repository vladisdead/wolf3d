/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:09:33 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/13 16:49:56 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		dda_init(t_wolf *wolf)
{
	if (wolf->ray.rdx < 0)
	{
		wolf->ray.stepx = -1;
		wolf->ray.sidedistx = (wolf->ray.rposx -
				(double)wolf->ray.mapx) * wolf->ray.ddistx;
	}
	else
	{
		wolf->ray.stepx = 1;
		wolf->ray.sidedistx = ((double)wolf->ray.mapx + 1.0 -
				wolf->ray.rposx) * wolf->ray.ddistx;
	}
	if (wolf->ray.rdy < 0)
	{
		wolf->ray.stepy = -1;
		wolf->ray.sidedisty = (wolf->ray.rposy -
				(double)wolf->ray.mapy) * wolf->ray.ddisty;
	}
	else
	{
		wolf->ray.stepy = 1;
		wolf->ray.sidedisty = ((double)wolf->ray.mapy + 1.0 -
				wolf->ray.rposy) * wolf->ray.ddisty;
	}
}

void		dda(t_wolf *wolf)
{
	wolf->ray.hit = 0;
	while (wolf->ray.hit == 0)
	{
		if (wolf->ray.sidedistx < wolf->ray.sidedisty)
		{
			wolf->ray.sidedistx += wolf->ray.ddistx;
			wolf->ray.mapx += wolf->ray.stepx;
			wolf->ray.side = 0;
		}
		else
		{
			wolf->ray.sidedisty += wolf->ray.ddisty;
			wolf->ray.mapy += wolf->ray.stepy;
			wolf->ray.side = 1;
		}
		if (wolf->map->map[wolf->ray.mapx][wolf->ray.mapy] == 1)
			wolf->ray.hit = 1;
	}
}

void		ray_utils(t_wolf *wolf)
{
	wolf->ray.rposx = wolf->ray.posx;
	wolf->ray.rposy = wolf->ray.posy;
	wolf->ray.rdx = wolf->ray.dirx + wolf->ray.planex * wolf->ray.camerax;
	wolf->ray.rdy = wolf->ray.diry + wolf->ray.planey * wolf->ray.camerax;
	wolf->ray.mapx = (int)wolf->ray.rposx;
	wolf->ray.mapy = (int)wolf->ray.rposy;
	wolf->ray.ddistx = sqrt(1 + (wolf->ray.rdy * wolf->ray.rdy)
			/ (wolf->ray.rdx * wolf->ray.rdx));
	wolf->ray.ddisty = sqrt(1 + (wolf->ray.rdx * wolf->ray.rdx)
			/ (wolf->ray.rdy * wolf->ray.rdy));
}

void		init_ray(t_wolf *wolf, int x)
{
	wolf->ray.camerax = 2 * x / (double)W_H - (double)W_W / (double)W_H;
	ray_utils(wolf);
	dda_init(wolf);
	dda(wolf);
	if (wolf->ray.side == 0)
	{
		wolf->ray.pwd = fabs((wolf->ray.mapx - wolf->ray.rposx
				+ (1.0 - wolf->ray.stepx) / 2) / wolf->ray.rdx);
		wolf->ray.drawwall = fabs((wolf->ray.mapx - 0.3 - wolf->ray.rposx
				+ (1.0 - wolf->ray.stepx) / 2) / wolf->ray.rdx);
	}
	else
	{
		wolf->ray.pwd = fabs((wolf->ray.mapy - wolf->ray.rposy +
				(1.0 - wolf->ray.stepy) / 2) / wolf->ray.rdy);
		wolf->ray.drawwall = fabs((wolf->ray.mapy - 0.3 - wolf->ray.rposy
				+ (1.0 - wolf->ray.stepy) / 2) / wolf->ray.rdy);
	}
}

void		raycast(t_wolf *wolf)
{
	wolf->ray.x = -1;
	while (++wolf->ray.x < W_W + 1)
	{
		init_ray(wolf, wolf->ray.x);
		wolf->ray.lineheight = abs((int)(W_H /
				wolf->ray.pwd));
		wolf->ray.drawstart = ((-wolf->ray.lineheight))
									/ 2 + W_H / 2;
		if (wolf->ray.drawstart < 0)
			wolf->ray.drawstart = 0;
		wolf->ray.drawend = wolf->ray.lineheight / 2 + W_H / 2;
		if (wolf->ray.drawend >= W_H)
			wolf->ray.drawend = W_H - 1;
		draw_wall(wolf->ray.x, wolf->ray.drawstart - 1,
				wolf->ray.drawend, wolf);
		draw_sight(wolf);
	}
}
