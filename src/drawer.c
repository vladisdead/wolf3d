#include "wolf3d.h"


void			put_pixel(SDL_Surface *surf, const int x, const int y,
                               Uint32 color)
{
    Uint32		*pixels;

    pixels = (Uint32 *)surf->pixels;
    if (x >= 0 && y >= 0 && x < surf->w && y < surf->h)
        pixels[(y * surf->w) + x] = color;
}

Uint32 			read_pixel(SDL_Surface *surface, const int x, const int y)
{
    int		bpp;
    Uint8 *p;

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


void    sdl_pixel(t_wolf *wolf, int x, int y, uint32_t *color)
{
    unsigned char *pixels;
    int width;

    pixels = (unsigned char *)wolf->surf->pixels;
    unsigned char *tmp = (unsigned char*)&color;

    width = wolf->surf->w;
    if (x < 0 && x >= wolf->surf->w)
        return ;
    if (y < 0 && y >= wolf->surf->h)
        return ;

    pixels[4 * (y * width + x) + 0] = *color;


}

void    draw_wall(int x, int start, int end, t_wolf *wolf)
{
    if (wolf->raycaster.side == 0)
        wolf->raycaster.wallx = wolf->raycaster.rayposy + wolf->raycaster.perpwalldist * wolf->raycaster.raydiry;
    else
        wolf->raycaster.wallx = wolf->raycaster.rayposx + wolf->raycaster.perpwalldist * wolf->raycaster.raydirx;

    wolf->raycaster.wallx -= floor(wolf->raycaster.wallx);
    wolf->texx = (int)(wolf->raycaster.wallx * (double)TEXT_W);
    if (wolf->raycaster.side == 0 && wolf->raycaster.raydirx > 0)
        wolf->texx = TEXT_W - wolf->texx - 1;
    if (wolf->raycaster.side == 1 && wolf->raycaster.raydiry < 0)
        wolf->texx = TEXT_W - wolf->texx - 1;
    while (++start < end)
    {
        wolf->d = start * 256 - WINDW_H * 128 + wolf->raycaster.lineheight * 128;
        wolf->texy = ((wolf->d * TEXT_H) / wolf->raycaster.lineheight) / 256;

        put_pixel(wolf->surf, x, start,
                read_pixel(wolf->brick, wolf->texx, wolf->texy));
    }
}

void    draw_sight(t_wolf *wolf)
{


}

void    update(t_wolf *wolf)
{
    SDL_Rect dstrect;

    dstrect.x = 0;
    dstrect.y = 0;
    dstrect.w = wolf->surf->w;
    dstrect.h = wolf->surf->h;

    SDL_Texture *text = SDL_CreateTextureFromSurface(wolf->renderer, wolf->surf);

    SDL_RenderCopy(wolf->renderer, text, NULL, &dstrect);
    SDL_DestroyTexture(text);

    SDL_RenderPresent(wolf->renderer);
    SDL_FillRect(wolf->surf, NULL, 0x858585);
}

