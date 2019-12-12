/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:15:49 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/12 20:59:01 by cyuriko          ###   ########.fr       */
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
	if (wolf->raycaster.side == 0)
		wolf->raycaster.wallx = wolf->raycaster.rayposy +
				wolf->raycaster.perpwalldist * wolf->raycaster.raydiry;
	else
		wolf->raycaster.wallx = wolf->raycaster.rayposx +
				wolf->raycaster.perpwalldist * wolf->raycaster.raydirx;
	wolf->raycaster.wallx -= floor(wolf->raycaster.wallx);
	wolf->texx = (int)(wolf->raycaster.wallx * (double)TEXT_W);
	if (wolf->raycaster.side == 0 && wolf->raycaster.raydirx > 0)
		wolf->texx = TEXT_W - wolf->texx - 1;
	if (wolf->raycaster.side == 1 && wolf->raycaster.raydiry < 0)
		wolf->texx = TEXT_W - wolf->texx - 1;
	while (++start < end)
	{
		wolf->d = start * 256 - WINDW_H * 128 +
				wolf->raycaster.lineheight * 128;
		wolf->texy = ((wolf->d * TEXT_H) / wolf->raycaster.lineheight) / 256;
		put_pixel(wolf->surf, x, start,
				read_pixel(wolf->brick, wolf->texx, wolf->texy));
	}
}

void		draw_sight(t_wolf *wolf)
{
	if (wolf->raycaster.side == 0 && wolf->raycaster.raydirx > 0)
	{
		wolf->raycaster.floorxwall = wolf->raycaster.mapx;
		wolf->raycaster.floorywall = wolf->raycaster.wallx + wolf->raycaster.mapy;
	}
	else if (wolf->raycaster.side == 0 && wolf->raycaster.raydirx < 0)
	{
		wolf->raycaster.floorxwall = wolf->raycaster.mapx + 1.0;
		wolf->raycaster.floorywall = wolf->raycaster.mapy + wolf->raycaster.wallx;
	}
	else if (wolf->raycaster.side == 1 && wolf->raycaster.raydiry > 0)
	{
		wolf->raycaster.floorxwall = wolf->raycaster.mapx + wolf->raycaster.wallx;
		wolf->raycaster.floorywall = wolf->raycaster.mapy;
	}
	else
	{
		wolf->raycaster.floorxwall = wolf->raycaster.mapx + wolf->raycaster.wallx;
		wolf->raycaster.floorywall = wolf->raycaster.mapy + 1.0;
	}
	wolf->raycaster.distwall = wolf->raycaster.perpwalldist;
	wolf->raycaster.distplayer = 0.0;
	if (wolf->raycaster.drawend < 0)
		wolf->raycaster.drawend = WINDW_H;
	wolf->raycaster.y = wolf->raycaster.drawend - 1;
	while (++wolf->raycaster.y < WINDW_H)
	{
		wolf->raycaster.currentdist = WINDW_H / (2.0 * wolf->raycaster.y - WINDW_H);
		wolf->raycaster.weight = (wolf->raycaster.currentdist - wolf->raycaster.distplayer) / (wolf->raycaster.distwall - wolf->raycaster.distplayer);
		wolf->raycaster.currentfloorx = wolf->raycaster.weight * wolf->raycaster.floorxwall + (1.0 - wolf->raycaster.weight) * wolf->raycaster.posx;
		wolf->raycaster.currentfloory = wolf->raycaster.weight * wolf->raycaster.floorywall + (1.0 - wolf->raycaster.weight) * wolf->raycaster.posy;
		wolf->raycaster.floortexx = (int)(wolf->raycaster.currentfloorx * TEXT_W) % TEXT_W;
		wolf->raycaster.floortexy = (int)(wolf->raycaster.currentfloory * TEXT_H) % TEXT_H;
		put_pixel(wolf->surf, wolf->raycaster.x, wolf->raycaster.y, read_pixel(wolf->floor, wolf->raycaster.floortexx, wolf->raycaster.floortexy));
		put_pixel(wolf->surf, wolf->raycaster.x, WINDW_H - wolf->raycaster.y, read_pixel(wolf->ceil, wolf->raycaster.floortexx, wolf->raycaster.floortexy));
	}
}

void		update(t_wolf *wolf)
{
	SDL_Rect dstrect;

	dstrect.x = 0;
	dstrect.y = 0;
	dstrect.w = wolf->surf->w;
	dstrect.h = wolf->surf->h;
	wolf->texture = SDL_CreateTextureFromSurface(wolf->renderer, wolf->surf);
	SDL_RenderCopy(wolf->renderer, wolf->texture, NULL, &dstrect);
	SDL_DestroyTexture(wolf->texture);
	SDL_RenderPresent(wolf->renderer);
	SDL_FillRect(wolf->surf, NULL, 0x00);
}
