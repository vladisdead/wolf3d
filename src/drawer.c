/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:15:49 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/14 12:24:22 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		put_pixel(SDL_Surface *surf, const int x, const int y, Uint32 color)
{
	Uint32		*pixels;

	pixels = (Uint32 *)surf->pixels;
	if (x >= 0 && y >= 0 && x < surf->w && y < surf->h)
		pixels[(y * surf->w) + x] = color;
}

Uint32		read_pixel(SDL_Surface *surface, const int x, const int y)
{
	int		bpp;
	Uint8	*p;

	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	if (bpp == 2)
		return (*(Uint16 *)p);
	if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] << 0 | p[1] << 8 | p[2] << 16);
	}
	if (bpp == 4)
		return (*(Uint32 *)p);
	return (0);
}

void		draw_wall(int x, int start, int end, t_wolf *wolf)
{
	if (wolf->ray.side == 0)
		wolf->ray.wallx = wolf->ray.rposy +
				wolf->ray.pwd * wolf->ray.rdy;
	else
		wolf->ray.wallx = wolf->ray.rposx +
				wolf->ray.pwd * wolf->ray.rdx;
	wolf->ray.wallx -= floor(wolf->ray.wallx);
	wolf->texx = (int)(wolf->ray.wallx * (double)T_W);
	if (wolf->ray.side == 0 && wolf->ray.rdx > 0)
		wolf->texx = T_W - wolf->texx - 1;
	if (wolf->ray.side == 1 && wolf->ray.rdy < 0)
		wolf->texx = T_W - wolf->texx - 1;
	while (++start < end)
	{
		wolf->d = start * 256 - W_H * 128 +
				wolf->ray.lineheight * 128;
		wolf->texy = ((wolf->d * T_H) / wolf->ray.lineheight) / 256;
		put_pixel(wolf->surf, x, start,
				read_pixel(wolf->brick, wolf->texx, wolf->texy));
	}
}

void		floor_ceil(t_wolf *wolf)
{
	if (wolf->ray.side == 0 && wolf->ray.rdx > 0)
	{
		wolf->ray.fxwall = wolf->ray.mapx;
		wolf->ray.fywall = wolf->ray.wallx
				+ wolf->ray.mapy;
	}
	else if (wolf->ray.side == 0 && wolf->ray.rdx < 0)
	{
		wolf->ray.fxwall = wolf->ray.mapx + 1.0;
		wolf->ray.fywall = wolf->ray.mapy
				+ wolf->ray.wallx;
	}
	else if (wolf->ray.side == 1 && wolf->ray.rdy > 0)
	{
		wolf->ray.fxwall = wolf->ray.mapx
				+ wolf->ray.wallx;
		wolf->ray.fywall = wolf->ray.mapy;
	}
	else
	{
		wolf->ray.fxwall = wolf->ray.mapx
				+ wolf->ray.wallx;
		wolf->ray.fywall = wolf->ray.mapy + 1.0;
	}
}

void		draw_sight(t_wolf *wolf)
{
	floor_ceil(wolf);
	wolf->ray.dwall = wolf->ray.pwd;
	wolf->ray.dplayer = 0.0;
	if (wolf->ray.drawend < 0)
		wolf->ray.drawend = W_H;
	wolf->ray.y = wolf->ray.drawend - 1;
	while (++wolf->ray.y < W_H)
	{
		wolf->ray.cdist = W_H / (2.0 * wolf->ray.y - W_H);
		wolf->ray.w = (wolf->ray.cdist - wolf->ray.dplayer)
				/ (wolf->ray.dwall - wolf->ray.dplayer);
		wolf->ray.cfloorx = wolf->ray.w * wolf->ray.fxwall
				+ (1.0 - wolf->ray.w) * wolf->ray.posx;
		wolf->ray.cfloory = wolf->ray.w * wolf->ray.fywall
				+ (1.0 - wolf->ray.w) * wolf->ray.posy;
		wolf->ray.ftexx = (int)(wolf->ray.cfloorx * T_W) % T_W;
		wolf->ray.ftexy = (int)(wolf->ray.cfloory * T_H) % T_H;
		put_pixel(wolf->surf, wolf->ray.x, wolf->ray.y,
				read_pixel(wolf->floor, wolf->ray.ftexx,
						wolf->ray.ftexy));
		put_pixel(wolf->surf, wolf->ray.x, W_H - wolf->ray.y,
				read_pixel(wolf->ceil, wolf->ray.ftexx,
						wolf->ray.ftexy));
	}
}
