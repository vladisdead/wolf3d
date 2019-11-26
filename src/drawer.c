#include "wolf3d.h"

void    sdl_pixel(t_wolf *wolf, int x, int y, t_color_sdl color)
{
    unsigned char *pixels;
    int width;

    pixels = (unsigned char *)wolf->surf->pixels;
    width = wolf->surf->w;
    if (x < 0 && x >= wolf->surf->w)
        return ;
    if (y < 0 && y >= wolf->surf->h)
        return ;

    pixels[4 *(y * width + x) + 0] = color.b;
    pixels[4 *(y * width + x) + 1] = color.g;
    pixels[4 *(y * width + x) + 2] = color.r;
    pixels[4 *(y * width + x) + 3] = 1;

}

void    draw_wall(int x, int start, int end, t_wolf *wolf)
{
    while (++start < end)
        sdl_pixel(wolf, x, start, wolf->raycaster.color);
}

void    draw_sight(t_wolf *wolf)
{
    int x;
    int y;

    wolf->raycaster.sight = (t_color_sdl){0, 0, 0, 0};
    x = 445;
    y = 445;
    while (x <= 455)
    {
        sdl_pixel(wolf, x, 450, wolf->raycaster.sight);
        x++;
    }
    while (y <= 455)
    {
        sdl_pixel(wolf, 450, y, wolf->raycaster.sight);
        y++;
    }

}

void    update(t_wolf *wolf)
{
    SDL_Rect dstrect;

    dstrect.x = 0;
    dstrect.y = 0;
    dstrect.w = wolf->surf->w;
    dstrect.h = wolf->surf->h;

    SDL_Texture *text = SDL_CreateTextureFromSurface(wolf->renderer, wolf->surf);
    SDL_Texture *t = SDL_CreateTextureFromSurface(wolf->renderer, wolf->brick);
    SDL_RenderCopy(wolf->renderer, text, NULL, &dstrect);
    SDL_DestroyTexture(text);

    SDL_RenderPresent(wolf->renderer);
    SDL_FillRect(wolf->surf, NULL, 0x858585);
}

